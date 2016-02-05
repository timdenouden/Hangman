//
//  dictionary.h
//  Hangman
//
//  Created by Timothy DenOuden on 11/26/14.
//  Copyright (c) 2014 Timothy DenOuden. All rights reserved.
//

#ifndef Hangman_dictionary_h
#define Hangman_dictionary_h

#include <string>
#include "phrase.h"

class Dictionary {
public:
    Dictionary(string filename);
    Phrase* getPhrase() const;
};

#endif
