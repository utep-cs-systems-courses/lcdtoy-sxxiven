#include <msp430.h>
//#include "led.h"
//#include "buzzer.h"
//#include "stateMachines.h"
#include "stateMachine.h"
#include "buzzer.h"

char playing_note = 0, song_length = 54, jurrasic_enable, jaw_count = 0; 

void
__interrupt_vec(WDT_VECTOR) WDTInterrupt(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  /* if(blink_count == 100)
  {
    state_advance();
    blink_count = 0;
    }*/
  
  //activates the states for all three buttons if they are enables
 
  if(blink_count == delay)
  {

    //the following make sure the song plays then next note
    if(jurrasic_enable)
    {
      playing_note++;
      playing_note = playing_note % song_length; 
    }
    //advances the states and rests the count
    state_advance();
    blink_count = 0; 
  }
  if( jurrasic_enable == 0 ){ 
    playing_note = 0;
    jaw_count = 0;
  }

  if(jurrasic_enable)
  {
    if(jaw_count == 175)
    {
      // jaw_toggle();
      jaw_count = 0;
    }
    jaw_count++; 
  }
  
   blink_count++; 
}
