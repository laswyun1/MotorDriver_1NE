/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    sd_diskio.h
  * @brief   Header for sd_diskio.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Note: code generation based on sd_diskio_dma_template.h */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SD_DISKIO_H
#define __SD_DISKIO_H

#include "main.h"
#include "module.h"

/** @defgroup SDMMC SDMMC
 * @brief SDMMC HAL BSP module driver
 * @
 */
#ifdef HAL_SD_MODULE_ENABLED

/* USER CODE BEGIN firstSection */
/* can be used to modify / undefine following code or add new definitions */
/* USER CODE END firstSection */

/* Includes ------------------------------------------------------------------*/
#include "bsp_driver_sd.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern const Diskio_drvTypeDef  SD_Driver;


//void BSP_SD_WriteCpltCallback(void);
//void BSP_SD_ReadCpltCallback(void);

/* USER CODE BEGIN lastSection */
/* can be used to modify / undefine previous code or add new definitions */
/* USER CODE END lastSection */

#endif /* HAL_SD_MODULE_ENABLED */

#endif /* __SD_DISKIO_H */
