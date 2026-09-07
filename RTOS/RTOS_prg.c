///*
// * RTOS_prg.c
// *
// *  Created on: Aug 26, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MTH.h"
//
//#include "RTOS_int.h"
//#include "RTOS_prv.h"
//#include "RTOS_cfg.h"
//#include "../MCAL/SYSTICK/SYSTICK_int.h"
//
//Task_t SystemTasks[MAX_SYSTASK_SIZE] = {{NULL}};
//u32 TimingArray[MAX_SYSTASK_SIZE]={0};
//
//u8 RTOS_vCreateTask(void (*TaskFunction)(void),u32 Periodicity,u8 Priority)
//{
//	u8 L_u8ErrorState = 0 ;
//	if(SystemTasks[Priority].TaskFunction == NULL)
//	{
//	//Initially check that the given priority is in the system range
//	if (Priority< MAX_SYSTASK_SIZE)
//	{
//	SystemTasks[Priority].TaskFunction = TaskFunction ;
//	SystemTasks[Priority].Periodicity = Periodicity ;
//	SystemTasks[Priority].state = READY; // Initialize the task as ready
//
//	}
//	else
//	{
//		 L_u8ErrorState = RESERVED_PRIORITY_ERROR; //
//	}
//	}
//	else
//	{
//		L_u8ErrorState = OUT_OF_SYSTASK_RANGE_ERROR;
//	}
//	return L_u8ErrorState;
//}
//
//void RTOS_vScheduler(void)
//{
//	for (u8 Counter = 0 ; Counter < MAX_SYSTASK_SIZE ; Counter ++ )
//	{
//		if(SystemTasks[Counter].state==READY)
//		{
//			if(TimingArray[Counter] == 0)
//		   {
//			SystemTasks[Counter].state = RUNNING;
//			SystemTasks[Counter].TaskFunction();
//			SystemTasks[Counter].state = READY;
//
//			TimingArray[Counter] = SystemTasks[Counter].Periodicity;
//
//		   }
//			else
//			{
//				TimingArray[Counter]--;
//			}
//	    }
//	}
//}
//
//u8 RTOS_vDeleteTask(u8 Priority)
//{
//	u8 L_u8ErrorState = 0 ;
//	if (Priority< MAX_SYSTASK_SIZE)
//	{
//	if(SystemTasks[Priority].TaskFunction != NULL)
//	{
//	SystemTasks[Priority] = (Task_t){0} ;
//	}
//	}
//	else
//	{
//		L_u8ErrorState = OUT_OF_SYSTASK_RANGE_ERROR ;
//	}
//	return L_u8ErrorState ;
//}
//u8 RTOS_vSuspedTask(u8 Priority)
//{
//	u8 L_u8ErrorState = 0 ;
//	if (Priority< MAX_SYSTASK_SIZE)
//	{
//	if(SystemTasks[Priority].state == READY)
//	{
//	SystemTasks[Priority].state	 = Suspend ;
//	}
//	}
//	else
//	{
//		L_u8ErrorState = OUT_OF_SYSTASK_RANGE_ERROR ;
//	}
//	return L_u8ErrorState ;
//}
//
//u8 RTOS_vResumeTask(u8 Priority)
//{
//
//	u8 L_u8ErrorState = 0 ;
//	if (Priority< MAX_SYSTASK_SIZE)
//	{
//	if(SystemTasks[Priority].state == READY ||SystemTasks[Priority].state == Suspend)
//	{
//	SystemTasks[Priority].state	 = READY ;
//	}
//	}
//	else
//	{
//		L_u8ErrorState = OUT_OF_SYSTASK_RANGE_ERROR ;
//	}
//	return L_u8ErrorState ;
//}
//
//void RTOS_vStartOS(void)
//{
//	MSYSTCK_Config_t STK_cfg = {
//			.InterruptEnable = INT_ENABLE,
//			.CLK_SRC = CLK_SRC_AHB_8
//	};
//	MSYSTICK_vInit(&STK_cfg);
//	MSYSTICK_vSetIntervalMulti(TICK_TIM,RTOS_vScheduler);
//}
