//
//  gameManager.cpp
//  Hangman
//
//  Created by Timothy DenOuden on 11/27/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#include "gameManager.h"

GameManager::GameManager(Phrase* phrase) {
    bodyState = 0;
    guessedLetters = "";
    this->phrase = phrase;
}

int GameManager::getBodyState() const {
    return bodyState;
}

bool GameManager::isAlreadyGuessed(string guess) {
    for(int i = 0; i < guessedLetters.length(); i++) {
        if(guessedLetters[i] == guess[0]) {
            return true;
        }
    }
    return false;
}

bool GameManager::guessLetter(string letter) {
    if(phrase->guessCharacter(letter)) {
        return true;
    }
    guessedLetters.push_back(letter[0]);
    return false;
}

string GameManager::getGuessedLetters() const {
    return guessedLetters;
}

void GameManager::addToBodyState() {
    bodyState++;
}

void GameManager::printHangman() {
    cout << endl;
    cout << " ________" << endl;
    cout << " |      |" << endl;
    if(bodyState == 0) {
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 1) {
        cout << " |    (o_o)" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 2) {
        cout << " |    (o_o)" << endl;
        cout << " |      |" << endl;
        cout << " |      |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 3) {
        cout << " |    (o_o)" << endl;
        cout << " |     /|" << endl;
        cout << " |      |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 4) {
        cout << " |    (o_o)" << endl;
        cout << " |     /|\\" << endl;
        cout << " |      |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 5) {
        cout << " |    (o_o)" << endl;
        cout << " |     /|\\" << endl;
        cout << " |      |" << endl;
        cout << " |     /" << endl;
        cout << " |" << endl;
    }
    else if(bodyState == 6) {
        cout << " |    (x_x)" << endl;
        cout << " |     /|\\" << endl;
        cout << " |      |" << endl;
        cout << " |     / \\" << endl;
        cout << " |" << endl;
    }
    cout << "----------" << endl;
}

