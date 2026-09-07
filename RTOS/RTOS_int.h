/*
 * RTOS_int.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Omar Desoky
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_
//Error Handlers
// RESERVED_PRIORITY_ERROR 1
//OUT_OF_SYSTASK_RANGE_ERROR 2

void RTOS_vStartOS(void);
u8 RTOS_vCreateTask(void (*TaskFunction)(void),u32 Periodicity,u8 Priority);
void RTOS_vScheduler(void);
u8 RTOS_vDeleteTask(u8 Priority);
u8 RTOS_vSuspedTask(u8 Priority);
u8 RTOS_vResumeTask(u8 Priority);

#endif /* RTOS_RTOS_INT_H_ */
