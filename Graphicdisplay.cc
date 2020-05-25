#include "Graphicdisplay.h"
#include <iostream>

using namespace std;

GraphicDisplay::GraphicDisplay(Xwindow &xx):x{xx}, myBoard{}{
    
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
                if((i ==0) || (i == 9) || (j ==0) || (j == 9)) continue;
                if((i+j) % 2 == 0){
                int tileLength = 500 / 10;
                int x = (tileLength * i);
                int y = 500 - (tileLength * j);
                int width = tileLength;
                int colour = (i + j) % 2 ? 1:0;
                w.fillRectangle(x, y-tileLength, width, width, colour);
                }
        }
    }

  w.drawBigString(20, 87, "8",0);
  w.drawBigString(20, 137, "7",0);
  w.drawBigString(20, 187, "6",0);
  w.drawBigString(20, 237, "5",0);
  w.drawBigString(20, 287, "4",0);
  w.drawBigString(20, 337, "3",0);
  w.drawBigString(20, 387, "2",0);
  w.drawBigString(20, 437, "1",0);

  w.drawBigString(63, 480, "a",0);
  w.drawBigString(113, 480, "b",0);
  w.drawBigString(163, 480, "c",0);
  w.drawBigString(213, 480, "d",0);
  w.drawBigString(263, 480, "e",0);
  w.drawBigString(313, 480, "f",0);
  w.drawBigString(363, 480, "g",0);
  w.drawBigString(413, 480, "h",0);

}

GraphicDisplay::GraphicDisplay(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            delete myBoard[j][i];
        }
    }
    delete myBoard;
}

void GraphicDisplay::welcomeMessage(Xwindow &x){
    w.drawStringFont(110,150, "Welcome to the Chess Game!", "-adobe-times-bold-i-normal--25-180-100-100-p-128-iso8859-15", 1);
    w.drawStringFont(130,190, "Please enter any command", "-adobe-times-bold-i-normal--25-180-100-100-p-128-iso8859-15", 1);
    w.drawStringFont(205,230, "To start!!", "-adobe-times-bold-i-normal--25-180-100-100-p-128-iso8859-15", 1);*/

}

void GraphisDisplay::graphicPiece(Piece *p[8][8], Xwindow &x){
    int colour = (p.getColour() == 'W')? 0 : 1;
     for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            string s = string(1, p[j][i]->getPiece());
            int tileLength = 500/10;
            int x = (tileLength * i) + 65;
            int y = (tileLength * j) + 80;
            x.drawBigString(x, y, s, colour);
        }
  }
}
