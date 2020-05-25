//
//  exceptions.hpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#ifndef exceptions_hpp
#define exceptions_hpp

#include <stdio.h>

class UnknownCommand {};

class InvalidColour {};

class InvalidColumn {};

class InvalidRow {};

class InvalidMove {};

class InvalidPiece {};

int convertCol (char col);
bool isInRange(int col, int row);
int convertRow(char row);
string convertToStrLoc(int, int);
#endif /* exceptions_hpp */
