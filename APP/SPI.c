///*
// * SPI.c
// *
// *  Created on: Sep 2, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/SYSTICK/SYSTICK_int.h"
//#include "../MCAL/SPI/SPI_int.h"
//
//
//int main()
//{
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
//	MRCC_vEnableCLK(RCC_APB2,12);
//
//
//	MSPI_vInit();
//	GPIOx_PinConfig_t MOSI =
//	{
//			.Port = GPIO_PORTA,
//			.Pin =GPIO_PIN7,
//			.Mode = GPIO_ALF,
//			.AltFunc = GPIO_AF5
//	};
//	MGPIO_vInit(&MOSI);
//	GPIOx_PinConfig_t MISO =
//	{
//			.Port = GPIO_PORTA,
//			.Pin =GPIO_PIN6,
//			.Mode = GPIO_ALF,
//			.AltFunc = GPIO_AF5
//	};
//	MGPIO_vInit(&MISO);
//	GPIOx_PinConfig_t SCK =
//	{
//	        .Port = GPIO_PORTA,
//	        .Pin = GPIO_PIN5,
//	        .Mode = GPIO_ALF,
//	        .AltFunc = GPIO_AF5,
//	        .OutputSpeed = Output_high_speed,
//	        .OutputType = OUTPUT_push_pull,
//	        .PullType = GPIO_OT_NOPULL
//	};
//	MGPIO_vInit(&SCK);
//
//	GPIOx_PinConfig_t LED =
//		{
//				.Port = GPIO_PORTA,
//				.Pin =GPIO_PIN1,
//				.Mode = GPIO_Output,
//				.OutputSpeed = Output_low_speed,
//				.OutputType = OUTPUT_push_pull,
//				.PullType = GPIO_OT_NOPULL
//		};
//		MGPIO_vInit(&LED);
//
//		u8 data = 0 ;
//		data =MSPI_u8Transcieve('A');
//		if (data == 'A')
//		{
//			MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
//		}
//	while(1)
//	{
//
//	}
//}
//
//
//
