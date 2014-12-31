/*
  RUN.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 This is Nicole's latest version (Dec. 30).
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

// INITIALIZE

int mazeArray[24][24] =
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  // LEFT edgecof maze
  {0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1},
  {0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,5,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1},
  {1,0,5,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//  <-- BOTTOM             TOP ---->
  {0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1},
  {0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,1},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0},
  {0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1},
  {1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,1}  //RIGHT edge of maze
};

int offsetX = 1;
int offsetY = 1;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();    // Required code, line 2 of 2.
  Serial.begin(9600); 
}

// Global variables go here...

/*
Point mazeArray[21row][21column] =
{
  {#,#<#...#},
  {#,#...
}
*/



// below: DrawPx (x,y,screen[x][y]}
/*
for (int i = 0; i < 576; i++)
{
  if (mazeArray[i].x >= 0 &&
      mazeArray[i].x <= 7 &&
      mazeArray[i].y >= 0 &&
      mazeArray[i].y <= 7)
  {
    DrawPx(mazeArray[i].x, mazeArray[i].y, Green);
  }
}
*/






void loop()                     // run over and over again
{ 
  ClearSlate();
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      int x = i + offsetX;
      int y = j + offsetY;
      
      int drawColor = 0;
      if (x < 24 && x > 0 && 
          y < 24 && y > 0)
          {
            drawColor = mazeArray[x][y];
          }
      DrawPx(i,j, drawColor);
    }
  }
  DrawPx(2,2,Yellow);  // draw PLAYER over background
  DisplaySlate();
  
  CheckButtonsPress();
  
  if (Button_Right)
  {
    if (offsetX < 22)
      offsetX++;
  }
  if (Button_Left)
  {
    if (offsetX > -2)
      offsetX--;
  }
  if (Button_Up)
  {
    if (offsetY < 22)
      offsetY++;
  }
  if (Button_Down)
  {
    if (offsetY > -2)
      offsetY--;
  }
}
