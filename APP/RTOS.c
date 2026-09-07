///*
// * RTOS.c
// *
// *  Created on: Aug 26, 2026
// *      Author: Omar Desoky
// */
//
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../RTOS/RTOS_int.h"
//#include "../MCAL/SYSTICK/SYSTICK_int.h"
//
//void vled1(void)
//{
//	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN0);
//}
//void vled2(void)
//{
//	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN1);
//}
//void vled3(void)
//{
//	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN2);
//}
//int main()
//{
//
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOA);   // LED port
//
//	GPIOx_PinConfig_t led1 = {
//	               .Port = GPIO_PORTA,
//	               .Pin  = GPIO_PIN0,
//	               .Mode = GPIO_Output,
//	               .OutputSpeed = Output_low_speed,
//	           };
//
//	GPIOx_PinConfig_t led2 = {
//	               .Port = GPIO_PORTA,
//	               .Pin  = GPIO_PIN1,
//	               .Mode = GPIO_Output,
//	               .OutputSpeed = Output_low_speed,
//	           };
//
//	GPIOx_PinConfig_t led3 = {
//	               .Port = GPIO_PORTA,
//	               .Pin  = GPIO_PIN2,
//	               .Mode = GPIO_Output,
//	               .OutputSpeed = Output_low_speed,
//	           };
//	    // Initialize the Output pins for seven Segment LEDs
//	    MGPIO_vInit(&led1);
//	    MGPIO_vInit(&led2);
//	    MGPIO_vInit(&led3);
//	RTOS_vCreateTask(vled1,10,0);
//	RTOS_vCreateTask(vled2,25,1);
//	RTOS_vCreateTask(vled3,35,2);
//	RTOS_vStartOS();
//	while(1)
//	{
//
//	}
//}
//
//
//
//
