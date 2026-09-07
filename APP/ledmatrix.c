///*
// * led.c
// *
// *  Created on: Aug 22, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/NVIC/NVIC_int.h"
//#include "../MCAL/SYSTICK/SYSTICK_int.h"
//#include "../HAL/LEDMATRIX/LEDMATRIX_int.h"
//
//u8 matrix[8] = {0x4F, 0x48, 0x48, 0x7F, 0x09, 0x09, 0x79, 0x00};
//int main(void)
//{
//    MRCC_vInit();
//    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOA);   // LED port
//    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOB);
//    MSYSTCK_Config_t sys = {
//    		.InterruptEnable = INT_DISABLE,
//    		.CLK_SRC = CLK_SRC_AHB_8,
//    };
//
//    MSYSTICK_vInit(&sys);
//
//    // Set Output Pins configuration for seven Segment LEDs
//    GPIOx_PinConfig_t COLS[8] = {{.Port = GPIO_PORTA,.Pin  = GPIO_PIN0,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//    							 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN1,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN2,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN3,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN4,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN5,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN6,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//							     {.Port = GPIO_PORTA,.Pin  = GPIO_PIN7,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								};
//
//    GPIOx_PinConfig_t ROWS[8] = {{.Port = GPIO_PORTB,.Pin  = GPIO_PIN0,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//    							 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN1,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN2,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN5,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN6,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN7,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								 {.Port = GPIO_PORTB,.Pin  = GPIO_PIN8,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//							     {.Port = GPIO_PORTB,.Pin  = GPIO_PIN9,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								};
//// Initialize the Output pins for seven Segment LEDs
//    HLEDMATRIX_vInit(ROWS,8,COLS,8);
//    HLEDMATRIX_vDisplay(matrix,1000);
//    while (1)
//    {
//
//}}
//
