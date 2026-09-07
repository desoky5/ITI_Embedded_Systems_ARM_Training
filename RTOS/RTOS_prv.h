/*
 * RTOS_prv.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Omar Desoky
 */

#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_

typedef enum
{
	DORMANT,
	READY,
	RUNNING,
	Suspend
}TASK_States_t;

typedef struct{
	void (*TaskFunction)(void); //Pointer to function with return type void and do not take any argument
	u32 Periodicity;
	TASK_States_t state;
}Task_t;

// RESERVED_PRIORITY_ERROR 1
//OUT_OF_SYSTASK_RANGE_ERROR 2
#define RESERVED_PRIORITY_ERROR 1
#define OUT_OF_SYSTASK_RANGE_ERROR 2
#endif /* RTOS_RTOS_PRV_H_ */
