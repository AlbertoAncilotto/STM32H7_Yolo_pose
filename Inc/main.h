/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ST7789_RST_Pin GPIO_PIN_2
#define ST7789_RST_GPIO_Port GPIOC
#define ST7789_DC_Pin GPIO_PIN_3
#define ST7789_DC_GPIO_Port GPIOC
#define CAMERA_PWON_Pin GPIO_PIN_0
#define CAMERA_PWON_GPIO_Port GPIOA
#define CAMERA_RST_Pin GPIO_PIN_1
#define CAMERA_RST_GPIO_Port GPIOA
#define ST7789_RST2_Pin GPIO_PIN_2
#define ST7789_RST2_GPIO_Port GPIOA
#define ST7789_DC2_Pin GPIO_PIN_2
#define ST7789_DC2_GPIO_Port GPIOH
#define ST7789_CS_Pin GPIO_PIN_3
#define ST7789_CS_GPIO_Port GPIOH
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOI
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOI
#define LED_3_Pin GPIO_PIN_2
#define LED_3_GPIO_Port GPIOI
#define LED_4_Pin GPIO_PIN_3
#define LED_4_GPIO_Port GPIOI
/* USER CODE BEGIN Private defines */
#define D2_RAM 0x30000000
#define RAW_FRAMEBUFFER D2_RAM
#define CAMERA_DUAL_BUFF RAW_FRAMEBUFFER+320*240*2
#define CAMERA_888_BUFF CAMERA_DUAL_BUFF+120*120*2 //0x3002C880
#define CAMERA_BIGENDIAN 0x38000000

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
