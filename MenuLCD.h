/*
 Arduino_LCD_Menu Library
Copyright Dustin Andrews, David Andrews 2012 
Licensed under the follwing license:

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
following conditions are met:
Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
in the documentation and/or other materials provided with the distribution. 
The name of the author may not be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <LiquidCrystal_I2C.h>

#ifndef MenuLCD_H

#define MenuLCD_H 1
class MenuLCD
{
  public:
  MenuLCD(int LCDADDR, int characters, int lines);
  bool MenuLCDSetup();
  bool PrintMenu( char ** pString, int nLines, int nSelectedLine /*= 0*/ );
  bool PrintLineRight( char* pString, int iRow );
  bool PrintLine( char* pString, int iRow );
  int getLines();
  int getCharacters();
  void ClearLCD();
  LiquidCrystal_I2C * getLCD();

  enum Direction{ LEFT, RIGHT };


  void WipeMenu( char* pString[], int nLines, MenuLCD::Direction dir );

  
  private:
  LiquidCrystal_I2C* m_pLCD;
  int m_LCDADDR;
  int m_characters;
  int m_lines;
};

#endif
