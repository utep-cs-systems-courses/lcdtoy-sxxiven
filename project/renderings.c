#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "renderings.h"

void drawTriangle(u_char rowOff, u_char colOff, u_char width, u_char height,
	       u_char rowJump, u_char colJump, u_char opperation,  u_int colorBGR)
{
  u_char r, c, colLeft, colRight;

  for(r = 0; r <= height; r+=rowJump)
  {
    colLeft = 0;
    colRight = r*width;
    for(c = colLeft; c <= colRight; c+= colJump)
    {
      switch (opperation)
      {
      case 0: //both offsets are adding
	drawPixel(colOff+c, rowOff+r, colorBGR); break;
      case 1: // only column offset is adding
	drawPixel(colOff+c, rowOff-r, colorBGR); break;
      case 2: // only row offset is adding
	drawPixel(colOff-c, rowOff+r, colorBGR); break;
      case 3: //both offsets are subtracting
	drawPixel(colOff-c, rowOff-r, colorBGR); break; 
      }
    }
  }
}

void drawBox(u_char rowOff, u_char colOff, u_char width, u_char height,
	     u_char rowJump, u_char colJump, u_int colorBGR)
{
  u_char r, c;

  for(r = 0; r <= height; r+=rowJump)
  {
    for(c = 0; c <= width; c+=colJump)
    {
      drawPixel(colOff+c, rowOff+r, colorBGR);
    }
  }
}

void drawEatenDonut(u_char rowOff, u_char colOff, u_char width, u_char height,
		u_char stepSize, u_int colorBGR)
{
  u_char r, c, colRight, colLeft;
  for(r= 0; r <= height; r++)
  {
    colLeft = 0;
    colRight = width - (r/stepSize);
    for(c = colLeft; c <= colRight; c++)
    {
      drawPixel(colOff+c, rowOff+r, colorBGR);
    }
  }
}

void drawHourGlass()
{
  clearScreen(COLOR_PURPLE);
  drawTriangle(80, 68, 1, 30, 3, 1, 0, COLOR_BLACK);
  drawTriangle(80, 68, 1, 30, 3, 1, 1, COLOR_BLUE);
  drawTriangle(80, 68, 1, 30, 3, 1, 2, COLOR_RED);
  drawTriangle(80, 68, 1, 30, 3, 1, 3, COLOR_YELLOW);
}


void drawDonut()
{
  u_char rowBase = 60, colBase = 48; 
  drawBox(rowBase, colBase, 33, 33, 1, 1, COLOR_BROWN);
  drawBox(rowBase +12, colBase +12, 9, 9, 1, 1, COLOR_YELLOW);
  drawTriangle(rowBase +6, colBase + 3, 1, 3, 3, 1, 0, COLOR_CYAN);
  drawTriangle(rowBase + 6, colBase + 18, 1, 3, 3, 1, 3, COLOR_HOT_PINK);
  drawTriangle(rowBase + 6, colBase + 18, 1, 3, 3, 1, 1, COLOR_HOT_PINK);
  drawTriangle(rowBase + 9, colBase + 27, 1, 3, 3, 1, 0, COLOR_RED);
  drawTriangle(rowBase + 18, colBase + 6, 1, 3, 3, 1, 0, COLOR_GREEN);
  drawTriangle(rowBase + 18, colBase + 6, 1, 3, 3, 1, 2, COLOR_GREEN);
  drawTriangle(rowBase + 24, colBase + 27,1, 3, 3, 1, 2, COLOR_ORANGE);
  drawTriangle(rowBase + 30, colBase + 27,1, 3, 3, 1, 3, COLOR_ORANGE);
  drawTriangle(rowBase + 27, colBase + 9, 1, 4, 4, 1, 0, COLOR_HOT_PINK);
}

void drawJurrasicPark()
{
  u_char rowBase = 35, colBase = 33; 
  drawBox(rowBase, colBase + 33, 24, 21, 1, 1, COLOR_BLACK);
  drawBox(rowBase + 3, colBase + 42, 3, 3, 1, 1, COLOR_WHITE);
  drawBox(rowBase + 21, colBase +33, 9, 30, 1, 1, COLOR_BLACK);
  drawBox(rowBase + 60, colBase +9, 6, 3, 1, 1, COLOR_BLACK);
  drawBox(rowBase + 60, colBase + 21, 6, 3, 1, 1, COLOR_BLACK);
  drawTriangle(rowBase+36, colBase+48, 1, 6, 1, 1, 3, COLOR_BLACK);
  drawTriangle(rowBase+21, colBase+33, 1, 30, 1, 1, 2, COLOR_BLACK);
  drawTriangle(rowBase+63, colBase+9, 1, 12, 1, 1, 1, COLOR_BLACK);
  drawTriangle(rowBase+63, colBase+21, 1, 12, 1, 1, 1, COLOR_BLACK);

  drawString5x7(32, 12, "Welcome to", COLOR_YELLOW, COLOR_RED);
  drawString5x7( 25, rowBase + 80, "Jurrasic Park", COLOR_YELLOW, COLOR_RED);
}

void drawInstructions()
{
  u_char baseRow = 15, baseCol = 2; 
  clearScreen(COLOR_BLACK);
  drawString5x7(baseCol, baseRow, "Welcome to my LCD Toy", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(baseCol, baseRow + 20, "Button 1: Hourglass", COLOR_PURPLE, COLOR_BLACK);
  drawString5x7(baseCol, baseRow + 40, "Button 2: Donut", COLOR_YELLOW, COLOR_BLACK);
  drawString5x7(baseCol, baseRow + 60, "Button 3: Jurr. Park", COLOR_RED, COLOR_BLACK);
  drawString5x7(baseCol, baseRow + 80, "Button 4: Directions", COLOR_WHITE, COLOR_BLACK);
}
