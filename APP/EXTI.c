///*
// * EXTI.c
// *
// *  Created on: Aug 23, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/GPIO/GPIO_int.h"
//#include "../MCAL/NVIC/NVIC_int.h"
//#include "../MCAL/EXTI/EXTI_int.h"
//#include "../MCAL/SYSCFG/SYSCFG_int.h"
//#include "../HAL/Seven_Segment/Seven_Segment_int.h"
//#define DELAY_MS(d) do{ volatile unsigned int i = (d)*4000;while(i--){ asm ("NOP"); }}while(0)
//s16 G_s16BtnFlag =0 ;
//void EXTI_inc(void)
//{
//	u8 L_u8ButtonState = MGPIO_u8GetPinVal(GPIO_PORTB,GPIO_PIN0);
//	if(L_u8ButtonState == GPIO_LOW)
//	{
//		DELAY_MS(100);
//		while (MGPIO_u8GetPinVal(GPIO_PORTB, GPIO_PIN0));
//		DELAY_MS(100);
//		G_s16BtnFlag++;
//		if (G_s16BtnFlag == 10 ) G_s16BtnFlag = 0;
//		MSEVENSEG_vDisplay(G_s16BtnFlag);
//	}
//
//}
//
//void EXTI_dec(void)
//{
//	u8 L_u8ButtonState = MGPIO_u8GetPinVal(GPIO_PORTB,GPIO_PIN1);
//	if(L_u8ButtonState == GPIO_LOW)
//	{
//		DELAY_MS(100);
//		while (MGPIO_u8GetPinVal(GPIO_PORTB, GPIO_PIN1));
//		DELAY_MS(100);
//		G_s16BtnFlag--;
//		if (G_s16BtnFlag == -1 ) G_s16BtnFlag = 9;
//		MSEVENSEG_vDisplay(G_s16BtnFlag);
//	}
//
//}
//int main(void)
//{
//    MRCC_vInit();
//    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOB);   // LED port
//    MRCC_vEnableCLK(RCC_AHB1, RCC_GPIOA);
//    MRCC_vEnableCLK(RCC_APB2,14);
//
//
//    // Set Output Pins configuration for seven Segment LEDs
//        GPIOx_PinCinfig_t led1 = {
//            .Port = GPIO_PORTA,
//            .Pin  = GPIO_PIN0,
//            .Mode = GPIO_Output,
//            .OutputSpeed = Output_low_speed,
//        };
//        GPIOx_PinCinfig_t led2 = {
//             .Port = GPIO_PORTA,
//             .Pin  = GPIO_PIN1,
//             .Mode = GPIO_Output,
//             .OutputSpeed = Output_low_speed,
//         };
//        GPIOx_PinCinfig_t led3 = {
//             .Port = GPIO_PORTA,
//             .Pin  = GPIO_PIN2,
//             .Mode = GPIO_Output,
//             .OutputSpeed = Output_low_speed,
//         };
//        GPIOx_PinCinfig_t led4 = {
//             .Port = GPIO_PORTA,
//             .Pin  = GPIO_PIN3,
//             .Mode = GPIO_Output,
//             .OutputSpeed = Output_low_speed,
//         };
//
//        GPIOx_PinCinfig_t led5 = {
//               .Port = GPIO_PORTA,
//               .Pin  = GPIO_PIN4,
//               .Mode = GPIO_Output,
//               .OutputSpeed = Output_low_speed,
//           };
//        GPIOx_PinCinfig_t led6 = {
//               .Port = GPIO_PORTA,
//               .Pin  = GPIO_PIN5,
//               .Mode = GPIO_Output,
//               .OutputSpeed = Output_low_speed,
//           };
//        GPIOx_PinCinfig_t led7 = {
//               .Port = GPIO_PORTA,
//               .Pin  = GPIO_PIN6,
//               .Mode = GPIO_Output,
//               .OutputSpeed = Output_low_speed,
//           };
//    // Initialize the Output pins for seven Segment LEDs
//
//        MGPIO_vInit(&led1);
//        MGPIO_vInit(&led2);
//        MGPIO_vInit(&led3);
//        MGPIO_vInit(&led4);
//        MGPIO_vInit(&led5);
//        MGPIO_vInit(&led6);
//        MGPIO_vInit(&led7);
//
//
//    GPIOx_PinCinfig_t button1 = {
//              .Port = GPIO_PORTB,
//              .Pin  = GPIO_PIN0,
//              .Mode = GPIO_Input,
//              .PullType = GPIO_OT_PULLUP ,
//          };
//    GPIOx_PinCinfig_t button2 = {
//                 .Port = GPIO_PORTB,
//                 .Pin  = GPIO_PIN1,
//                 .Mode = GPIO_Input,
//                 .PullType = GPIO_OT_PULLUP ,
//             };
//
//    MGPIO_vInit(&button1);
//    MGPIO_vInit(&button2);
//
//    MEXTI_vInit();
//    MEXTI_vSetTrigger(EXTI_LINE0,EXTI_FALLING_EDGE);
//    MEXTI_vSetTrigger(EXTI_LINE1,EXTI_FALLING_EDGE);
//    MSYSCFG_vSetEXTIPort(0,SYSCFG_PORTB);
//    MSYSCFG_vSetEXTIPort(1,SYSCFG_PORTB);
//    MEXTI_vSetCallBack(EXTI_inc,EXTI_LINE0);
//    MEXTI_vSetCallBack(EXTI_dec,EXTI_LINE1);
//    MEXTI_vEnableINT(EXTI_LINE0);
//    MEXTI_vEnableINT(EXTI_LINE1);
//    MNVIC_vEnable_peripheral_INT(6); // the position is extracted from vector table
//    MNVIC_vEnable_peripheral_INT(7);
//
//
//    while (1)
//    {
//
//    }
//
//}
//
//
//
//
