// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include "controlLED.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{
    //TODO: Define states by name
    led4, led5, led6, led7
} stateType;

volatile stateType currState;
volatile int timerFlag=0;

int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
  
    currState=led4;
    
    while(1)
    {
        
        //Use a switch statement to define the behavior based on the state
        switch(currState){
            case led4:
                turnONLED(4);
                break;

            case led5:
                turnONLED(5);
                break;
                
            case led6:
                turnONLED(6);
                break;
                
            case led7:
                turnONLED(7);
                break;
      }
    }
    return 0;
}

void _ISR _CNInterrupt(void)
{
    IFS1bits.CNIF=0;        //put down interrupt flag
    T1CONbits.TON=0;
    
    if(PORTBbits.RB5==0)
    {
        T1CONbits.TON=1;
    }
    if(PORTBbits.RB5==1 && timerFlag==0)
    {
            if(currState==led4 )
            {
                currState=led5;
            }
            else if(currState==led5 )
            {
                currState=led6;
            }
            else if(currState==led6 )
            {
                currState=led7;
            }
            else if(currState==led7 )
            {
                currState=led4;
            }
            TMR1=0;
    }
    else if(PORTBbits.RB5==1 && timerFlag == 1)
    {
        if(currState==led4 )
        {
            currState=led7;
        }
        else if(currState==led5 )
        {
            currState=led4;
        }
        else if(currState==led6 )
        {
            currState=led5;
        }
        else if(currState==led7 )
        {
            currState=led6;
        }
        TMR1=0;
    }
   
    timerFlag=0;
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
   
    IFS0bits.T1IF = 0;
    timerFlag=1;
    
    //TODO: Change states if necessary.

    
    //Make sure if you use any variables that they are declared volatile!
}