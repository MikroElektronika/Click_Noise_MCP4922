/*******************************************************************************
* Title                 :   Noise HAL
* Filename              :   noise_hal.c
* Author                :   CAL
* Origin Date           :   26/07/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials       Description
*  26/07/16       1.0.0             CAL        Module Created.
*
*******************************************************************************/
/**
 * @file noise_hal.c
 * @brief <h2> HAL layer </h2>
 */
/******************************************************************************
* Includes
*******************************************************************************/
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
#if defined( __MIKROC_PRO_FOR_ARM__ )       || \
    defined( __MIKROC_PRO_FOR_DSPIC__ )
static void         ( *write_spi_p )            ( unsigned int data_out );
static unsigned int ( *read_spi_p )             ( unsigned int buffer );

#elif defined( __MIKROC_PRO_FOR_AVR__ )     || \
      defined( __MIKROC_PRO_FOR_PIC__ )     || \
      defined( __MIKROC_PRO_FOR_8051__ )
static void         ( *write_spi_p )            ( unsigned char data_out );
static unsigned char( *read_spi_p )             ( unsigned char dummy );

#elif defined( __MIKROC_PRO_FOR_PIC32__ )
static void         ( *write_spi_p )            ( unsigned long data_out );
static unsigned long( *read_spi_p )             ( unsigned long buffer );

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
static void         ( *write_spi_p )            ( unsigned char data_out );
static unsigned char( *read_spi_p )             ( unsigned char dummy );
static void         ( *write_bytes_spi_p )      ( unsigned char *data_out,
                                                  unsigned int count );
static void         ( *read_bytes_spi_p )       ( unsigned char *buffer,
                                                  unsigned int count );
#endif

#if defined( __MIKROC_PRO_FOR_ARM__ )     || \
    defined( __MIKROC_PRO_FOR_AVR__ )     || \
    defined( __MIKROC_PRO_FOR_PIC__ )     || \
    defined( __MIKROC_PRO_FOR_PIC32__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ )   || \
    defined( __MIKROC_PRO_FOR_8051__ )    || \
    defined( __MIKROC_PRO_FOR_FT90x__ )
extern sfr sbit NOISE_CS;
#endif

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void noise_hal_cs_high()
{ 
    NOISE_CS = 1;
}

void noise_hal_cs_low()
{
    NOISE_CS = 0;
}

void noise_hal_init()
{
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )
    write_spi_p             = SPI_Wr_Ptr;
    read_spi_p              = SPI_Rd_Ptr;

#elif defined( __MIKROC_PRO_FOR_PIC__ )
    write_spi_p             = SPI1_Write;
    read_spi_p              = SPI1_Read;

#elif defined( __MIKROC_PRO_FOR_FT90x__ )
    write_spi_p             = SPIM_Wr_Ptr;
    read_spi_p              = SPIM_Rd_Ptr;
    write_bytes_spi_p       = SPIM_WrBytes_Ptr;
    read_bytes_spi_p        = SPIM_RdBytes_Ptr;
#endif
    noise_hal_cs_high();
}

void noise_hal_write( uint16_t buffer )
{
    uint8_t temp = 0;

    buffer |= 0x7000;           /**< buffered enabled, buffered data, normal output gain */
#if defined( __MIKROC_PRO_FOR_FT90x__ ) || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_PIC__ )   
    
    temp = ( buffer >> 8 );
    noise_hal_cs_low();
    write_spi_p( temp );
    temp = buffer & 0x00FF;
    write_spi_p( temp );
    noise_hal_cs_high();
#else
    noise_hal_cs_low();
    write_spi_p( buffer );
    noise_hal_cs_high();
#endif
}

/*************** END OF FUNCTIONS ***************************************************************************/