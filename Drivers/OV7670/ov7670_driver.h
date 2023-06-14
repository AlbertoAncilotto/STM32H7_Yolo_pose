
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef OV7670_DRIVER_H
#define OV7670_DRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Include Camera component Driver */
#include "main.h"
#include "camera.h"

#define  ov7670_ID    0x76
#define  ov7670_ADDR  ((uint16_t)0x42)


/* ov7670 Registers definition */
#define ov7670_SENSOR_PIDH              0x0A
#define ov7670_SENSOR_PIDL              0x0B
#define ov7670_SENSOR_COM7              0x12
#define ov7670_SENSOR_TSLB              0x3A
#define ov7670_SENSOR_MTX1              0x4F
#define ov7670_SENSOR_MTX2              0x50
#define ov7670_SENSOR_MTX3              0x51
#define ov7670_SENSOR_MTX4              0x52
#define ov7670_SENSOR_MTX5              0x53
#define ov7670_SENSOR_MTX6              0x54
#define ov7670_SENSOR_BRTN              0x55
#define ov7670_SENSOR_CNST1             0x56
#define ov7670_SENSOR_CNST2             0x57


typedef enum 
{
  CAMERA_OK            = 0x00,
  CAMERA_ERROR         = 0x01,
  CAMERA_TIMEOUT       = 0x02,
  CAMERA_NOT_DETECTED  = 0x03,
  CAMERA_NOT_SUPPORTED = 0x04

} Camera_StatusTypeDef;

#define RESOLUTION_R320x240      CAMERA_R320x240      /* QVGA Resolution      */
#define RESOLUTION_R640x480      CAMERA_R640x480      /* VGA Resolution       */  

#define CAMERA_IRQHandler      CAMERA_IRQHandler
#define DCMI_IRQHandler        CAMERA_IRQHandler
#define CAMERA_DMA_IRQHandler  CAMERA_DMA_IRQHandler  


uint8_t CAMERA_Init(uint32_t Resolution);  
uint8_t CAMERA_DeInit(void);
void    CAMERA_ContinuousStart(uint8_t *buff);
void    CAMERA_SnapshotStart(uint8_t *buff);
void    CAMERA_Suspend(void);
void    CAMERA_Resume(void);
uint8_t CAMERA_Stop(void); 
void    CAMERA_PwrUp(void);
void    CAMERA_PwrDown(void);
void    CAMERA_LineEventCallback(void);
void    CAMERA_VsyncEventCallback(void);
void    CAMERA_FrameEventCallback(void);
void    CAMERA_ErrorCallback(void);

/* Camera features functions prototype */
void    CAMERA_ContrastBrightnessConfig(uint32_t contrast_level, uint32_t brightness_level);
void    CAMERA_BlackWhiteConfig(uint32_t Mode);
void    CAMERA_ColorEffectConfig(uint32_t Effect);
   
/* These functions can be modified in case the current settings (e.g. DMA stream)
   need to be changed for specific application needs */
void CAMERA_MspInit(DCMI_HandleTypeDef *hdcmi, void *Params);
void CAMERA_MspDeInit(DCMI_HandleTypeDef *hdcmi, void *Params);

/* Camera-specific implementation*/
void     ov7670_Init(uint16_t DeviceAddr, uint32_t resolution);
void     ov7670_Config(uint16_t DeviceAddr, uint32_t feature, uint32_t value, uint32_t BR_value);
uint16_t ov7670_ReadID(uint16_t DeviceAddr);

void     CAMERA_I2C2_Init(void);
void     CAMERA_IO_Init(void);
void     CAMERA_IO_Write(uint8_t addr, uint8_t reg, uint8_t value);
uint8_t  CAMERA_IO_Read(uint8_t addr, uint8_t reg);
void     CAMERA_Delay(uint32_t delay);

/* CAMERA driver structure */
extern CAMERA_DrvTypeDef   ov7670_drv;

#ifdef __cplusplus
}
#endif

#endif /* OV7670_DRIVER_H */

