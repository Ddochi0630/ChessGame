//
//  Piece.hpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Piece {
    char colour; //the colour of the current piece, can only be black or white
    bool is_first_move = true;
    bool isCastle = false;
public:
     
    //constructor
    Piece(char colour) : colour(colour) {}
    //default destructor
    virtual ~Piece() = 0;
    // getter and setter for is_first_move
    void setIsFirstMove(bool b);
    bool getIsFirstMove();
    //getPiece is a pure virtual method and will be implemented by each subclass
    // returns the letter representation of each piece. Upper case letter for white and Lower case Letter for black
    // R/r = Rook
    // N/n = Knight
    // B/b = Bishop
    // Q/q = Queen
    // K/k = King
    // P/p = Pawn
    virtual char getPiece() = 0;
    
    //getColour returns the colour of this piece.
    char getColour();
    
    // validMove returns true if this piece is making a valid move, false otherwise.
    // validMove occurs when source row/col and destination row/col is in range, the movement is allowed by that specific piece, and there is no other pieces in between (except for knight).
    virtual bool validMove (string from, string to, Piece* board[8][8]) = 0;
    virtual bool isBlocked (string from, string to, Piece * board[8][8]) = 0;
    bool getIsCastle () { return isCastle;}
    void setIsCastle (char is) {isCastle = is;}
    bool isCheck(string, Piece* board[8][8]);
    void castle(string, string, Piece * board[8][8]);
};

class Pawn : public Piece {
public:
    //Pawn's constructor calls it's parent constructor
    Pawn (char colour) : Piece(colour) {
    }
    //default destructor
    ~Pawn() override {}
    
    char getPiece () override;
    bool validMove(string, string, Piece* board[8][8]) override;
    bool isBlocked (string from, string to, Piece * board[8][8]) override;
};

class Rook : public Piece {
public:
    //constructor
    Rook (char colour) : Piece(colour) {}
    //destructor
    ~Rook()override{}
    char getPiece () override;
    bool validMove(string, string, Piece* board[8][8]) override;
    bool isBlocked (string from, string to, Piece * board[8][8]) override;
};

class Knight : public Piece {
public:
    Knight (char colour) : Piece(colour) {}
    ~Knight()override{};
    char getPiece () override;
    bool validMove(string, string, Piece* board[8][8]) override;
    bool isBlocked (string from, string to, Piece * board[8][8]) override;
};

class Bishop : public Piece {
public:
    Bishop (char colour) : Piece(colour) {}
    ~Bishop()override{};
    char getPiece() override;
    bool isBlocked(string, string, Piece* board[8][8]) override;
    bool validMove(string, string, Piece* board[8][8]) override;
};

class Queen : public Piece {
public:
    Queen (char colour) : Piece(colour) {}
    ~Queen()override{};
    char getPiece() override;
    bool validMove(string,string, Piece* board[8][8]) override;
    bool isBlocked (string from, string to, Piece * board[8][8]) override;
};

class King : public Piece {
    bool isCastle = false;
public:
    King (char colour) : Piece(colour) {}
    ~King()override{};
    char getPiece() override;
    bool validMove(string, string, Piece* board[8][8]) override;
    bool isBlocked (string from, string to, Piece * board[8][8]) override;
    bool getIsCaslte() {return isCastle;}
    void setIsCastle(bool c) {isCastle = c;}
    bool canCastle();
    //bool isCheck(string, Piece* board[8][8]);
    //void castle(string, string, Piece * board[8][8]);
};
#endif /* Piece_hpp */
