///*
// * DMA.c
// *
// *  Created on: Sep 6, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//
//
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/NVIC/NVIC_int.h"
//#include "../MCAL/DMA/DMA_int.h"
//void led (void)
//{
//	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
//
//}
//u32 source[10] = {1,2,3,4,5,6,7,8,9,10};
//u32 dest[10] = {0};
//
//int main()
//{
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1,22);
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
//	        GPIOx_PinConfig_t led1 = {
//	            .Port = GPIO_PORTA,
//	            .Pin  = GPIO_PIN0,
//	            .Mode = GPIO_Output,
//	            .OutputSpeed = Output_low_speed,
//	        };
//	        MGPIO_vInit(&led1);
//	MNVIC_vEnable_Peripheral_INT(56);
//	MDMA2_vInit(0);
//	MDMA2_vSetStreamCfg(0, source, dest, Byte, Byte, 10, FIFO_FULL);
//	MDMA2_vCallBack(0,led);
//	MDMA2_vEnableStream(0);
//
//
//	while(1)
//	{
//
//	}
//}
//
//
