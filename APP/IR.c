#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MTH.h"

#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/SYSTICK/SYSTICK_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/NVIC/NVIC_int.h"
#include "../HAL/Seven_Segment/Seven_Segment_int.h"
#define DELAY_MS(d) do{ volatile unsigned int i = (d)*4000;while(i--){ asm ("NOP"); }}while(0)
s16 G_s16BtnFlag =0 ;
/* Function Prototypes */
void APP_GET_TIME(void);
void APP_DecodeBits(void);

/* Global State Variables */
volatile u8  G_u8StartingFlag = 0;
volatile u32 G_u32Arr[50]     = {0};
volatile u8  G_u8Counter      = 0;
volatile u8  G_u8Value        = 0;

int main(void)
{
    /* 1. Initialize System Clock */
    MRCC_vInit();

    /* ---------------- Peripheral Clock Selection ---------------- */
    /* Cortex-M4 (STM32F4) */
    MRCC_vEnableCLK(RCC_AHB1, GPIO_PORTA);
    MRCC_vEnableCLK(RCC_APB2, 14); // SYSCFG Clock (Bit 14)

    /* Cortex-M3 (STM32F1) - Alternative */
    // MRCC_vEnableCLK(RCC_APB2, RCC_GPIOA);
    // MRCC_vEnableCLK(RCC_APB2, 0);  // AFIO Clock (Bit 0)

    /* 2. Configure IR Input Pin (PA0) */
    GPIOx_PinConfig_t IR = {
        .Port = GPIO_PORTA,
        .Pin  = GPIO_PIN0,
        .Mode = GPIO_Input
    };

    MGPIO_vInit(&IR);

    /* 3. Configure Status LED Pin (PA1) */
    GPIOx_PinConfig_t LED = {
        .Port       = GPIO_PORTA,
        .Pin        = GPIO_PIN1,
        .Mode       = GPIO_Output,
        .OutputSpeed      = Output_low_speed,
        .OutputType = OUTPUT_push_pull
    };
    MGPIO_vInit(&LED);
    // Set Output Pins configuration for seven Segment LEDs
        GPIOx_PinConfig_t led1 = {
            .Port = GPIO_PORTA,
            .Pin  = GPIO_PIN2,
            .Mode = GPIO_Output,
            .OutputSpeed = Output_low_speed,
        };
        GPIOx_PinConfig_t led2 = {
             .Port = GPIO_PORTA,
             .Pin  = GPIO_PIN3,
             .Mode = GPIO_Output,
             .OutputSpeed = Output_low_speed,
         };
        GPIOx_PinConfig_t led3 = {
             .Port = GPIO_PORTA,
             .Pin  = GPIO_PIN4,
             .Mode = GPIO_Output,
             .OutputSpeed = Output_low_speed,
         };
        GPIOx_PinConfig_t led4 = {
             .Port = GPIO_PORTA,
             .Pin  = GPIO_PIN5,
             .Mode = GPIO_Output,
             .OutputSpeed = Output_low_speed,
         };

        GPIOx_PinConfig_t led5 = {
               .Port = GPIO_PORTA,
               .Pin  = GPIO_PIN6,
               .Mode = GPIO_Output,
               .OutputSpeed = Output_low_speed,
           };
        GPIOx_PinConfig_t led6 = {
               .Port = GPIO_PORTA,
               .Pin  = GPIO_PIN7,
               .Mode = GPIO_Output,
               .OutputSpeed = Output_low_speed,
           };
        GPIOx_PinConfig_t led7 = {
               .Port = GPIO_PORTA,
               .Pin  = GPIO_PIN8,
               .Mode = GPIO_Output,
               .OutputSpeed = Output_low_speed,
           };
    // Initialize the Output pins for seven Segment LEDs

        MGPIO_vInit(&led1);
        MGPIO_vInit(&led2);
        MGPIO_vInit(&led3);
        MGPIO_vInit(&led4);
        MGPIO_vInit(&led5);
        MGPIO_vInit(&led6);
        MGPIO_vInit(&led7);


    /* 4. Configure External Interrupt (EXTI Line 0, Falling Edge) */
    MEXTI_vInit();
    MEXTI_vEnableINT(EXTI_LINE0);
    MEXTI_vSetTrigger(EXTI_LINE0, EXTI_FALLING_EDGE);
    MEXTI_vSetCallBack(APP_GET_TIME, EXTI_LINE0);

    /* 5. Enable EXTI0 IRQ Channel in NVIC (Position 6) */
    MNVIC_vEnable_Peripheral_INT(6);

    /* 6. Configure SysTick Timer (Interrupt Enabled, AHB / 8 Clock Source) */
    MSYSTIC_Config_t STK_CFG = {
        .InterruptEnable = INT_ENABLE,
        .CLK_SRC         = CLK_SRC_AHB_8
    };
    MSYSTICK_vInit(&STK_CFG);
//   	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
//    	MSYSTICK_vSetDelay_ms(1000);
//    	MGPIO_vSetPinVal(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
//    	MSYSTICK_vSetDelay_ms(1000);
    while(1)
    {

    	 switch(G_u8Value)
    	 {

    	 case 22 :
    	    		 HSEVENSEG_vDisplay(0);
    	    		break;
    	 case 12 :
    		 HSEVENSEG_vDisplay(1);
    		break;
    	 case 24 :
    		 HSEVENSEG_vDisplay(2);
    		  break;
    	 case 94 :
        		 HSEVENSEG_vDisplay(3);
        		break;
    	 case 8 :
        		 HSEVENSEG_vDisplay(4);
        		  break;
    	 case 28 :
    	        HSEVENSEG_vDisplay(5);
    	        break;
    	 case 90 :
    	        HSEVENSEG_vDisplay(6);
    	        break;
    	 case 66 :
        	   HSEVENSEG_vDisplay(7);
        	   break;
    	 case 82 :
    	   HSEVENSEG_vDisplay(8);
    	   break;
    	 case 74 :
    	      HSEVENSEG_vDisplay(9);
    	       break;
    	 case 9 :

    		 for (u8 i = 0 ; i <10; i++)
    		 {
    			 HSEVENSEG_vDisplay(i);
    			DELAY_MS(500);
    		 }
    		 break;
    	 case 21 :
    	     	for (s8 i = 9 ; i >-1;i--)
    	     	{
    	     	HSEVENSEG_vDisplay(i);
    	     	DELAY_MS(500);
    	     	}
    	       break;
    	 }
    }

    return 0;
}

/* ================= EXTI0 ISR: Timestamp Capture ================= */

void APP_GET_TIME(void)
{
    if(G_u8StartingFlag == 0)
    {
        /* First Falling Edge: Start of Frame Leader Code */
        G_u8StartingFlag = 1;
        MSYSTICK_vSetIntervalSingle(15, APP_DecodeBits);
    }
    else
    {
        /* Capture bit pulse duration in microseconds */
        G_u32Arr[G_u8Counter++] = MSYSTICK_u32GetElapsedTime_SingleShot() / 3.125;

        /* Rearm timeout for the next incoming bit */
        MSYSTICK_vSetIntervalSingle(4, APP_DecodeBits);
    }
}

/* ================= SysTick Callback: Frame Decoder ================= */

void APP_DecodeBits(void)
{
    G_u8Value = 0;

    /* Decode Command Byte (Indices 17 to 24) */
    for(u8 i = 0; i < 8; i++)
    {
        if(G_u32Arr[17 + i] >= 1000 && G_u32Arr[17 + i] <= 1250)
        {
            CLR_BIT(G_u8Value, i); // Logical '0'
        }
        else if(G_u32Arr[17 + i] >= 2000 && G_u32Arr[17 + i] <= 2450)
        {
            SET_BIT(G_u8Value, i); // Logical '1'
        }
    }

    /* Reset State Flags and Counters */
    G_u8StartingFlag = 0;
    G_u8Counter      = 0;

    /* Clear capture buffer */
    for(u8 i = 0; i < 50; i++)
    {
        G_u32Arr[i] = 0;
    }
}
