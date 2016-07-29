/****************************************************************************
* Title                 :   Noise HAL
* Filename              :   noise_hal.h
* Author                :   CAL
* Origin Date           :   26/07/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials       Description
*  26/07/16       1.0.0             CAL        Module Created.
*
*****************************************************************************/
/**
 * @file noise_hal.h
 * @brief <h2> HAL layer </h2>
 *
 * @par
 * HAL layer for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> Noise click
 * board.
 */
#ifndef NOISE_HAL_H_
#define NOISE_HAL_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define DUMMY_BYTE	0x00
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
        
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3> CS High </h3>
 *
 * @par
 * Used by HW layer functions to set CS PIN high ( deselect )
 */
void noise_hal_cs_high( void );

/**
 * @brief <h3> CS Low </h3>
 *
 * @par
 * Used by HW layer functions to set CS PIN low ( selecet )
 */
void noise_hal_cs_low( void );

/**
 * @brief <h3> HAL Initialization </h3>
 *
 * Hal layer initialization. Must be called before any other function.
 */
void noise_hal_init( void );

/**
 * @brief <h3> HAL Write </h3>
 *
 * @par
 * Writes data through SPI bus
 *
 * @note Function have no affect to the CS PIN state - chip select is
 * controled directly from HW layer.
 *
 * @param[in] buffer
 */
void noise_hal_write( uint16_t buffer );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* NOISE_HAL_H_ */

/*** End of File **************************************************************/