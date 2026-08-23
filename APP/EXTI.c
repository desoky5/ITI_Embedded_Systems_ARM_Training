/*
 * EXTI.c
 *
 *  Created on: Aug 23, 2026
 *      Author: Omar Desoky
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MTH.h"
#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/NVIC/NVIC_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#define DELAY_MS(d) do{ volatile unsigned int i = (d)*4000;while(i--){ asm ("NOP"); }}while(0)

void Led(void)
{
	MGPIO_vTogPinVal(GPIO_PORTC,GPIO_PIN13);
}
int main(void)
{
    MRCC_vInit();
    MEXTI_vInit();

    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOC);   // LED port
    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOA);
    // Set Output Pins configuration for seven Segment LEDs
    GPIOx_PinCinfig_t led1 = {
        .Port = GPIO_PORTC,
        .Pin  = GPIO_PIN13,
        .Mode = GPIO_Output,
        .OutputSpeed = Output_low_speed,
    };

    MGPIO_vInit(&led1);

    GPIOx_PinCinfig_t button = {
              .Port = GPIO_PORTA,
              .Pin  = GPIO_PIN0,
              .Mode = GPIO_Input,
              .PullType = GPIO_OT_PULLUP ,
          };

    MGPIO_vInit(&button);

    MEXTI_vSetTrigger(EXTI_LINE0,EXTI_FALLING_EDGE);
    MEXTI_vSetCallBack(Led,EXTI_LINE0);
    MEXTI_vEnableINT(EXTI_LINE0);
    MNVIC_vEnable_peripheral_INT(6);
    MGPIO_vSetPinVal(GPIO_PORTC,GPIO_PIN13,GPIO_LOW);


    while (1)
    {

    }

}




