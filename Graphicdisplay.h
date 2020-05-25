#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include "window.h"
#include "Board.h"

class GraphicsDisplay : Public Board {
    Xwindow &x;
    Board myBoard;
    public :
        GraphicsDisplay(Xwindow &x);
        ~GraphicDisplay();
        void welcomeMessage(Xwindow &);
        void graphicPiece(Piece, Xwindow &);
};

#endif



