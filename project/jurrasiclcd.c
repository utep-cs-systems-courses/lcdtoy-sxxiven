#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>

int redrawJScreen = 1;

void main()
{
  configureClocks();
  lcd_init();
  p2sw_init(1);
  enableWDTInterrupts();

  u_char widt = screenWidth, height = screenHeight, j, r, c, colLeft, colRight, base = 70;
 

  //clearScreen(COLOR_RED); 
  or_sr(0x8);

  for(;;)
  {
    while(!redrawJScreen)
    {
      clearScreen(COLOR_WHITE); 
      //or_sr(0x10); //cpu off
      /* for(r = 0; r <=15; r+=3)
      {
	colLeft = 15-r;
	colRight = 15;
	for(c = colLeft; c<= colRight; c+=3)
        {
	  drawPixel(60 - c, 37 - c, COLOR_RED);
	}
	}*/
    }
    redrawJScreen = 0;
    drawJurrasic();
  }
}

void wdt_j_handler(){
  static short count = 0;
  count ++;
  if(count == 15)
  {
    if(p2sw_read())
    {
      redrawJScreen = 1; 
    }
      count = 0;
  }
}
  
void drawJurrasic()
{
  u_char r, c, colLeft, colRight; 
  for(r = 0; r <=15; r+=3)
  {
   colLeft = 15 -r;
   colRight = 15;
   for(c = colLeft; c<=colRight; c+=3)
   {
    drawPixel(60+c, 37+r, COLOR_BLUE); 
   }
  }
}
