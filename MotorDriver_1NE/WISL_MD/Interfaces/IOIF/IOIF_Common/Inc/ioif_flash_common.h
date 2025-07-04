

#ifndef INTERFACES_IOIF_IOIF_COMMON_INC_IOIF_FLASH_COMMON_H_
#define INTERFACES_IOIF_IOIF_COMMON_INC_IOIF_FLASH_COMMON_H_

#include "bsp_flash.h"


/** @defgroup FLASH FLASH
  * @brief FLASH BSP module driver
  * @{
  */
#ifdef BSP_FLASH_MODULE_ENABLED

#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

/**
 *-----------------------------------------------------------
 *              MACROS AND PREPROCESSOR DIRECTIVES
 *-----------------------------------------------------------
 * @brief Directives and macros for readability and efficiency.
 */

#define IOIF_NUM_SECTORS        1

#define IOIF_ERASE_ALL          1
#define IOIF_ERASE_ONE_SECTOR   0

#define IOIF_FLASH_ALIGN_SIZE_4B	4

#define IOIF_FLASH_READ_ADDR_SIZE_4B    4
#define IOIF_FLASH_READ_ADDR_SIZE_32B   32

#define IOIF_FLASH_READ_SIZE_4B     4
#define IOIF_FLASH_READ_SIZE_32B    32

#define IOIF_FLASH_WRITE_ADDR_SIZE  32

#define IOIF_FLASH_WRITE_SIZE_4B    4
#define IOIF_FLASH_WRITE_SIZE_32B   32

#define IOIF_FLASH_BUFFER_SIZE      256

#define IOIF_ALIGN_TO_4BYTES(length)   ((length + 3) & ~0x03)

/**
 * @defgroup FLASH_SECTOR_ADDRESSES Flash Sector Base Addresses
 * @{
 */
#define IOIF_FLASH_SECTOR_0_BANK1_ADDR     ((uint32_t)0x08000000) /* Base @ of Sector 0, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_1_BANK1_ADDR     ((uint32_t)0x08020000) /* Base @ of Sector 1, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_2_BANK1_ADDR     ((uint32_t)0x08040000) /* Base @ of Sector 2, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_3_BANK1_ADDR     ((uint32_t)0x08060000) /* Base @ of Sector 3, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_4_BANK1_ADDR     ((uint32_t)0x08080000) /* Base @ of Sector 4, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_5_BANK1_ADDR     ((uint32_t)0x080A0000) /* Base @ of Sector 5, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_6_BANK1_ADDR     ((uint32_t)0x080C0000) /* Base @ of Sector 6, Bank1, 128 Kbyte */
#define IOIF_FLASH_SECTOR_7_BANK1_ADDR     ((uint32_t)0x080E0000) /* Base @ of Sector 7, Bank1, 128 Kbyte */

#define IOIF_FLASH_SECTOR_0_BANK2_ADDR     ((uint32_t)0x08100000) /* Base @ of Sector 0, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_1_BANK2_ADDR     ((uint32_t)0x08120000) /* Base @ of Sector 1, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_2_BANK2_ADDR     ((uint32_t)0x08140000) /* Base @ of Sector 2, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_3_BANK2_ADDR     ((uint32_t)0x08160000) /* Base @ of Sector 3, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_4_BANK2_ADDR     ((uint32_t)0x08180000) /* Base @ of Sector 4, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_5_BANK2_ADDR     ((uint32_t)0x081A0000) /* Base @ of Sector 5, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_6_BANK2_ADDR     ((uint32_t)0x081C0000) /* Base @ of Sector 6, Bank2, 128 Kbyte */
#define IOIF_FLASH_SECTOR_7_BANK2_ADDR     ((uint32_t)0x081E0000) /* Base @ of Sector 7, Bank2, 128 Kbyte */

/*!< Start address for the user-defined section to be erased */
#define IOIF_FLASH_START_USER_ADDR  IOIF_FLASH_SECTOR_0_BANK2_ADDR /*!< Start address of user Flash area */

/*!< End address for the user-defined section to be erased.
     Calculated as the start address of the last sector minus one to cover the full sector */
#define IOIF_FLASH_END_USER_ADDR    (IOIF_FLASH_SECTOR_1_BANK2_ADDR - 1)

/*!< Start address of the Flash memory */
#define IOIF_FLASH_START_ADDR       ((uint32_t)0x08000000)

/*!< End address of the Flash memory */
#define IOIF_FLASH_END_ADDR         ((uint32_t)0x081FFFFF)

/*!< Define the size of user application in Flash memory */
#define IOIF_USER_FLASH_SIZE        (IOIF_FLASH_END_ADDR - IOIF_FLASH_START_USER_ADDR + 1)

/*!< Bitmap representing sectors of the user flash area that may be write-protected.
     Currently, protection is applied to sectors 0-7 */
#define IOIF_FLASH_SECTOR_TO_BE_PROTECTED (OB_WRP_SECTOR_0 | OB_WRP_SECTOR_1 | OB_WRP_SECTOR_2 | OB_WRP_SECTOR_3 |\
                                           OB_WRP_SECTOR_4 | OB_WRP_SECTOR_5 | OB_WRP_SECTOR_6 | OB_WRP_SECTOR_7)


/**
 *------------------------------------------------------------
 *                     TYPE DECLARATIONS
 *------------------------------------------------------------
 * @brief Custom data types and structures for the module.
 */


typedef enum _IOIF_FLASHState_t {
  IOIF_FLASH_STATUS_OK = 0,
  IOIF_FLASH_STATUS_ERASEKO,
  IOIF_FLASH_NOT_ALIGNED_4B,
  IOIF_FLASH_WRITING_ERROR,
  IOIF_FLASH_BUFFER_OVERFLOW,
} IOIF_FLASHState_t;


/**
 *------------------------------------------------------------
 *                      GLOBAL VARIABLES
 *------------------------------------------------------------
 * @brief Extern declarations for global variables.
 */




/**
 *------------------------------------------------------------
 *                     FUNCTION PROTOTYPES
 *------------------------------------------------------------
 * @brief Function prototypes declaration for this module.
 */

void IOIF_InitFlash(void);

IOIF_FLASHState_t IOIF_EraseFlash(uint32_t startSector, bool eraseAll);
IOIF_FLASHState_t IOIF_WriteFlash(uint32_t flashAddr, void* pData);
IOIF_FLASHState_t IOIF_ReadFlash(uint32_t flashAddr, void* pData, uint32_t length);


#endif /* BSP_FLASH_MODULE_ENABLED */

#endif /* INTERFACES_IOIF_IOIF_COMMON_INC_IOIF_FLASH_COMMON_H_ */
