#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>
#include <iostream>

class Bishop : public Piece {
public:
    Bishop (char){}
    ~Bishop(){};
    char getPiece() override;
    bool isBlocked(std::string, std::string, Piece* board[8]);
    bool validMove(std::string, std::string, Piece* board[8][8]) override;
};

#endif
