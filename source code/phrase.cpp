//
//  phrase.cpp
//  Hangman
//
//  Created by Timothy DenOuden on 11/26/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#include "phrase.h"

Phrase::Phrase(string phraseString) {
    fullPhrase = phraseString;
    for(int i = 0; i < fullPhrase.length(); i++) {
        if(fullPhrase[i] == ' ') {
            hiddenPhrase.push_back(' ');
        }
        else {
            hiddenPhrase.push_back('_');
        }
    }
}

string Phrase::getFullString() const {
    return fullPhrase;
}

string Phrase::getHiddenString() const {
    return hiddenPhrase;
}

bool Phrase::guessCharacter(string charGuess) {
    string tempPhrase = "";
    int count = 0;
    for(int i = 0; i < fullPhrase.length(); i++) {
        if(fullPhrase[i] == charGuess[0]) {
            tempPhrase.push_back(charGuess[0]);
            count++;
        }
        else {
            tempPhrase.push_back(hiddenPhrase[i]);
        }
    }
    hiddenPhrase = tempPhrase;
    if(count > 0) {
        return true;
    }
    return false;
}