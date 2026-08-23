/*
 * NVIC_int.h
 *
 *  Created on: Aug 22, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

typedef enum{
	Group16Sub0 = 3,//using the don`t care advantage to increment by 1
	Group8Sub2 , // 5
	Group4Sub4 ,
	Group2Sub8 ,
	Group0Sub16

}NVIC_Group_t;

#define Group16
void MNVIC_vEnable_peripheral_INT(u8 A_u8Position);
void MNVIC_vDisable_peripheral_INT(u8 A_u8Position);
void MNVIC_vSetPendingFlag(u8 A_u8Position);
void MNVIC_vClearPendingFlag(u8 A_u8Position);
u8 MNVIC_u8GetFlagStatus(u8 A_u8Position);

void MNVIC_vSetGroupPriority(NVIC_Group_t A_xGroupPriority);

void MNVIC_vSetPeripheralPriority(u8 A_u8Position,u8 A_u8Group ,u8 A_u8SubGroup);




#endif /* MCAL_NVIC_NVIC_INT_H_ */
