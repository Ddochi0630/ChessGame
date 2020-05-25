//
//  Chess.hpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#ifndef Chess_hpp
#define Chess_hpp

#include <stdio.h>
#include "Board.hpp"
class Chess : public Board {
    Board myBoard;
    char currentPlayer;
public:
    // switchTurn changes currentPlayer's value from B to W or vice versa
    void switchTurn();
    // isCheck returns true if any pieces from the oppnent's side can take the king, false otherwise
    bool isCheck(char c);
    // canMove returns true if this player has at least one piece that can make a valid move, false otherwise
    bool canMove(char c);
    // kind of tricky, can implement this last
    //bool canCastle(char c);
    // makeMove makes a move and updates the board
    void makeMove(string from, string to, Piece * board[8][8]);
    // isOver returns true when the game is over and displays message
    bool isOver();
    // setTurn makes c to go next
    // void setTurn (char c);
    // bool isCheckAtPosn(char c, int row, int col);
};
#endif /* Chess_hpp */
