//
//  Board.cpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
#include "exceptions.hpp"
using namespace std;
//constructor initializes each element of board to nullptr
Board::Board()
{
setNull();
}

//destructor deallocates dynamically allocated memory
//this might be changed later as I'm currently thinking how to do setup required by this assignment
Board::~Board()
{
deAlloc();
}

// deAlloc is a helper function to deallocate dynamically allocated memory
void Board::deAlloc(){ 
	for (int i = 0; i < 8; i++) 
    { 
        for (int j = 0; j < 8; j++) 
        { 
        	delete board[i][j];
        } 
    } 
}
// setNull is a helper function to set all elements of board to nullptr
void Board::setNull(){
	for (int i = 0; i < 8; i++) 
    { 
        for (int j = 0; j < 8; j++) 
        { 
            board[i][j] = nullptr; 
        }
    } 
}

// prints the board according to project specification
void Board::printBoard(){
    // output each array element's value
    int k = 8;
    for (int i = 0; i < 8; i++) 
    { 
        for (int j = 0; j < 8; j++)
        { 
            cout << k << " "; 
            // check if nullptr
            if (board[i][j] == nullptr) {
            	// check position on board for white or black squares. if col and row are both even or both odd, then white square
            	if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0))) {
            		cout << " ";
            	} else {
                    cout << "_";
            	}
            } else { // Piece is an abstract class
            	cout << board[i][j]->getPiece(); 
            	k--;
        	}
    	}
    	cout << endl;
	}
}

    
//methods needed for setting up the board.

// defaultSetup sets up the board as a standard chess game
void Board::defaultSetup(){
	// Deallocate memory and set whole board to nullptr first
	deAlloc();
	setNull();
	// Placing Black pieces
	for (int col = 0; col < 8; col++) 
	{
        board[6][col] = new Pawn('B');
	}
	board[7][0] = new Rook('B');
	board[7][1] = new Knight('B');
	board[7][2] = new Bishop('B');
	board[7][3] = new Queen('B');
	board[7][4] = new King('B');
	board[7][5] = new Bishop('B');
	board[7][6] = new Knight('B');
	board[7][7] = new Rook('B');

	// Placing White pieces
	for (int col = 0; col < 8; col++) 
	{
        board[1][col] = new Pawn('W');
	}
	board[0][0] = new Rook('W');
	board[0][1] = new Knight('W');
	board[0][2] = new Bishop('W');
	board[0][3] = new Queen('W');
	board[0][4] = new King('W');
	board[0][5] = new Bishop('W');
	board[0][6] = new Knight('W');
	board[0][7] = new Rook('W');
}



// removePiece removes a piece from the board
void Board::removePiece(string location){
	// removePiece should deallocate the one Piece from the board
	int col = convertCol(location[0]);
	int row = convertRow(location[1]);
	delete board[row][col];
	board[row][col] = nullptr;
	printBoard();
}

// addPiece adds a piece to the board
void Board::addPiece(char p, string location){
    // first get the location from string
    int col = convertCol(location[0]);
    int row = convertRow(location[1]);

    // next check if space we're adding piece is empty or not
    if (board[row][col] != nullptr) {
        removePiece(location);
    }
    if (p == 'K') {board[row][col] = new King('W');}
    else if (p == 'k') {board[row][col] = new King('B');}
    else if (p == 'R') {board[row][col] = new Rook('W');}
    else if (p == 'r') {board[row][col] = new Rook('B');}
    else if (p == 'N') {board[row][col] = new Knight('W');}
    else if (p == 'n') {board[row][col] = new Knight('B');}
    else if (p == 'B') {board[row][col] = new Bishop('W');}
    else if (p == 'b') {board[row][col] = new Bishop('B');}
    else if (p == 'Q') {board[row][col] = new Queen('W');}
    else if (p == 'q') {board[row][col] = new Queen('B');}
    else if (p == 'P') {board[row][col] = new Pawn('W');}
    else if (p == 'p') {board[row][col] = new Pawn('B');}
    else { // invalid piece
        throw InvalidPiece();
    }
    // do something if the user inputs an invalid piece or location?
    

    // print board at the end
    printBoard();
}

// setTurn 
void Board::setTurn(char c){
    currentPlayer = c;
}

void Board::switchTurn() {
    if (currentPlayer == 'W'){
        currentPlayer = 'B';
    } else if (currentPlayer == 'B') {
        currentPlayer = 'W';
    } else {
        throw InvalidColour();
    }
}
void Board::makeMove(string from, string to, Piece * board[8][8]){
    int fromRow = convertRow(from[1]);
    int fromCol = convertCol(from[0]);
    int toRow = convertRow(to[1]);
    int toCol = convertCol(to[0]);
    Piece * fromGrid = board[fromRow][fromCol];
    Piece * toGrid = board[toRow][toCol];
    if (fromGrid->validMove(from, to, board) && fromGrid->isBlocked(from, to, board) == false){
        // determine the castling move
        if (fromGrid->getPiece() == 'K' || fromGrid->getPiece() == 'k'){
            if (fromGrid->getIsCastle() == true){
                fromGrid->castle(from, to, board);
            }
        } else if (toGrid == nullptr) {
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = nullptr;
        } else {
            delete board[toRow][toCol];
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = nullptr;
        }
    } else {
        throw InvalidMove();
    }
}


bool Board::isOver(Piece * board[8][8]){
  
}
