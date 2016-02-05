//
//  main.cpp
//  Hangman
//
//  Created by Timothy DenOuden on 11/26/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "string"

using namespace std;

#include "dictionary.h"
#include "gameManager.h"

const string BLANK = "";
const string ENTER_GUESS = "Enter lowercase letter to guess enter \"i give up\" to end game";
const string ALREADY_GUESSED = "You already guessed that letter!";

int main()
{
    cout << "=========================================" << endl;
    cout << "= #  #  ##  #   #  ### #   #  ##  #   # =" << endl;
    cout << "= #  # #  # ##  # #    ## ## #  # ##  # =" << endl;
    cout << "= #### #### # # # # ## # # # #### # # # =" << endl;
    cout << "= #  # #  # #  ## #  # #   # #  # #  ## =" << endl;
    cout << "= #  # #  # #   #  ##  #   # #  # #   # =" << endl;
    cout << "=========================================" << endl;
    cout << "Please enter a lower case phrase to guess \nex: \"the cake is a lie\"" << endl;
    string desiredPhrase;
    getline(cin, desiredPhrase);
    Phrase* phrase = new Phrase(desiredPhrase);
    GameManager* manager = new GameManager(phrase);
    string guess;
    string message = BLANK;
    bool running = true;
    bool winning = false;
    int turnCount = 0;
    while(running) {
        for(int i = 0; i < 50; i++) {
            cout << "\n";
        }
        manager->printHangman();
        turnCount++;
        cout << "Guessed letters: " << manager->getGuessedLetters() << endl;
        cout << phrase->getHiddenString() << endl;
        cout << message << endl;
        cout << ENTER_GUESS << endl;
        getline(cin, guess);
        if(guess.length() == 1) {
            if(manager->isAlreadyGuessed(guess)) {
                message = ALREADY_GUESSED;
            }
            else {
                if(!manager->guessLetter(guess)) {
                    manager->addToBodyState();
                }
            }
        }
        else if(guess.length() > 1) {
            if(guess == "i give up") {
                running = false;
            }
            else if(guess == phrase->getFullString()) {
                running = false;
                winning = true;
            }
        }
        if(phrase->getFullString() == phrase->getHiddenString()) {
            running = false;
            winning = true;
        }
        if(manager->getBodyState() > 5) {
            running = false;
        }
    }
    for(int i = 0; i < 50; i++) {
        cout << "\n";
    }
    if(winning) {
    cout << "===================================" << endl;
    cout << "= #   # # #   # #   # #### ####   =" << endl;
    cout << "= #   # # ##  # ##  # #    #   #  =" << endl;
    cout << "= #   # # # # # # # # ###  ####  =" << endl;
    cout << "= # # # # #  ## #  ## #    #  #   =" << endl;
    cout << "=  # #  # #   # #   # #### #   #  =" << endl;
    cout << "===================================" << endl;
        cout << "You win! It only took you " << turnCount << " guesses!" << endl;
    }
    else {
        manager->printHangman();
        cout << "   R.I.P." << endl;
        cout << "It was a good try! The prase was: " << phrase->getFullString() << endl;
    }
    system("PAUSE");
    return 0;
}
