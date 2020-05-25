#include "bishop.h"

using namespace std;

Bishop::Bishop(char c):Piece(c){}

char Bishop::getPiece(){
    if(this->getColour() == 'B'){
        return 'b';
    } else {
        return 'B';
    }
}

bool Bishop::isBlocked(string from, string to, Piece *board[8][8]){
    int fromRow = from[0] - 97;;
    int fromCol = 7 - (from[1] - 49);
    int toRow = to[0] - 97;
    int toCol = 7 - (to[1] - 49);

    if((fromRow > toRow) && (fromCol > toCol)){
        for(int i = fromRow, j = fromCol; i > toRow; --i, --j){
            if(board[j][i]->getPiece() != NULL){
                return true;
            }
        }
    } else if ((fromRow > toRow) && (fromCol < toCol)){
        for(int i = fromRow, j = fromCol; i < toRow; ++i, --j){
            if(board[j][i]->getPiece() != NULL){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol > toCol)){
        for(int i = fromRow, j = fromCol; i > toRow; --i, ++j){
            if(board[j][i]->getPiece() != NULL){
                return true;
            }
        }
    } else if ((fromRow < toRow) && (fromCol < toCol)){
        for(int i = fromRow, j = fromCol; i < toRow; ++i, -++){
            if(board[j][i]->getPiece() != NULL){
                return true;
            }
        }
    } else {
        return false;
    }
}

bool Bishop::validMove(string from, string to, Piece *board[8][8]){
    if(isBlocked(from, to, board) == true){
        return false;
    } else {
        return true;
    }
    
}
