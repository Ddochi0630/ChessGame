
//  Board.hpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "Piece.hpp"
class Board {
    Piece* board[8][8];
    char currentPlayer;
    // we also need to add a getter and setter for the private members above
public:
    //constructor initializes each element of board to nullptr
    Board();
    //destructor deallocates dynamically allocated memory
    //this might be changed later as I'm currently thinking how to do setup required by this assignment
    ~Board();

    // deAlloc is a helper function to deallocate dynamically allocated memory
    void deAlloc(); 
    // setNull is a helper function to set all elements of board to nullptr
    void setNull(); 

    // prints the board according to project specification
    void printBoard();
    
    //methods needed for setting up the board.
    
    // defaultSetup sets up the board as a standard chess game
    void defaultSetup();
    
    // addPiece adds a piece to the board
    void addPiece(char p, string location);
    
    // removePiece removes a piece from the board
    void removePiece(string location);

    void setTurn(char c);

    auto getPiece () {
        return board;
    }

    void switchTurn();
    
    bool isOver(Piece * board[8][8]);
    
    void makeMove(string from, string to, Piece * board[8][8]);
    
};
#endif /* Board_hpp */
