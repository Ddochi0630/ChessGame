//
//  Piece.cpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#include "Piece.hpp"
#include "exceptions.hpp"
#include <cstdlib>
#include "Chess.hpp"
char Piece::getColour() {
    return colour;
}

void Piece::setIsFirstMove(bool b){
       is_first_move = b;
   }

bool Piece::getIsFirstMove(){
    return is_first_move;
}
 
char Pawn::getPiece () {
    char c = this->getColour();
    if (c == 'B') {
        return 'p';
    } else if (c == 'W'){
        return 'P';
    } else {
        throw InvalidColour();
    }
}

bool Pawn::isBlocked(string from, string to, Piece *board[8][8]){
    int fromCol = convertCol(from[0]);
    int fromRow = convertRow(from[1]);
    int toCol = convertCol(to[0]);
    //int toRow = convertRow(to[1]);

 
    bool is_first = this->getIsFirstMove();
    if (is_first == false){
        return false;
    } else if (toCol - fromCol == 1){
        return false;
    } else {
        if(this->getColour() == 'B'){
            if (board[fromRow - 1][fromCol] != nullptr) {
                return true;
            } else {
                return false;
            }
        } else if (this->getColour() == 'W'){
            if (board[fromRow + 1][fromCol] != nullptr){
                return true;
            } else {
                return false;
            }
        } else {
            throw InvalidColour();
        }
    }
}

// if ((is_first == false) && (board[toRow][toCol] != nullptr))
bool Pawn::validMove(string from, string to, Piece* board[8][8]) {
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    bool is_first = this->getIsFirstMove();
    if (isInRange(fromCol, fromRow) || isInRange(toCol, toRow) || from == to){
        return false;
    }
    // first we determine if the piece is moving forward or diagonally.
    // if it is moving forward, and the destination grid contains a piece, then return false no matter what.
    if (getColour() == 'W') {
        if (fromCol == toCol) { // this is the moving straight case
            if (board[toRow][toCol] != nullptr){
                return false;
            }
            if (is_first == true) {
                if ((fromCol == toCol) && ((toRow - 2 == fromRow) || (toRow - 1 == fromRow))) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if ((fromCol == toCol) && (toRow - 1 == fromRow)){
                    //the nullptr in the if statement considered the case where there is a piece blocking the movement of Pawn
                    return true;
                } else {
                    return false;
                }
            }
        } else if ((fromRow - 1 == toRow) && ((fromCol - 1 == toCol) || (fromCol + 1 == toCol))) { //this is the moving diagonally case
            if ((board[toRow][toCol] != nullptr) && (board[toRow][toCol]->getColour() == 'B')){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if (getColour() == 'B') {
        if (fromCol == toCol){
            if (board[toRow][toCol] != nullptr){
                return false;
            } else if (is_first == true){
                if ((fromCol == toCol) && ((toRow + 2 == fromRow) || (toRow + 1 == fromRow))) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if ((fromCol == toCol) && (toRow + 1 == fromRow)){
                    return true;
                } else {
                    return false;
                }
            }
        } else if ((fromRow + 1 == toRow) && ((fromCol - 1 == toCol) || (fromCol + 1 == toCol))) {
            if ((board[toRow][toCol] != nullptr) && (board[toRow][toCol]->getColour() == 'W')) {
                return true;
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

char Rook::getPiece () {
    char c = this->getColour();
    if (c == 'B') {
        return 'r';
    } else if (c == 'W'){
        return 'R';
    } else {
        throw InvalidColour();
    }
}

bool Rook::isBlocked(string from, string to, Piece* board[8][8]){
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    
   if ((fromRow == toRow) && (fromCol > toCol)){ // up
        for(int i = fromRow, j = fromCol; j > toCol; --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow == toRow) && (fromCol < toCol)){ // down
        for(int i = fromRow, j = fromCol; j < toCol; ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow > toRow) && (fromCol == toCol)){ // right
        for(int i = fromRow, j = fromCol; i > toRow; --i){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow  < toRow) && (fromCol == toCol)){ // left
        for(int i = fromRow, j = fromCol; i < toRow; ++i){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } 
    return false;
}


bool Rook::validMove(string from, string to, Piece* board[8][8]){
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    
    if (isInRange(fromCol, fromRow) || isInRange(toCol, toRow)){
        return false;
    }
    
    // check there is same colour piece
    if((board[toCol][toRow] != nullptr) && (board[toCol][toRow]->getColour() == board[fromCol][fromRow]->getColour())){
        return false;
    }
    //first determin validity of path
    if(isBlocked(from, to, board)){
        if(from != to){
            if ((fromRow == toRow) && (fromCol != toCol)) {
                return true;
            } else if ((fromCol == toCol) && (fromRow != toRow)) {
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
}

char Bishop::getPiece(){
    char c = this->getColour();
    if (c == 'B') {
        return 'b';
    } else if (c == 'W'){
        return 'B';
    } else {
        throw InvalidColour();
    }
}

bool Bishop::isBlocked(string from, string to, Piece *board[8][8]){
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);

    if(abs(fromRow - toRow) != abs(fromCol - toCol)) return true;
    
    if((fromRow > toRow) && (fromCol > toCol)){
        for(int i = fromRow, j = fromCol; i > toRow; --i, --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow > toRow) && (fromCol < toCol)){
        for(int i = fromRow, j = fromCol; i < toRow; ++i, --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol > toCol)){
        for(int i = fromRow, j = fromCol; i > toRow; --i, ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol < toCol)){
        for(int i = fromRow, j = fromCol; i < toRow; ++i, ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    }
    return false;
}

bool Bishop::validMove(string from, string to, Piece *board[8][8]){
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    
    if(isBlocked(from, to, board) == false){
        if(abs(fromCol - toCol) == abs(fromRow - toRow)){ // diagonal direction
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

char King::getPiece(){
    char c = this->getColour();
    if (c == 'B') {
        return 'k';
    } else if (c == 'W'){
        return 'K';
    } else {
        throw InvalidColour();
    }
}

bool Piece::isCheck(string from, Piece* board[8][8]){
    for (int i = 0; i < 8; ++i) {
           for (int j = 0; j < 8; ++j){
               string loc = convertToStrLoc(i, j);
               if ((board[i][j] != nullptr) && (board[i][j]->getColour() != getColour()) && (board[i][j]->validMove(loc, from, board))) {
                   return true;
               }
           }
       }
       return false;
}

bool King::validMove(string from, string to, Piece* board[8][8]){
    
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);

    if (isInRange(fromCol, fromRow) || isInRange(toCol, toRow)){
        return false;
    }

    // there is already a same colour piece
    
    if((board[toCol][toRow] == nullptr) && (board[toCol][toRow]->getColour() == board[fromCol][fromRow]->getColour())){
        return false;
    }
    //check if it is possibily a castling move
    if(fromRow == toRow && abs(fromCol - toCol) == 2){
        if (getColour() == 'B') {
            if ((isCheck(from, board) == false) && isCheck("a8", board) == false) {
                if (board[0][0]->getIsFirstMove() == true && board[0][3]->getIsFirstMove() == true){
                    if (board[0][1] == nullptr && board[0][2] == nullptr) {
                        isCastle = true;
                        return true;
                    }
                }
            } else if ((isCheck(from, board) == false) && isCheck("h8", board) == false) {
                if (board[0][7]->getIsFirstMove() == true && board[0][3]->getIsFirstMove() == true) {
                    if (board[0][4] == nullptr && board[0][5] == nullptr && board[0][6] == nullptr){
                        isCastle = true;
                        return true;
                    }
                }
            }
        } else if (getColour() == 'W') {
            if ((isCheck(from, board) == false) && isCheck("a1", board) == false) {
                if (board[7][0]->getIsFirstMove() == true && board[7][3]->getIsFirstMove() == true){
                    if (board[7][1] == nullptr && board[7][2] == nullptr) {
                        isCastle = true;
                        return true;
                    }
                }
            } else if ((isCheck(from, board) == false) && isCheck("h1", board) == false) {
                if (board[7][7]->getIsFirstMove() == true && board[7][3]->getIsFirstMove() == true) {
                    if (board[7][4] == nullptr && board[7][5] == nullptr && board[7][6] == nullptr){
                        isCastle = true;
                        return true;
                    }
                }
            }
        }
    }

    //regular moves
    // case 1: moving vertically by 1 grid
    if((fromCol == toCol) && (abs(fromRow-toRow) == 1)) {
        return true;
    } else if ((fromRow == toRow) && (abs(fromCol-toCol) == 1)) { // case 2: moving horizontally by 1 grid
        return true;
    } else if ((fromRow + 1 == toRow) && ((fromCol - 1 == toCol) || (fromCol + 1 == toCol))) { //diagonally upwards by 1 grid
        return true;
    } else if ((fromRow - 1 == toRow) && ((fromCol - 1 == toCol) || (fromCol + 1 == toCol))) {
        return true;
    } else {
        return false;
    }
}

char Queen::getPiece(){
    char c = this->getColour();
    if (c == 'B') {
        return 'q';
    } else if (c == 'W'){
        return 'Q';
    } else {
        throw InvalidColour();
    }
}

void Piece::castle(string from, string to, Piece * board[8][8]) {
    int fromRow = convertRow(from[1]);
    int fromCol = convertCol(from[0]);
    int toRow = convertRow(to[1]);
    int toCol = convertCol(to[0]);
    Piece * fromGrid = board[fromRow][fromCol];
    //Piece * toGrid = board[toRow][toCol];
    if (toCol < fromCol){
        board[toRow][toCol] = fromGrid;
        board[fromRow][fromCol] = nullptr;
        //move rook
        board[toRow][3] = board[toRow][0];
        board[toRow][0] = nullptr;
    } else {
        board[toRow][toCol] = fromGrid;
        board[fromRow][fromCol] = nullptr;
        board[toRow][5] = board[toRow][7];
        board[toRow][7] = nullptr;
    }
}


bool Queen::isBlocked(string from, string to, Piece* board[8][8]){
    
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    
    
    // up right
    if((fromRow > toRow) && (fromCol > toCol)){
        for(int i = fromRow, j = fromCol; i > toRow; --i, --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow > toRow) && (fromCol < toCol)){  // down right
        for(int i = fromRow, j = fromCol; i < toRow; ++i, --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol > toCol)){ // up left
        for(int i = fromRow, j = fromCol; i > toRow; --i, ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol < toCol)){ // down left
        for(int i = fromRow, j = fromCol; i < toRow; ++i, ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow == toRow) && (fromCol > toCol)){ // up
        for(int i = fromRow, j = fromCol; j > toCol; --j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow == toRow) && (fromCol < toCol)){ // down
        for(int i = fromRow, j = fromCol; j < toCol; ++j){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow > toRow) && (fromCol == toCol)){ // right
        for(int i = fromRow, j = fromCol; i > toRow; --i){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } else if ((fromRow  < toRow) && (fromCol == toCol)){ // left
        for(int i = fromRow, j = fromCol; j < toRow; --i){
            if(board[j][i] != nullptr){
                return true;
            }
        }
    } 
    return false;
}

bool Queen::validMove(string from, string to, Piece* board[8][8]){
    int fromCol = convertCol(from[1]);
    int fromRow = convertRow(from[0]);
    int toCol = convertCol(to[1]);
    int toRow = convertRow(to[0]);
    
    if (isInRange(fromCol, fromRow) || isInRange(toCol, toRow)){
        return false;
    }
    
    // check there is same colour piece

    if((board[toCol][toRow] != nullptr) && (board[toCol][toRow]->getColour() == board[fromCol][fromRow]->getColour())){
        return false;
    }
    
    if(isBlocked(from, to, board) == false){
        if(abs(fromCol - toCol) == abs(fromRow - toRow)){ // diagonal direction
            return true;
        } else if(fromCol == toCol){ // horizantal
            return true;
        } else if(fromRow == toRow){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

char Knight::getPiece(){
    char c = this->getColour();
    if (c == 'B') {
        return 'n';
    } else if (c == 'W'){
        return 'N';
    } else {
        throw InvalidColour();
    }
}

bool Knight::validMove(string from, string to, Piece* board[8][8]){
 
    int fromCol = convertCol(from[0]);
    int fromRow = convertRow(from[1]);
    int toCol = convertCol(to[0]);
    int toRow = convertRow(to[1]);
 
    int rowDiff = abs(fromRow - toRow);
    int colDiff = abs(fromCol - toCol);

    if (isInRange(fromCol, fromRow) || isInRange(toCol, toRow)){
        return false;
    }

    // check there is same colour piece

    if((board[toCol][toRow] != nullptr) && (board[toCol][toRow]->getColour() == board[fromCol][fromRow]->getColour())){
        return false;
    }

    if(rowDiff == 2 && colDiff == 1){
        return true;
    } else if(rowDiff == 1 && colDiff == 2){
        return true;
    } else {
        return false;
    }
    
}
