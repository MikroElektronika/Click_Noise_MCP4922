/****************************************************************************
* Title                 :   Noise CLICK
* Filename              :   noise_hw.h
* Author                :   Corey Lakey
* Origin Date           :   26/07/2016
* Notes                 :   Hardware layer
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  26/07/16     .1                  CAL     Interface Created.
*
*****************************************************************************/
/**
 * @file noise_hw.c
 * @brief <h3> Hardware Layer </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "noise_hw.h"
#include "noise_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void noise_init( void )
{
	noise_hal_init();
}

void noise_set_threshold( uint16_t threshold )
{
	noise_hal_write( threshold );
}
/*************** END OF FUNCTIONS *********************************************/
