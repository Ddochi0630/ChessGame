//
//  exceptions.cpp
//  chess
//
//  Created by 许千珣 on 2020-04-12.
//  Copyright © 2020 许千珣. All rights reserved.
//

#include "exceptions.hpp"
#include <string>

int convertCol (char col) {
    if (col == 'a'){
        return 0;
    } else if (col == 'b'){
        return 1;
    } else if (col == 'c'){
        return 2;
    } else if (col == 'd') {
        return 3;
    } else if (col == 'e'){
        return 4;
    } else if (col == 'f'){
        return 5;
    } else if (col == 'g'){
        return 6;
    } else if (col == 'h') {
        return 7;
    } else {
        throw InvalidColumn();
    }
}

int convertRow (char row) {
    if (row == '8'){
        return 0;
    } else if (row == '7'){
        return 1;
    } else if (row == '6'){
        return 2;
    } else if (row == '5') {
        return 3;
    } else if (row == '4'){
        return 4;
    } else if (row == '3'){
        return 5;
    } else if (row == '2'){
        return 6;
    } else if (row == '1') {
        return 7;
    } else {
        throw InvalidRow();
    }
}
    
bool isInRange(int col, int row) {
    if (col > 8 || row > 8) {
        return false;
    }
    return true;
}

std::string convertToStrLoc(int row, int col){
    std::string r;
    std::string c;
    if (row == 0){
        r = "8";
    } else if (row == 1) {
        r = "7";
    } else if (row == 2) {
        r = "6";
    } else if (row == 3) {
        r = "5";
    } else if (row == 4) {
        r = "4";
    } else if (row == 5) {
        r = "3";
    } else if (row == 6) {
        r = "2";
    } else if (row == 7) {
        r = "1";
    } else {
        throw InvalidRow();
    }
    if (col == 0){
        c = "a";
    } else if (col == 1) {
        c = "b";
    } else if (col == 2) {
        c = "c";
    } else if (col == 3) {
        c = "d";
    } else if (col == 4) {
        c = "e";
    } else if (col == 5) {
        c = "f";
    } else if (col == 6) {
        c = "g";
    } else if (col == 7) {
        c = "h";
    } else {
        throw InvalidRow();
    }
    return c+r;
}
