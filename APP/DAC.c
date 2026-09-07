///*
// * EXTI.c
// *
// *  Created on: Aug 23, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/NVIC/NVIC_int.h"
//#include "../MCAL/EXTI/EXTI_int.h"
//#include "../MCAL/SYSCFG/SYSCFG_int.h"
//
//#include "../HAL/DAC/DAC_int.h"
//#include "../HAL/DAC/voice.h"
//u8 playing ;
//static u32 Iterator = 0;
//void DAC_Hndler(void)
//{
//	if (playing)
//	{
//	HDAC_vSendSample(test1_raw, Iterator);
//	Iterator++;
//	if (Iterator == voice_len)
//		{
//		Iterator = 0;
//		playing = 0 ;
//		}
//	}
//}
//void button_Handeler(void)
//{
//	Iterator = 0 ;
//	playing = 1;
//}
//int main()
//{
//	MRCC_vInit();
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
//	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTB);
//	    GPIOx_PinConfig_t DAC_Pins[8] = {{.Port = GPIO_PORTA,.Pin  = GPIO_PIN0,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//	    							 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN1,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN2,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN3,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN4,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN5,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									 {.Port = GPIO_PORTA,.Pin  = GPIO_PIN6,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//								     {.Port = GPIO_PORTA,.Pin  = GPIO_PIN7,.Mode = GPIO_Output,.OutputSpeed = Output_low_speed},
//									};
//
//	    GPIOx_PinConfig_t button1 = {
//	              .Port = GPIO_PORTB,
//	              .Pin  = GPIO_PIN0,
//	              .Mode = GPIO_Input,
//	              .PullType = GPIO_OT_PULLUP ,
//	          };
//
//	    MGPIO_vInit(&button1);
//
//	HDAC_vInit(DAC_Pins,8);
//	MSYSTICK_vSetIntervalMulti_us(125, DAC_Hndler);
//
//	MEXTI_vInit();
//	MEXTI_vSetTrigger(EXTI_LINE0,EXTI_FALLING_EDGE);
//	MSYSCFG_vSetEXTIPort(0,SYSCFG_PORTB);
//	MEXTI_vSetCallBack(DAC_Hndler,EXTI_LINE0);
//	MEXTI_vEnableINT(EXTI_LINE0);
//	MNVIC_vEnable_peripheral_INT(6);
//
//while(1)
//{
//
//}
//return 0 ;
//}
//
//
//
//
//
//
