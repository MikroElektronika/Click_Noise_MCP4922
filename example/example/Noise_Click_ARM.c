#include <stdint.h>
#include "noise_hw.h"

sbit NOISE_CS 	at GPIOD_ODR.B13;
sbit NOISE_INT 	at GPIOD_IDR.B10;

void system_setup( void );

void main() 
{
    //Local Decalartions
    uint8_t buffer[20] = { 0 };
    uint32_t value = 0;
    uint16_t threshold = 600;
    
    //Setup
    system_setup();
    
    noise_set_threshold( threshold );
    
    //Loop
    while(1)
    {
        value = ADC1_Read( 4 );
        LongToStr( value, buffer );
        UART1_Write_Text( buffer );
        UART1_Write_Text( "\r\n" );
        Delay_ms(20);
        if( NOISE_INT == 0 );  // Do nothing
        else
            UART1_Write_Text( "Interrupt!!!!!!\r\n" );
    }

}

void system_setup( void )
{
    //GPIOs
    GPIO_Digital_Output( &GPIOD_BASE, _GPIO_PINMASK_13 );
    GPIO_Digital_Input( &GPIOD_BASE, _GPIO_PINMASK_10 );
    
    //UART
    UART1_Init( 9600 );
    Delay_ms(100);
    UART1_Write_Text( "UART Initialized\r\n" );
    
    //SPI
    SPI3_Init_Advanced( _SPI_FPCLK_DIV4, _SPI_MASTER | _SPI_16_BIT |
		    _SPI_CLK_IDLE_LOW | _SPI_FIRST_CLK_EDGE_TRANSITION |
		    _SPI_MSB_FIRST | _SPI_SS_DISABLE | _SPI_SSM_ENABLE |
                    _SPI_SSI_1, &_GPIO_MODULE_SPI3_PC10_11_12 );
    Delay_ms(200);
    UART1_Write_Text( "SPI Initialized\r\n" );

    //ADC
    ADC1_Init();
    Delay_ms(200);
    UART1_Write_Text( "ADC Initialized\r\n" );

    //Noise Click
    noise_init();
    UART1_Write_Text( "Noise Click Initialized\r\n" );

}