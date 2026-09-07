///*
// * TFT.c
// *
// *  Created on: Sep 3, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/SPI/SPI_int.h"
//#include "../HAL/TFT/TFT_int.h"
//#include "../HAL/TFT/TFT_img.h"
//
//
//
//int main()
//{
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
//	MRCC_vEnableCLK(RCC_APB2,12);
//	GPIOx_PinConfig_t MOSI =
//	{
//			.Port = GPIO_PORTA,
//			.Pin =GPIO_PIN7,
//			.Mode = GPIO_ALF,
//			.AltFunc = GPIO_AF5
//	};
//	MGPIO_vInit(&MOSI);
//	GPIOx_PinConfig_t SCK =
//	{
//			.Port = GPIO_PORTA,
//			.Pin =GPIO_PIN5,
//			.Mode = GPIO_ALF,
//			.AltFunc = GPIO_AF5
//	};
//	MGPIO_vInit(&SCK);
//	HTFT_vInit();
//	//u16 size = sizeof(image)/sizeof(image[0]);
//	HTFT_vFillBackgroundColor(0XFF);
//	HTFT_vFillRectangle(0X00);
//
//	while (1)
//	{
//
//	}
//
//}
