//
//  Phrase.h
//  Hangman
//
//  Created by Timothy DenOuden on 11/26/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#ifndef Hangman_Phrase_h
#define Hangman_Phrase_h

#include <string>

using namespace std;

class Phrase {
public:
    Phrase(string phraseString);
    string getFullString() const;
    string getHiddenString() const;
    bool guessCharacter(string charGuess);
private:
    string fullPhrase;
    string hiddenPhrase;
};

#endif
