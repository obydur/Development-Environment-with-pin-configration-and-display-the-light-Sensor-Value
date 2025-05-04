/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-1
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include " init.h" 			// Initialization functions
#include " xpc56el.h" 		// Hardware definitations
#include " siu.h"			// System integration Unit for GPIO control


/* Global variables **********************************************************/
int count = 0;
int sw4_value = 0;
// Bool temp_btn1_value = false;
int btns_handler = 1;

// Function to turn off all Leds***********************************************/
void turn_off_all_leds(void)
{
SIU.GPDO[56].R = 0; //LED P (Read)
SIU.GPDO[57].R = 0; //LED RX (Yellow)
SIU.GPDO[58].R = 0; //LED Tx (Yellow)
SIU.GPDO[59].R = 0; //LED U1 (Green)
SIU.GPDO[43].R = 0; //LED U2 (Green)
SIU.GPDO[6].R = 0; //LED U3 (Green)

}

/* Task-1: Potentimer Reading implementation *****************************************************/
void task_pot(int x){

	/* TO-DO: your task implementations **************************************/
	/* Mapping potentimer value (0-4095) to 6 LEDs using ranges 4096 divide into 6 */
	if (x < 682)  // Range 1: 0-681
	{
		SIU.GPDO[56].R = 1;  //Only LED P on
		SIU.GPDO[57].R = 0;  // LED Rx  off
		SIU.GPDO[58].R = 0;  
		SIU.GPDO[59].R = 0;  
		SIU.GPDO[43].R = 0;  
		SIU.GPDO[6].R = 0;  
	}

	else if (x < 1364) // Range 2: 682-1363
	{
		SIU.GPDO[56].R = 1; //ONLY LED P and Rx on
		SIU.GPDO[57].R = 1; 
		SIU.GPDO[58].R = 0; //Others LED are off
		SIU.GPDO[59].R = 0; 
		SIU.GPDO[43].R = 0; 
		SIU.GPDO[6].R = 0; 
	}
	else if (x < 2046)  // Range3: 1354-2045
	{
		SIU.GPDO[56].R = 1;	 //only LED p Rx Tx are on
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[59].R = 0;  // LED u1 u2 u3 are  off
		SIU.GPDO[43].R = 0;  
		SIU.GPDO[6].R = 0;
	}
	else if (x < 2728) 		// range 4: 2046-2727
	{
		 SIU.GPDO[56].R = 1; // LED P RX TX U1 are on
		 SIU.GPDO[57].R = 1; 
		 SIU.GPDO[58].R = 1; 
		 SIU.GPDO[59].R = 1; 
		 SIU.GPDO[43].R = 0; // Only LED u2 and u3 are off
		 SIU.GPDO[6].R = 0; 
		 
	}
	else if (x < 3410)  // Range 5: 2727-3409
	{
		SIU.GPDO[56].R = 1; 	//LED P RX TX U1 U2 are on
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[59].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[6].R = 0; 		// only LED u3 is off
		
	}
	else 	// Range 6: >=3410
	{
		SIU.GPDO[56].R = 1; // All LEDs on
		SIU.GPDO[57].R = 1; 
		SIU.GPDO[58].R = 1; 
		SIU.GPDO[59].R = 1;
		SIU.GPDO[43].R = 1; 
		SIU.GPDO[6].R = 1; 

	}

	/*************************************************************************/
}

/* Task-2  Reading and Displaying the light sensor Value implementation *****************************************************/
void task_ldr(int x){

	/* TO-DO: your task  is Mapping Light Sensor value  (0-3410) to 6 LEDs using ranges implementations **************************************/
	if (x < 682) // Range 1: 0-681

    {

        SIU.GPDO[56].R = 1; // Only LED P on

        SIU.GPDO[57].R = 0;

        SIU.GPDO[58].R = 0;

        SIU.GPDO[6].R = 0;

        SIU.GPDO[43].R = 0;

        SIU.GPDO[59].R = 0;

    }
	else if (x < 1364) // Range 2: 682-1363

    {

        SIU.GPDO[56].R = 1; // LED P and Rx on

        SIU.GPDO[57].R = 1;

        SIU.GPDO[58].R = 0;

        SIU.GPDO[6].R = 0;

        SIU.GPDO[43].R = 0;

        SIU.GPDO[59].R = 0;

    }

    else if (x < 2046) // Range 3: 1364-2045

    {

        SIU.GPDO[56].R = 1; // LED P, Rx, and Tx on

        SIU.GPDO[57].R = 1;

        SIU.GPDO[58].R = 1;

        SIU.GPDO[6].R = 0;

        SIU.GPDO[43].R = 0;

        SIU.GPDO[59].R = 0;

    }

    else if (x < 2728) // Range 4: 2046-2727

    {

        SIU.GPDO[56].R = 1; // LED P, Rx, Tx, and U3 on

        SIU.GPDO[57].R = 1;

        SIU.GPDO[58].R = 1;

        SIU.GPDO[6].R = 1;

        SIU.GPDO[43].R = 0;

        SIU.GPDO[59].R = 0;

    }

    else if (x < 3410) // Range 5: 2728-3409

    {

        SIU.GPDO[56].R = 1; // LED P, Rx, Tx, U3, and U2 on

        SIU.GPDO[57].R = 1;

        SIU.GPDO[58].R = 1;

        SIU.GPDO[6].R = 1;

        SIU.GPDO[43].R = 1;

        SIU.GPDO[59].R = 0;

    }

    else // Range 6: >=3410

    {

        SIU.GPDO[56].R = 1; // All LEDs on

        SIU.GPDO[57].R = 1;

        SIU.GPDO[58].R = 1;

        SIU.GPDO[6].R = 1;

        SIU.GPDO[43].R = 1;

        SIU.GPDO[59].R = 1;

    }


	/*************************************************************************/
}

/* Task-3 implementation *****************************************************/
void task_counter(void){

	/* TO-DO: your task implementations **************************************/
if (sw4_value == 1){
PIT_StartTimer(1);
Switch (count)
{
	case 0:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
		break;
	case 1:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
		break;
	case 1:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 0;
		break;
	case 2:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 1;
		break;	
	case 3:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 0;
		break;
	case 4:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 1;
		break;
	case 5:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 1;
		break;
	case 6:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 1;
		break;
	case 7:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 1;
		break;
	default:
		count = 0;
		break;
	}
   }
	/*************************************************************************/
}

/*
 * @brief	Main program
 *
 * @param	void
 * @retval	int
 */
int main(void) {
	/* peripherals initialization (Hardware), do not remove */
	peripheralsInit();

	//For Task 1
	int pot_value = 0; // Potentiometer Reading (0-4095)
	int sw1_value = 0;  // Switch 1 state

	/* For Task 2*/
	int sw2_value = 0; // Switch 2 state
	int ldr_value = 0;

	 /* For Task 3*/
     int sw3_value = 0;
      	// int sw4_value = 0;
      	int btn1_value = 0;
      	int btn2_value = 0;

	/* TO-DO: your task implementations **************************************/


	/* Configure and start timer channels */	
    // PIT_ConfigureTimer(<channel>, <interval in milliseconds>);
	PIT_ConfigureTimer(1, 1000);

	/*************************************************************************/

	/* main program */
	while(1){
		/* System function, do not remove(Get this form init) */
		systemFunction();
		/* TO-DO: Read potentiometer value and SW1 state implementations **********************************/
        pot_value = (ADC0.CDR[5].R & 0x00000FFF); // Read potentiometer
        ldr_value = (ADC1.CDR[3].R & 0x00000FFF); // Read light sensor
        sw1_value = (SIU.GPDI[52].R);// Switch 1
        sw2_value = (SIU.GPDI[53].R); // Switch 2 use in task 2

		sw3_value = (SIU.GPDI[54].R);
		sw4_value = (SIU.GPDI[55].R);
		btn1_value = (SIU.GPDI[60].R);
		btn2_value = (SIU.GPDI[62].R);
/* Task 1: When SW1 is ON, display potentiometer value on LEDs */
		/*For Task 3*/
		if (btn1_value == 1)
		{
			btns_handler = 1;
		}
		else if (btn2_value == 1)
		{
			btns_handler = 0;
		}

if (sw1_value == 1 && sw2_value == 0)

{

task_pot(pot_value); // Display potentiometer value

}
else if(sw2_value == 1 && sw1_value == 0){

   task_ldr(ldr_value); // Display light sensor value

}
else if (sw1_value == 0 && sw2_value == 0 && sw3_value == 1)
{
	// PIT_StartTimer(1);
	task_counter();
}

else

{

//turn_off_all_leds(); // Turn off all LEDs when SW1 is OFF
PIT_StopTimer(1);

}

		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
	}
}


/*
 * @brief	PIT timer channel 1 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_1(void){

	/* TO-DO: your task implementations **************************************/
	if (btns_handler==1)
		{
			count = count + 1;
		}
		else if (btns_handler==0)
		{
			count = count - 1;
			if (count == -1)
			{
				count = 7;
			}
		}
		else
		{
			count = count + 1;
		}
    /* Not used in Task 1 */

	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void){

	/* TO-DO: your task implementations **************************************/
	   /* Not used in Task 1 */

	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void){

	/* TO-DO: your task implementations **************************************/
   /* Not used in Task 1 */

	/*************************************************************************/
}
