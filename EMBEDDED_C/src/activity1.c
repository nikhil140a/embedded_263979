#include "activity1.h"

void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1<<LedPin);
	/* Configure Switch1 pin as Output */
	DDRD &= ~(1<<SwitchPin_0);
    SW_PORT |= (1<<SwitchPin_0);
	/* Configure Switch2 pin as Output */
    DDRD &= ~(1<<SwitchPin_1);
    SwitchPort |= (1<<SwitchPin_1);
}

int initialize_led(){
    /* Check if both Switch is closed; i.e Pins 3 and 4 of port D is low*/
    if(!(PIND&(1<<SwitchPin_0)) && !(PIND&(1<<SwitchPin_1))){
        /* Turn on LED */
        LedPort |= (1<<LedPin);
        _delay_ms(2000);
        return 1;
    }
    else{
        LedPort &= ~(1<<LedPin);
        /* Turn off LED*/
        _delay_ms(2000);
        return 0;
    }
}

