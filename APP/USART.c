///*
// * USART.c
// *
// *  Created on: Aug 31, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/SYSTICK/SYSTICK_int.h"
//#include "../MCAL/NVIC/NVIC_int.h"
//
//#include "../MCAL/USART/USART_int.h"
//
//
//
//int main()
//{
//	//Enable Clock
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
//	MRCC_vEnableCLK(RCC_APB2,4);
//
//	GPIOx_PinConfig_t TX = {
//			.Port = GPIO_PORTA,
//			.Pin = GPIO_PIN9,
//			.Mode = GPIO_ALF,
//			.AltFunc = GPIO_AF7
//	};
//
//	GPIOx_PinConfig_t RX = {
//				.Port = GPIO_PORTA,
//				.Pin = GPIO_PIN10,
//				.Mode = GPIO_ALF,
//				.AltFunc = GPIO_AF7,
//		};
//
//	MGPIO_vInit(&TX);
//	MGPIO_vInit(&RX);
//
//	MUSART_vInit();
//	MNVIC_vEnable_peripheral_INT(37);
//	while(1)
//	{
//		MUSART_vSendData('A');
//		MUSART_vSendData('B');
//		MUSART_vSendData('C');
//	}
//
//}
