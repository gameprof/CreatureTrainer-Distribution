//
//  Trainer.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"


string Trainer::makeMove(stringstream& situation) {
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer 
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situation.str(); 
    

    /* 
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */
    string response;
    cin >> response; 

    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}