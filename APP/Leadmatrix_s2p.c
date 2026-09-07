/*
 * Leadmatrix_s2p.c
 *
 *  Created on: Sep 7, 2026
 *      Author: Omar Desoky
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MTH.h"

#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/SYSTICK/SYSTICK_int.h"
#include "../HAL/S2P/S2P_int.h"
#include "../HAL/LEDMATRIX/LEDMATRIX_int.h"

int main()
{
	MRCC_vInit();
	MRCC_vEnableCLK(RCC_AHB1,GPIO_PORTA);
	MSYSTIC_Config_t sys = {
	    		.InterruptEnable = INT_DISABLE,
	    		.CLK_SRC = CLK_SRC_AHB_8,
	    };

	    MSYSTICK_vInit(&sys);
	u8 matrix[8] = {0x00, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x00};
	S2P_Init_t ledmatrix ={
			.DataPort = GPIO_PORTA,
			.DataPin = GPIO_PIN0,
			.ShiftCLKPort=GPIO_PORTA,
			.ShiftCLKPin = GPIO_PIN1,
			.LatchCLKPort = GPIO_PORTA,
			.LatchCLKPin = GPIO_PIN2
	};
	HS2P_vInit(&ledmatrix);

	while(1)
	{
		for (u8 col = 0 ; col < 8 ; col ++ )
		{
			u8 colByte = ~(1 << (7 - col));
			u16 full = ((u16)colByte<<8)| matrix[col];
			HS2P_vSendData(&ledmatrix,full);
			MSYSTICK_vSetDelay_ms(2);

		}
	}
}



