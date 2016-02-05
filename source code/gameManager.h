//
//  gameManager.h
//  Hangman
//
//  Created by Timothy DenOuden on 11/26/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#ifndef Hangman_gameManager_h
#define Hangman_gameManager_h

#include <iostream>
#include "phrase.h"

class GameManager {
public:
    //constructs game manager and the length of the giraffe neck and assigns the phrase to be guessed
    GameManager(Phrase* phrase);
    
    //returns the state of the hangman
    int getBodyState() const;
    
    //returns the already guessed letters
    string getGuessedLetters() const;
    
    //returns true if the letter of the guess was already guessed
    bool isAlreadyGuessed(string guess);
    
    //tests the phrase to see if the letter is in the phrase assuming the letter is not already guessed
    bool guessLetter(string letter);
    
    //add a segment of the body lowering the health
    void addToBodyState();
    
    //prints hangman graphic
    void printHangman();
private:
    //phrase that the user is to guess
    Phrase* phrase;
    
    //a string containing all of the previously guessed letters
    string guessedLetters;
    
    //the health of the hangman
    int bodyState;
};

#endif
