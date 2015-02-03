#include "controlLED.h"
#include "p24fj64ga002.h"
#define ON 0;
#define OFF 1;

void turnONLED(int led)
{
    if(led==4)
    {
        LATBbits.LATB15=ON;
        LATBbits.LATB14=OFF;
        LATBbits.LATB13=OFF;
        LATBbits.LATB12=OFF;
    }
    else if(led==5)
    {
        LATBbits.LATB15=OFF;
        LATBbits.LATB14=ON;
        LATBbits.LATB13=OFF;
        LATBbits.LATB12=OFF;
    }
    else if(led==6)
    {
        LATBbits.LATB15=OFF;
        LATBbits.LATB14=OFF;
        LATBbits.LATB13=ON;
        LATBbits.LATB12=OFF;
    }
    else if(led==7)
    {
        LATBbits.LATB15=OFF;
        LATBbits.LATB14=OFF;
        LATBbits.LATB13=OFF;
        LATBbits.LATB12=ON;
    }
    
}
