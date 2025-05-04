/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "init.h"  // Initialization functions
#include "xpc56el.h" //Hardware definitions
#include "siu.h"   // system Integration Unit for GPIO control


/*
 * @brief	SIU pin configuration function
 *
 * @param	void
 * @retval	void
 */
void SIU_Init(void)
{
	// Configure all pins which are required for your task here

	/* TO-DO: your task implementations **************************************/


	/* Input pin configurations */

	//SIU.PCR[...].R = ...;
	SIU.PCR[52].R = 0X100;	// D4 SW1 configured as input
    SIU.PCR[53].R = 0X100;	// D5 SW2 configured as input
    SIU.PCR[54].R = 0X100;	// D6 SW3 configured as input
    SIU.PCR[55].R = 0X100;	//D7 SW4 configured as input
    SIU.PCR[60].R = 0X100;	// D12 BT1 configured as input
    SIU.PCR[62].R = 0X100;	// D14 BT2 configured as input



	/* Output pin configurations */

	//SIU.PCR[...].R = ...;
	SIU.PCR[56].R = 0X200; 	 // P D8 LED Light when command is high
	SIU.PCR[57].R = 0X200; 	 // RX D9 LED Light when command is high
	SIU.PCR[58].R = 0X200; 	 // TX D10 LED Light when command is high
	SIU.PCR[59].R = 0X200; 	 // U1 D11 LED Light when command is high
	SIU.PCR[43].R = 0X200; 	 // U2 C11 LED Light when command is high
	SIU.PCR[6].R = 0X200; 	 // U3 A6 LED Light when command is high



	/* Analog pin configurations */

	//SIU.PCR[...].R = ...;
	SIU.PCR[66].R = 0X2500; 	 // POT E2 LDR configured as analog input
	SIU.PCR[32].R = 0X2500; 	 // LDR C0 LDR configured as analog input
	/*************************************************************************/
}
