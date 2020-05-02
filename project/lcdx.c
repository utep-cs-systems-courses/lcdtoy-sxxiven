/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

int redrawScreen = 1; 

/** Initializes everything, clears the screen, draws "hello" and a square */
void
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight, j;
  p2sw_init(15);
  or_sr(0x8); 
  //clearScreen(COLOR_WHITE);
  float x, y;

  drawString5x7(10, 10, "switches:", COLOR_BLACK, COLOR_WHITE); 
  /*
  for (j =0; j<20; j++){
    drawPixel (j*2, j, COLOR_BLACK);
    drawPixel (0,20 -j, COLOR_BLACK);
    drawPixel (40-(2*j), 20, COLOR_BLACK);
    }*/

  u_char r, c;
  u_char colLeft, colRight;
  u_char base = 70; 
 
  while(1){
    u_int switches = p2sw_read(), i;
    char str[5];
    /*for(i = 0; i < 4; i++){
      str[i] = (switches & (1<<i)) ? '-': '0' +i;}
    str[4] = 0;
    drawString5x7(20, 20, str, COLOR_BLACK, COLOR_WHITE); 
    */
    if(switches & (1<<1)){
    for(r = 0; r <=15; r+=3){
      colLeft = 15 - r;
      colRight = 15;
      for(c = colLeft; c<=colRight; c+=3){
	drawPixel(60+c, 37+r, COLOR_BLACK);
	drawPixel(60-c, 37+r, COLOR_BLACK);
	drawPixel(60+c, 37-r, COLOR_BLACK);
	drawPixel(60 - c, 37-r, COLOR_BLUE); 
      }
    }
    }
     else{
       clearScreen(COLOR_WHITE);
     }

    //the following is a trapazoid
  
    /*for(c = 10; c<50; c++){
      for(r = 30; r < base; r++){
	if( r >c+20 && r > 50){
	  drawPixel(70-c, r, COLOR_BLACK);
	  drawPixel(c+50, r, COLOR_BLACK);
	}
      }
      }*/
  }
  /*
  for(c; c<= 30; c++){
    drawPixel(c, c, COLOR_RED);
    drawPixel((j/2), 40, COLOR_BLUE);
    drawPixel((j/2), j, COLOR_BLACK); 
    }*/
}
