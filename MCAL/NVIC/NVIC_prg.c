/*
 * NVIC_prg.c
 *
 *  Created on: Aug 22, 2026
 *      Author: Omar Desoky
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MTH.h"

#include "NVIC_int.h"
#include "NVIC_prv.h"
 u8 G_u8GroupPriority ;

void MNVIC_vEnable_peripheral_INT(u8 A_u8Position)
{
	SET_BIT(NVIC-> ISERx[A_u8Position/32],A_u8Position%32);
}
void MNVIC_vDisable_peripheral_INT(u8 A_u8Position)
{
	SET_BIT(NVIC-> ICERx[A_u8Position/32],A_u8Position%32);
}
void MNVIC_vSetPendingFlag(u8 A_u8Position)
{
	SET_BIT(NVIC-> ISPRx[A_u8Position/32],A_u8Position%32);
}
void MNVIC_vClearPendingFlag(u8 A_u8Position)
{
	SET_BIT(NVIC-> ICPRx[A_u8Position/32],A_u8Position%32);
}

u8 MNVIC_u8GetFlagStatus(u8 A_u8Position)
{
	u8 L_u8Flag ;
	L_u8Flag =  GET_BIT( NVIC->IABRx[A_u8Position/32],A_u8Position%32);
	return L_u8Flag;
}

void MNVIC_vSetGroupPriority(NVIC_Group_t A_xGroupPriority)
{
	G_u8GroupPriority = A_xGroupPriority;
	SCB_AIRCR = (VECTKEY)|(A_xGroupPriority << 8); // Vectkey is already in high section no need for shifting
}

void MNVIC_vSetPeripheralPriority(u8 A_u8Position,u8 A_u8Group ,u8 A_u8SubGroup)
{
	switch(G_u8GroupPriority)
	{
	case Group0Sub16:
		NVIC->IPRx[A_u8Position]= A_u8SubGroup<<4;
		break;
	case Group2Sub8:
		NVIC->IPRx[A_u8Position]= (A_u8SubGroup<<4)|(A_u8Group<<7);
		break;
	case Group4Sub4:
		NVIC->IPRx[A_u8Position]= (A_u8SubGroup<<4)|(A_u8Group<<6);
		break;
	case Group8Sub2:
		NVIC->IPRx[A_u8Position]= (A_u8SubGroup<<4)|(A_u8Group<<5);
		break;
	case Group16Sub0:
		NVIC->IPRx[A_u8Position]=(A_u8Group<<4);
		break;
	}
}
