![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

![Noise Click](http://cdn.mikroe.com/img/click/noise/noise-click.png)

---
[Product Page](http://www.mikroe.com/click/noise)

[Manual Page](http://docs.mikroe.com/Noise_click)

---

### General Description

Noise click is a mikroBUS™ add-on board with noise detecting circuitry. It enables you to set a noise detection threshold for alarm systems, environmental monitoring or data logging. When the volume of ambient sound reaches the set threshold, an interrupt is triggered.
The most important parts of the circuit are the microphone, an RMS-to-DC converter, two dual rail-to-rail Input/Output 10 MHz operational amplifiers, and a 12-bit digital-to-analog converter (DAC).
The 12-bit DAC provides the reference voltage — the noise threshold — for the comparator. You set the exact level through the SPI interface. The threshold should be configured through trial and error (4096 discrete values to select from).
Beside SPI, EN and OUT pins provide additional functionality.
The board works on a 3.3V power supply.


---

### Example

#### Configuration
* MCU:             STM32F107VC
* Dev.Board:       EasyMx Pro v7
* Oscillator:      72 Mhz internal
* Ext. Modules:    Noise click
* SW:              MikroC PRO for ARM 4.7.4

```
#include <stdint.h>

/*      Functions
 ****************************/

#include <stdint.h>
#include "noise_hw.h"

sbit NOISE_CS   at GPIOD_ODR.B13;
sbit NOISE_INT  at GPIOD_IDR.B10;

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

```


