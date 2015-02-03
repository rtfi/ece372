/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define FCY 14745600

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
    TRISBbits.TRISB15=0;    //LED is an output, so tristate bit is set to 0
    TRISBbits.TRISB14=0;
    TRISBbits.TRISB13=0;
    TRISBbits.TRISB12=0;
    //TODO: Turn each LED OFF
    LATBbits.LATB15=1;
    LATBbits.LATB14=1;
    LATBbits.LATB13=1;
    LATBbits.LATB12=1;
 
}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
    TRISBbits.TRISB5=1; //switch 1 is made an input.
    IFS1bits.CNIF=0;    //CN flag is put down.
    IEC1bits.CNIE=1;    //CN enable is turned on.
    CNEN2bits.CN27IE=1; //
}


void initTimer1(){
    //TODO: Initialize the timer
    PR1=(2*FCY)/256 - 1;
    T1CONbits.TCKPS=0b11;
    T1CONbits.TON=0;
    IEC0bits.T1IE=1;
    IFS0bits.T1IF=0;
    

}