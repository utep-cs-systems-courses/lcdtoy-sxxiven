/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char j;
  clearScreen(COLOR_WHITE);
  float x, y;

  
  for (j =0; j<20; j++){
    drawPixel (j, j, COLOR_BLACK);}
  for(j = 20; j>0; j--)
    drawPixel (0, j, COLOR_BLACK);
  for(j = 20; j >0; j--)
    drawPixel (j, 20, COLOR_BLACK);
}
