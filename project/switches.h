#ifndef switches_included
#define switches_included

#define SW0 BIT0           /* switch0 is p2.0 */
#define SW1 BIT1           /* switch1 is p2.1 */
#define SW2 BIT2
#define SW3 BIT3
#define SWITCHES (SW0 | SW1 | SW2 | SW3)       /* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_down0, switch_state_down2, switch_state_down3,
  switch_state_changed; /* effectively boolean */

#endif //included
