
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdbool.h>
#include "ov7670_driver.h"

#define CAMERA_VGA_RES_X          640
#define CAMERA_VGA_RES_Y          480
#define CAMERA_QVGA_RES_X         320
#define CAMERA_QVGA_RES_Y         240


I2C_HandleTypeDef hi2c2;
DCMI_HandleTypeDef  hDcmiHandler;
CAMERA_DrvTypeDef   *camera_drv;
static uint32_t CameraCurrentResolution;
static uint32_t CameraHwAddress;
static uint32_t GetSize(uint32_t resolution);

uint8_t rgb565to888(uint16_t color, uint8_t ch){

  if (ch==0) return (uint8_t)(((((color >> 11) & 0x1F) * 527) + 23) >> 6); //r
  else if (ch==1) return (uint8_t)(((((color >> 5) & 0x3F) * 259) + 33) >> 6); //g
  else if (ch==2) return (uint8_t)((((color & 0x1F) * 527) + 23) >> 6); //b

  return 0;
}

void Camera_toRGB888(uint16_t pSrc[120][120], uint8_t pDst[120][120][3])
{
  for (uint16_t j=0; j<120; j++){
    for (uint16_t i=0; i<120; i++){
      for (uint8_t channel=0; channel<3; channel++)
        pDst[j][i][channel] = rgb565to888(pSrc[j][i],channel);
    }
  }
}

void Camera_loadBuffer(uint16_t pSrc[240][320], uint16_t pDst[120][120])
{
  for (uint16_t j=0; j<240; j+=2){
    for (uint16_t i=40; i<320-40; i+=2){
      if (i%2==0 && j%2==0) {
        pDst[j/2][(i-40)/2] = pSrc[j][i];
      }
    }
  }
}



uint8_t CAMERA_Init(uint32_t Resolution)
{ 
  DCMI_HandleTypeDef *phdcmi;
  uint8_t status = CAMERA_ERROR;

  /* Get the DCMI handle structure */
  phdcmi = &hDcmiHandler;

  /*** Configures the DCMI to interface with the camera module ***/
  /* DCMI configuration */
  phdcmi->Init.CaptureRate      = DCMI_CR_ALL_FRAME;
  phdcmi->Init.HSPolarity       = DCMI_HSPOLARITY_LOW;
  phdcmi->Init.SynchroMode      = DCMI_SYNCHRO_HARDWARE;
  phdcmi->Init.VSPolarity       = DCMI_VSPOLARITY_HIGH;
  phdcmi->Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;
  phdcmi->Init.PCKPolarity      = DCMI_PCKPOLARITY_RISING;
  phdcmi->Instance              = DCMI;

  /* Power up camera */
  //CAMERA_PwrUp();

  /* Initialize the camera driver structure */
  camera_drv = &ov7670_drv;
  CameraHwAddress = ov7670_ADDR;

  /* DCMI Initialization */
  CAMERA_MspInit(&hDcmiHandler, NULL);
  HAL_DCMI_Init(phdcmi);

  ov7670_Init(CameraHwAddress, Resolution);
  HAL_DCMI_DisableCROP(phdcmi);
  CameraCurrentResolution = Resolution;

  return CAMERA_OK;
}


uint8_t CAMERA_DeInit(void)
{ 
  hDcmiHandler.Instance              = DCMI;
  HAL_DCMI_DeInit(&hDcmiHandler);
  CAMERA_MspDeInit(&hDcmiHandler, NULL);
  return CAMERA_OK;
}

/**
  * @brief  Starts the camera capture in continuous mode.
  * @param  buff: pointer to the camera output buffer
  * @retval None
  */
void CAMERA_ContinuousStart(uint8_t *buff)
{ 
  /* Start the camera capture */
  HAL_DCMI_Start_DMA(&hDcmiHandler, DCMI_MODE_CONTINUOUS, (uint32_t)buff, GetSize(CameraCurrentResolution));
}

/**
  * @brief  Starts the camera capture in snapshot mode.
  * @param  buff: pointer to the camera output buffer
  * @retval None
  */
void CAMERA_SnapshotStart(uint8_t *buff)
{ 
  /* Start the camera capture */
  HAL_DCMI_Start_DMA(&hDcmiHandler, DCMI_MODE_SNAPSHOT, (uint32_t)buff, GetSize(CameraCurrentResolution));
}

/**
  * @brief Suspend the CAMERA capture 
  * @retval None
  */
void CAMERA_Suspend(void) 
{
  /* Suspend the Camera Capture */
  HAL_DCMI_Suspend(&hDcmiHandler);  
}

/**
  * @brief Resume the CAMERA capture 
  * @retval None
  */
void CAMERA_Resume(void) 
{
  /* Start the Camera Capture */
  HAL_DCMI_Resume(&hDcmiHandler);
}

/**
  * @brief  Stop the CAMERA capture 
  * @retval Camera status
  */
uint8_t CAMERA_Stop(void) 
{
  uint8_t status = CAMERA_ERROR;
  if(HAL_DCMI_Stop(&hDcmiHandler) == HAL_OK)
  {
     status = CAMERA_OK;
  }
  
  /* Set Camera in Power Down */
  CAMERA_PwrDown();

  return status;
}

/**
  * @brief  CANERA power up
  * @retval None
  */
void CAMERA_PwrUp(void)
{
  GPIO_InitTypeDef gpio_init_structure;

  /* Enable GPIO clock */
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*** Configure the GPIO ***/
  /* Configure DCMI GPIO as alternate function */
  gpio_init_structure.Pin       = GPIO_PIN_13;
  gpio_init_structure.Mode      = GPIO_MODE_OUTPUT_PP;
  gpio_init_structure.Pull      = GPIO_NOPULL;
  gpio_init_structure.Speed     = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOH, &gpio_init_structure);

  /* De-assert the camera POWER_DOWN pin (active high) */
  HAL_GPIO_WritePin(GPIOH, GPIO_PIN_13, GPIO_PIN_RESET);

  HAL_Delay(3);     /* POWER_DOWN de-asserted during 3ms */
}

/**
  * @brief  CAMERA power down
  * @retval None
  */
void CAMERA_PwrDown(void)
{
  GPIO_InitTypeDef gpio_init_structure;

  /* Enable GPIO clock */
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*** Configure the GPIO ***/
  /* Configure DCMI GPIO as alternate function */
  gpio_init_structure.Pin       = GPIO_PIN_13;
  gpio_init_structure.Mode      = GPIO_MODE_OUTPUT_PP;
  gpio_init_structure.Pull      = GPIO_NOPULL;
  gpio_init_structure.Speed     = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOH, &gpio_init_structure);

  /* Assert the camera POWER_DOWN pin (active high) */
  HAL_GPIO_WritePin(GPIOH, GPIO_PIN_13, GPIO_PIN_SET);
}


/**
  * @brief  Get the capture size in pixels unit.
  * @param  resolution: the current resolution.
  * @retval capture size in pixels unit.
  */
static uint32_t GetSize(uint32_t resolution)
{ 
  uint32_t size = 0;
  
  /* Get capture size */
  switch (resolution)
  {  
  case CAMERA_R320x240:
    {
      size =  320*240/2; //2 pixels per word (capturing in rgb565)
    }
    break;
  default:
    {
      break;
    }
  }
  
  return size;
}

/**
  * @brief  Initializes the DCMI MSP.
  * @param  hdcmi: HDMI handle 
  * @param  Params
  * @retval None
  */
__weak void CAMERA_MspInit(DCMI_HandleTypeDef *hdcmi, void *Params)
{
  static DMA_HandleTypeDef hdma_handler;
  
  /*** Enable peripherals and GPIO clocks ***/
  /* Enable DCMI clock */
  __HAL_RCC_DCMI_CLK_ENABLE();

  /* Enable DMA2 clock */
  __HAL_RCC_DMA2_CLK_ENABLE();
  

  /*** Configure the DMA ***/
  /* Set the parameters to be configured */
  hdma_handler.Init.Request             = DMA_REQUEST_DCMI;
  hdma_handler.Init.Direction           = DMA_PERIPH_TO_MEMORY;
  hdma_handler.Init.PeriphInc           = DMA_PINC_DISABLE;
  hdma_handler.Init.MemInc              = DMA_MINC_ENABLE;
  hdma_handler.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
  hdma_handler.Init.MemDataAlignment    = DMA_MDATAALIGN_WORD;
  hdma_handler.Init.Mode                = DMA_CIRCULAR;
  hdma_handler.Init.Priority            = DMA_PRIORITY_HIGH;
  hdma_handler.Init.FIFOMode            = DMA_FIFOMODE_ENABLE;
  hdma_handler.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
  hdma_handler.Init.MemBurst            = DMA_MBURST_SINGLE;
  hdma_handler.Init.PeriphBurst         = DMA_PBURST_SINGLE;
  hdma_handler.Instance                 = DMA2_Stream3;

  /* Associate the initialized DMA handle to the DCMI handle */
  __HAL_LINKDMA(hdcmi, DMA_Handle, hdma_handler);

  /*** Configure the NVIC for DCMI and DMA ***/
  /* NVIC configuration for DCMI transfer complete interrupt */
  HAL_NVIC_SetPriority(DCMI_IRQn, 0x0F, 0);
  HAL_NVIC_EnableIRQ(DCMI_IRQn);

  /* NVIC configuration for DMA2D transfer complete interrupt */
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 0x0F, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);

  /* Configure the DMA stream */
  (void)HAL_DMA_Init(hdcmi->DMA_Handle);
}

/**
  * @brief  DeInitializes the DCMI MSP.
  * @param  hdcmi: HDMI handle 
  * @param  Params
  * @retval None
  */
__weak void CAMERA_MspDeInit(DCMI_HandleTypeDef *hdcmi, void *Params)
{
  /* Disable NVIC  for DCMI transfer complete interrupt */
  HAL_NVIC_DisableIRQ(DCMI_IRQn);  
  
  /* Disable NVIC for DMA2 transfer complete interrupt */
  HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);
  
  /* Configure the DMA stream */
  HAL_DMA_DeInit(hdcmi->DMA_Handle);  

  /* Disable DCMI clock */
  __HAL_RCC_DCMI_CLK_DISABLE();

  /* GPIO pins clock and DMA clock can be shut down in the application 
     by surcharging this __weak function */ 
}

/**
  * @brief  Line event callback
  * @param  hdcmi: pointer to the DCMI handle  
  * @retval None
  */
void HAL_DCMI_LineEventCallback(DCMI_HandleTypeDef *hdcmi)
{        
  CAMERA_LineEventCallback();
}

/**
  * @brief  Line Event callback.
  * @retval None
  */
__weak void CAMERA_LineEventCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_DCMI_LineEventCallback could be implemented in the user file
   */
}

/**
  * @brief  VSYNC event callback
  * @param  hdcmi: pointer to the DCMI handle  
  * @retval None
  */
void HAL_DCMI_VsyncEventCallback(DCMI_HandleTypeDef *hdcmi)
{        
  CAMERA_VsyncEventCallback();
}

/**
  * @brief  VSYNC Event callback.
  * @retval None
  */
__weak void CAMERA_VsyncEventCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_DCMI_VsyncEventCallback could be implemented in the user file
   */
}

/**
  * @brief  Frame event callback
  * @param  hdcmi: pointer to the DCMI handle  
  * @retval None
  */
void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
{        
  CAMERA_FrameEventCallback();
  HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
  Camera_loadBuffer(RAW_FRAMEBUFFER, CAMERA_DUAL_BUFF);
  Camera_toRGB888(CAMERA_DUAL_BUFF, CAMERA_888_BUFF);
}

/**
  * @brief  Frame Event callback.
  * @retval None
  */
__weak void CAMERA_FrameEventCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_DCMI_FrameEventCallback could be implemented in the user file
   */
}

/**
  * @brief  Error callback
  * @param  hdcmi: pointer to the DCMI handle  
  * @retval None
  */
void HAL_DCMI_ErrorCallback(DCMI_HandleTypeDef *hdcmi)
{        
  CAMERA_ErrorCallback();
}

/**
  * @brief  Error callback.
  * @retval None
  */
__weak void CAMERA_ErrorCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_DCMI_ErrorCallback could be implemented in the user file
   */
}




CAMERA_DrvTypeDef   ov7670_drv = 
{
  ov7670_Init,
  ov7670_ReadID,  
  1
};

/* Initialization sequence for QVGA resolution (320x240) - I'm sorry, it's ugly, half is stolen from a random git repo and the other half derived from the datasheet registers */
const unsigned char ov7670_QVGA[][2]=
{

    // Image format
		{ 0x12, 0x14 },		// 0x14 = QVGA size, RGB mode; 0x11 = QVGA, raw bayer
		{ 0xc, 0x8 }, //
		{ 0x11, 0b1000000 }, //

		{ 0xb0, 0x84 },		//
    { 0x40, 0x10 },

		// Hardware window
		{ 0x32, 0x80 },		//HREF
		{ 0x17, 0x17 },		//HSTART
		{ 0x18, 0x05 },		//HSTOP
		{ 0x03, 0x0a },		//VREF
		{ 0x19, 0x02 },		//VSTART
		{ 0x1a, 0x7a },		//VSTOP

    // FPS and clock speed setup
    { 0x11, 0x80 },
    { 0x6b, 0x0a },
    { 0x2a, 0x00 },
    { 0x2b, 0x00 },
    { 0x92, 0x66 },
    { 0x93, 0x00 },
    { 0x3b, 0x0a },

    //14.3 fps, 12Mhz pclk  -> you need a decently short and well shielded pixclk / MCO
    //{ 0x11, 0x00 },
    //{ 0x6b, 0x0a },
    //{ 0x2a, 0x00 },
    //{ 0x2b, 0x00 },
    //{ 0x92, 0x1a },
    //{ 0x93, 0x00 },
    //{ 0x3b, 0x0a },

    { 0x70, 0x3a },		//X_SCALING
		{ 0x71, 0x35 },		//Y_SCALING
		{ 0x72, 0x11 },		//DCW_SCALING
		{ 0x73, 0xf0 },		//PCLK_DIV_SCALING
		{ 0xa2, 0x02 },		//PCLK_DELAY_SCALING

		// Matrix coefficients
		{ 0x4f, 0x80 }, //
		{ 0x50, 0x80 }, //
		{ 0x51, 0x00 }, //
		{ 0x52, 0x22 }, //
		{ 0x53, 0x5e }, //
		{ 0x54, 0x80 }, //
		{ 0x58, 0x9e },

		// Gamma curve values
		{ 0x7a, 0x20 }, //
		{ 0x7b, 0x10 }, //
		{ 0x7c, 0x1e }, //
		{ 0x7d, 0x35 }, //
		{ 0x7e, 0x5a }, //
		{ 0x7f, 0x69 }, //
		{ 0x80, 0x76 }, //
		{ 0x81, 0x80 }, //
		{ 0x82, 0x88 }, //
		{ 0x83, 0x8f }, //
		{ 0x84, 0x96 }, //
		{ 0x85, 0xa3 }, //
		{ 0x86, 0xaf }, //
		{ 0x87, 0xc4 }, //
		{ 0x88, 0xd7 }, //
		{ 0x89, 0xe8 },

		// AGC and AEC parameters
		{ 0xa5, 0x05 }, //
		{ 0xab, 0x07 }, //
		{ 0x24, 0x95 }, //
		{ 0x25, 0x33 }, //
		{ 0x26, 0xe3 }, //
		{ 0x9f, 0x78 }, //
		{ 0xa0, 0x68 }, //
		{ 0xa1, 0x03 }, //
		{ 0xa6, 0xd8 }, //
		{ 0xa7, 0xd8 }, //
		{ 0xa8, 0xf0 }, //
		{ 0xa9, 0x90 }, //
		{ 0xaa, 0x94 }, //
		{ 0x10, 0x00 },

		// AWB parameters
		{ 0x43, 0x0a }, //
		{ 0x44, 0xf0 }, //
		{ 0x45, 0x34 }, //
		{ 0x46, 0x58 }, //
		{ 0x47, 0x28 }, //
		{ 0x48, 0x3a }, //
		{ 0x59, 0x88 }, //
		{ 0x5a, 0x88 }, //
		{ 0x5b, 0x44 }, //
		{ 0x5c, 0x67 }, //
		{ 0x5d, 0x49 }, //
		{ 0x5e, 0x0e }, //
		{ 0x6c, 0x0a }, //
		{ 0x6d, 0x55 }, //
		{ 0x6e, 0x11 }, //
		{ 0x6f, 0x9f }, //
		{ 0x6a, 0x40 }, //
		{ 0x01, 0x40 }, //
		{ 0x02, 0x60 }, //
		{ 0x13, 0xe7 },

		// Additional parameters
		{ 0x34, 0x11 }, //
		{ 0x3f, 0x00 }, //
		{ 0x75, 0x05 }, //
		{ 0x76, 0xe1 }, //
		{ 0x4c, 0x00 }, //
		{ 0x77, 0x01 }, //
		{ 0xb8, 0x0a }, //
		{ 0x41, 0x18 }, //
		{ 0x3b, 0x12 }, //
		{ 0xa4, 0x88 }, //
		{ 0x96, 0x00 }, //
		{ 0x97, 0x30 }, //
		{ 0x98, 0x20 }, //
		{ 0x99, 0x30 }, //
		{ 0x9a, 0x84 }, //
		{ 0x9b, 0x29 }, //
		{ 0x9c, 0x03 }, //
		{ 0x9d, 0x4c }, //
		{ 0x9e, 0x3f }, //
		{ 0x78, 0x04 }, //
		{ 0x0e, 0x61 }, //
		{ 0x0f, 0x4b }, //
		{ 0x16, 0x02 }, //
		{ 0x1e, 0x00 }, //
		{ 0x21, 0x02 }, //
		{ 0x22, 0x91 }, //
		{ 0x29, 0x07 }, //
		{ 0x33, 0x0b }, //
		{ 0x35, 0x0b }, //
		{ 0x37, 0x1d }, //
		{ 0x38, 0x71 }, //
		{ 0x39, 0x2a }, //
		{ 0x3c, 0x78 }, //
		{ 0x4d, 0x40 }, //
		{ 0x4e, 0x20 }, //
		{ 0x69, 0x00 }, //
		{ 0x6b, 0x3a }, //
		{ 0x74, 0x10 }, //
		{ 0x8d, 0x4f }, //
		{ 0x8e, 0x00 }, //
		{ 0x8f, 0x00 }, //
		{ 0x90, 0x00 }, //
		{ 0x91, 0x00 }, //
		{ 0x96, 0x00 }, //
		{ 0x9a, 0x00 }, //
		{ 0xb1, 0x0c }, //
		{ 0xb2, 0x0e }, //
		{ 0xb3, 0x82 }, //
		{ 0x4b, 0x01 },

    //contrast
    //{ 0x56, 0x50 },
    //brightness
    //{ 0x55, 0x98 },
};



/**
  * @brief  Initializes the ov7670 CAMERA component.
  * @param  DeviceAddr: Device address on communication Bus.
  * @param  resolution: Camera resolution
  * @retval None
  */
void ov7670_Init(uint16_t DeviceAddr, uint32_t resolution)
{
  uint32_t index;

  CAMERA_IO_Init();
  /* Prepare the camera to be configured by resetting all its registers */
  CAMERA_IO_Write(DeviceAddr, ov7670_SENSOR_COM7, 0x80);
  CAMERA_Delay(500);
  
  /* Initialize ov7670 */
  switch (resolution)
  {   
  case CAMERA_R320x240:
    {
      for(index=0; index<(sizeof(ov7670_QVGA)/2); index++)
      {
        CAMERA_IO_Write(DeviceAddr, ov7670_QVGA[index][0], ov7670_QVGA[index][1]);
        CAMERA_Delay(10);
      } 
      break;
    }
  default:
    {
      break;
    }
  }
}


/**
  * @brief  Read the ov7670 Camera identity.
  * @param  DeviceAddr: Device address on communication Bus.
  * @retval the ov7670 ID
  */
uint16_t ov7670_ReadID(uint16_t DeviceAddr)
{
  /* Initialize I2C */
  CAMERA_IO_Init();
  
  /* Get the camera ID */
  return (CAMERA_IO_Read(0x43, ov7670_SENSOR_PIDH));
}


void CAMERA_IO_Init(void){
  CAMERA_I2C2_Init();
}

void CAMERA_IO_Write(uint8_t addr, uint8_t reg, uint8_t value){
  HAL_StatusTypeDef ret;
  ret=HAL_I2C_Mem_Write(&hi2c2, addr, reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&value, 1, 1000);
  if (ret!=HAL_OK){
    LCD_Print("Camera i2c write err");
    Error_Handler();
  }
}

uint8_t CAMERA_IO_Read(uint8_t addr, uint8_t reg){
  uint8_t read_value = 0;
  HAL_StatusTypeDef ret;
  ret=HAL_I2C_Mem_Read(&hi2c2, addr, reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&read_value, 1, 1000);
  if (ret!=HAL_OK){
    LCD_Print("Camera i2c read err");
    //Error_Handler();
  }
  return read_value;
}

void CAMERA_Delay(uint32_t delay){
  HAL_Delay(delay);
};

void CAMERA_I2C2_Init(void)
{
  HAL_I2C_DeInit(&hi2c2);
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = ((uint32_t)0x40912732)  ;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
}


