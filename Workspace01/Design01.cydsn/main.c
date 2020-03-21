/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint16 X,Y=0;
uint8 Channel=0;
//uint16 
void Get_Reference(){
 Channel=Mux_GetChannel();
 switch(Channel){
   case 0: 
     break;
    
   case 1:
     break;
   case 2:
     break;
   case 3:
     break;
   default:
     break;


}


}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
     PWM_Start();
     ADC_Start();
     PWM2_Start();
     Mux_Start();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
