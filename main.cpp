//
//  main.cpp
//  cs246FinalProject
//
//  Created by 许千珣 on 2020-04-13.
//  Copyright © 2020 许千珣. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include "Chess.hpp"
#include "Piece.hpp"
#include <string>
#include "exceptions.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Chess newGame;
    string cmd;
    
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "setup") {
                string action;
                while (true){
                    cin >> action;
                    if (action == "+")
                    {
                        string piece;
                        string location;
                        cin >> piece >> location;
                        // add piece to that location
                    } else if (action == "-") {
                        string location;
                        cin >> location;
                        // remove piece from that location
                    } else if (action == "=") {
                        char c;
                        cin >> c;
                        // make this colours turn to go next
                    } else if (action == "done") {
                        //check if every condition is met before break
                        // Upon completion of setup mode, you must verify that the board contains exactly one white
                        // king and exactly one black king; that no pawns are on the first or last row of the board; and
                        // that neither king is in check. The user cannot leave setup mode until these conditions are
                        //satisfied.


                        // should the above be a method or just code written here?
                        break;
                    } else {
                        throw UnknownCommand();
                    }
                }
            } else if (cmd == "game"){
                string identity1; // can be human or computer
                string identity2;
                cin >> identity1 >> identity2;
                // do something here (not sure what to do yet)
            } else if (cmd == "resign") {
                // do something to end the game and make the oppenent win
                
            } else if (cmd == "move") {
                //make a valid move
                // must check whose turn it is before making a move
            } else {
                throw UnknownCommand();
            }
        }
    } catch (ios::failure &) {}
    catch (UnknownCommand uc) {
        cout <<"command entered is not valid."<<endl;
    }
    catch (InvalidColour ic) {
    }
}