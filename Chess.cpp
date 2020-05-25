//
//  Chess.cpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#include "Chess.hpp"
#include "exceptions.hpp"
#include <string>
#include "Piece.hpp"
using namespace std;


void Chess::switchTurn() {
    if (currentPlayer == 'W'){
        currentPlayer = 'B';
    } else if (currentPlayer == 'B') {
        currentPlayer = 'W';
    } else {
        throw InvalidColour();
    }
}

/*
bool Chess::isCheck(char c) {
    int kingRow = 0;
    int kingCol = 0;
    auto board = this->myBoard.getPiece();
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((board[i][j] != nullptr) && (board[i][j]->getColour() == c) && ((board[i][j]->getPiece() == 'K') || (board[i][j]->getPiece() == 'k'))) {
                kingRow = i;
                kingCol = j;
                //the king is found on the board;
                
            }
        }
    }
    string kingLoc = convertToStrLoc(kingRow, kingCol);
    //check opponent pieces and see if king is in check
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j){
            string loc = convertToStrLoc(i, j);
            if ((board[i][j] != nullptr) && (board[i][j]->getColour() != c) && (board[i][j]->validMove(loc, kingLoc, board))) {
                return true;
            }
        }
    }
    return false;
}
bool Chess::isCheckAtPosn(char c, int row, int col) {
    string loc = convertToStrLoc(row, col);
    auto board = this->myBoard.getPiece();
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; ++j) {
            string currentLoc = convertToStrLoc(i, j);
            if ((board[i][j] != nullptr) && (board[i][j]->getColour() != c) && (board[i][j]->validMove(currentLoc, loc, board))) {
                return true;
            }
        }
    }
    return false;
}

bool Chess::canCastle(char c) {
    auto board = this->myBoard.getPiece();
    if (c == 'B') {
        if ((isCheck(c) == false) && isCheckAtPosn(c, 0, 0) == false) {
            if (board[0][0]->getIsFirstMove() == true && board[0][3]->getIsFirstMove() == true){
                if (board[0][1] == nullptr && board[0][2] == nullptr) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if((isCheck(c) == false) && isCheckAtPosn(c, 0, 7) == false) {
            if (board[0][7]->getIsFirstMove() == true && board[0][3]->getIsFirstMove() == true) {
                if (board[0][4] == nullptr && board[0][5] == nullptr && board[0][6] == nullptr){
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if (c == 'W'){
        if (isCheck(c) == false && isCheckAtPosn(c, 7, 0) == false) {
            if (board[7][0]->getIsFirstMove() == true && board[7][3]->getIsFirstMove() == true){
                if (board[7][1] == nullptr && board[7][2] == nullptr) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if (isCheck(c) == false && isCheckAtPosn(c, 7, 7) == false){
            if (board[7][7]->getIsFirstMove() == true && board[7][3]->getIsFirstMove() == true){
                if (board[7][4] == nullptr && board[7][5] == nullptr && board[7][6] == nullptr) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        throw InvalidColour();
    }
}
*/
