/****************************************************************************
* Title                 :   Noise CLICK
* Filename              :   noise_hw.h
* Author                :   CAL
* Origin Date           :   26/07/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  26/07/16    XXXXXXXXXXX         CAL      Interface Created.
*
*****************************************************************************/
/**
 * @file noise_hw.h
 * @brief <h3> Hardware Layer </h3>
 *
 * @par
 * Low level functions for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> CLICKNAME click
 * board.
 */

/**
 * @page LIB_INFO Library Info
 * @date 26 Jul 2016
 * @author Corey Lakey
 * @copyright GNU Public License
 * @version 1.0.0 - Initial testing and verification
 */

/**
 * @page TEST_CFG Test Configurations
 *
 * ### Test configuration STM : ###
 * @par
 * -<b> MCU           </b> :      STM32F107VC
 * -<b> Dev. Board    </b> :      EasyMx Pro v7
 * -<b> Oscillator    </b> :      72 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for ARM 4.7.1
 *
 * ### Test configuration PIC32 : ###
 * @par
 * -<b> MCU           </b> :      PIC32MX795F512L
 * -<b> Dev. Board    </b> :      EasyPIC Fusion v7
 * -<b> Oscillator    </b> :      80 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for PIC 3.6.0
 *
 * ### Test configuration FT90x : ###
 * @par
 * -<b> MCU           </b> :      FT900Q
 * -<b> Dev. Board    </b> :      EasyFT90x v7
 * -<b> Oscillator    </b> :      100 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for FT90x 1.2.1
 *
 * ### Test configuration PIC : ###
 * @par
 * -<b> MCU           </b> :      PIC18F87K22
 * -<b> Dev. Board    </b> :      EasyPIC Pro v7
 * -<b> Oscillator    </b> :      16 Mhz external
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for PIC 6.6.3
 *
 * ### Test configuration dsPIC : ###
 * @par
 * -<b> MCU           </b> :      dsPIC33EJ256GP710A
 * -<b> Dev. Board    </b> :      EasyPIC Fusion v7
 * -<b> Oscillator    </b> :      8 Mhz internal
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for dsPIC 6.2.1
 *
 * ### Test configuration AVR : ###
 * @par
 * -<b> MCU           </b> :      ATMEGA32
 * -<b> Dev. Board    </b> :      EasyAVR v7
 * -<b> Oscillator    </b> :      8 Mhz external
 * -<b> Ext. Modules  </b> :      CLICKNAME Click
 * -<b> SW            </b> :      MikroC PRO for FT90x 6.1.1
 */

/**
 * @mainpage
 * <h3> General Description </h3>
 * @par
 *
 *
 * <h3> Features </h3>
 * @par
 *
 *
 */
#ifndef NIOSE_HW_H
#define NOISE_HW_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

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
 * @brief <h3> HW Layer Initialization </h3>
 *
 * @par
 * Prepares library for usage and sets needed values to default.
 *
 * @note
 * This function must be called first.
 *
 * Example :
 * @code
 *
 * @endcode
 */
void noise_init( void );

/**
 * @brief <h3> Noise Set Threshold </h3>
 *
 * @par
 *  Sets Analog value "threshold". When value from noise click exceeds
 * this "threshold" an interrupt will be triggered.
 *
 *
 * @param[in] threshold -	16 bit value for threshold ( interrupt generation )
 */
void noise_set_threshold( uint16_t threshold );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* NOISE_HW_H */
/*** End of File **************************************************************/