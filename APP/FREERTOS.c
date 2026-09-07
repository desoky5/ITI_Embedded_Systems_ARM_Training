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
//#include "../FreeRTOS/FreeRTOS/FreeRTOS.h"
//#include "../FreeRTOS/FreeRTOS/task.h"
//
//void vled1(void *pvparameters)
//{
//
//	while(1)
//	{
//		MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN0);
//			vTaskDelay(100);
//	}
//}
//void vled2(void *pvparameters)
//{
//
//	while(1)
//	{
//		MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN1);
//			vTaskDelay(200);
//	}
//}
//void vled3(void *pvparameters)
//{
//
//	while(1)
//	{
//		MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN2);
//			vTaskDelay(300);
//
//	}
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
//				   .OutputType = OUTPUT_push_pull,
//	           };
//
//	GPIOx_PinConfig_t led2 = {
//	               .Port = GPIO_PORTA,
//	               .Pin  = GPIO_PIN1,
//	               .Mode = GPIO_Output,
//	               .OutputSpeed = Output_low_speed,
//				   .OutputType = OUTPUT_push_pull,
//	           };
//
//	GPIOx_PinConfig_t led3 = {
//	               .Port = GPIO_PORTA,
//	               .Pin  = GPIO_PIN2,
//	               .Mode = GPIO_Output,
//	               .OutputSpeed = Output_low_speed,
//				   .OutputType = OUTPUT_push_pull,
//	           };
//	    // Initialize the Output pins for seven Segment LEDs
//	    MGPIO_vInit(&led1);
//	    MGPIO_vInit(&led2);
//	    MGPIO_vInit(&led3);
//	    xTaskCreate(vled1,(const char* const)"led1",128,NULL,1,NULL);
//	    xTaskCreate(vled2,(const char* const)"led2",128,NULL,2,NULL);
//	    xTaskCreate(vled3,(const char* const)"led2",128,NULL,3,NULL);
//	    vTaskStartScheduler();
//	while(1)
//	{
//
//	}
//}
//
//
//
//
