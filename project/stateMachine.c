#include <msp430.h>
#include "stateMachine.h"
//#include "states.h"
//#include "led.h"
//#include "buzzer.h"
#include "switches.h"
//#include "off.h"
#include <lcdutils.h>
#include<lcddraw.h>
#include "renderings.h"

char state = 3, switch_state_change, delay, donut_enable = 0, jaw_toggle = 1;
int s1c = 0, s2c = 0, s3c = 0, s4c = 0;


//the following are the global variables used
//char delay = 150, reps = 0, siren_enable = 0, s_letter = 1, changed;

//the following is the music score for the quick version of jurrasic park theme song
int music_score[54][2] =
  {
  {Bb5, Three}, {Bb5, Eigth}, {A5, Eigth}, {Bb5, Half}, {C6, Eigth}, {C6, Half}, {Eb6, Eigth},
  {Eb6, Three}, {D6, Eigth}, {Bb5, Eigth}, {C6, Half}, {A5, Eigth}, {F5, Quarter}, {D6, Eigth},
  {Bb5, Eigth}, {C6, Three}, {F6, Eigth}, {Bb5, Eigth}, {Eb6, Half}, {D6, Eigth}, {D6, Half},
  {C6, Eigth}, {C6, Full}, {Bb6, Eigth}, {A6, Eigth}, {Bb6, Quarter}, {F6, Quarter},
  {Eb6, Quarter}, {Bb6, Eigth}, {A6, Eigth}, {Bb6, Half}, {F6, Quarter}, {Bb5, Quarter},
  {Ab6, Full}, {Bb6, Eigth}, {A6, Eigth}, {Bb6, Quarter}, {F6, Eigth}, {E6, Eigth}, {F6, Quarter},
  {Eb6, Eigth},{D6, Eigth}, {Eb6, Quarter}, {C6, Eigth}, {Bb5, Eigth}, {C6, Quarter}, {Bb6, Eigth},
  {A6, Eigth}, {Bb6, Quarter}, {F6, Eigth}, {E6, Eigth}, {F6, Half}, {A6, Full}, {Bb6, Full}
  }; 

//  The following funtion toggles the s which is comprimised of three short 'beeps'
/*char toggle_SOS()	   
{
  delay = (reps < 3) ? 10 : 80;
  green_led = 1; 
  reps++;
  buzzer_set_period(1000);
  return 1;		      
}

// the following sets the conditions for when the siren is on its low state 
char siren_low()
{
  delay = 1;
  reps++;
  green_led = 1; 
  buzzer_set_period(3500);
  return 1; 
}

//this function provides the high siren conditions
char siren_high()
{
  delay = 250;
  reps = 0;
  green_led = 1;
  buzzer_set_period(2500);
  return 1; 
}

//this function toggles the buzzer and the led off as needed
char toggle_off()
{
  char changed = 0; 
  if(reps <3 && count_on) //sets the off conditions for the s letter in s.o.s
  {
   changed = toggle_leds_off(50);
  }
  else if (reps >= 3 && count_on) //sets the off condition for the letter o in s.o.s
  {
    if(reps == 6)
    {
      reps = 0; //resets the count to the begging of the message once it has compleated
    }
    changed = toggle_leds_off(100);
  }
  else if (siren_enable)
  {
    changed = toggle_leds_off(2); //sets the off condition for the low siren
  }
  return changed;
}
*/

void loadInstructions()
{
  drawInstructions();
}

//The following function instructs on how to play the specifies not and its delay (total time) 
void play_note()
{
  //green_led = 0;
  if(playing_note %3 == 0)
    toogle_jaw();
  delay = music_score[playing_note][1];
  buzzer_set_period(music_score[playing_note][0]);
}

void toogle_jaw()
{
  if(jaw_toggle)
    drawTriangle(53, 90, 3, 6, 1, 1, 3, COLOR_RED);
  else
    drawTriangle(53, 90, 3, 6, 1, 1, 3, COLOR_BLACK);
  jaw_toggle++;
  jaw_toggle = jaw_toggle % 2; 
}

void state_advance()
{
  delay = 100; 
  switch(state)
  {
  case 0: //draws traingles
    if(switch_state_changed)
    {
      buzzer_set_period(0);
      drawHourGlass();
      switch_state_changed = 0; 
    } break;
  case 1:
    if(switch_state_changed)
    {
      buzzer_set_period(0);
      clearScreen(COLOR_YELLOW);
      drawString5x7(23, 12, "Here is a donut", COLOR_BLACK, COLOR_YELLOW);
      drawDonut();
      switch_state_changed = 0;
    }
    break;
  case 2:
    if(switch_state_changed){ clearScreen(COLOR_RED);
      drawJurrasicPark();
      switch_state_changed = 0;
    }
    play_note();
    break;
  case 3:
    if(switch_state_changed)
    {
      drawInstructions();
      buzzer_set_period(0);
      switch_state_changed = 0;
    }break;
  case 4:
    if(switch_state_changed)
    {
      buzzer_set_period(0);
      drawString5x7(55, 115, "NOM", COLOR_BLACK, COLOR_YELLOW);
      drawEatenDonut(60, 48, 12, 12, 3, COLOR_YELLOW);
    }
    break;
  }
}


