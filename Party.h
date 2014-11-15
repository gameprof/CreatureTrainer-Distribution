//
//  Party.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/14/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Party__
#define __CreatureTrainer__Party__

#include <stdio.h>
#include "Creature.h"

class Party {
public:
    Party();
    
    static const int MAX_PARTY_SIZE = 4;
    
    Creature creatures[MAX_PARTY_SIZE];
    
    Creature& getActiveCreature();
    
    int getActiveCreatureNum();
    
    bool setActiveCreatureNum(int slotNum);
    
    void printStatus(stringstream& ss);
    
    bool alive();
    
    void restInactive();
    
private:
    int activeCreature = 0;
    
    
    
};

#endif /* defined(__CreatureTrainer__Party__) */
