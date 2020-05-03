#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"

int redrawScreen = 1;

void main()
{

  configureClocks();
  lcd_init();
  buzzer_init();
  switch_init();
  loadInstructions();
  or_sr(0x8);
  enableWDTInterrupts();
}
