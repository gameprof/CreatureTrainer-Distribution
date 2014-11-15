//
//  Creature.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Creature__
#define __CreatureTrainer__Creature__

#include <stdio.h>
#include <vector>
#include "CreatureType.h"

class Creature{
private:
    int type; // Creature's type
    int level; 	// - The numerical level of the creature. Starts at 0.
    int healthCurr; //- Current level of health. If healthCurr reaches 0, the creature faints.
    int healthMax;
    int xp; // The level of experience that this creature has
    
public:
    Creature();
    
    //(accessors for each private field)
    //rest() - (POSSIBLE) Called each turn that a creature is not used. Will regain a small amount of health
    
    /**
     * Requires: cType must be in the range [0…NUM_TYPES].
     * Modifies: CreatureType data.
     * Effects:  Randomizes the various stats for this CreatureType.
     */
    static Creature factory(int cType);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns the name of the CreatureType.
     */
    // Note: int pad below has a default value of -1.
    //       This is called a "default parameter"
    string getTypeName(int pad=-1);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns type.
     */
    int getType();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns type.
     */
    CreatureType& getCreatureType();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets type.
     * Effects:  Nothing.
     */
    void setType(int);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns level.
     */
    int getLevel();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets level.
     * Effects:  Nothing.
     */
    void setLevel(int);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns healthCurr.
     */
    int getHealthCurr();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets healthCurr.
     * Effects:  Nothing.
     */
    void setHealthCurr(int);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns xp.
     */
    int getXp();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets xp.
     * Effects:  Nothing.
     */
    void setXp(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Increases health.
     * Effects:  Heals the creature a small amount.
     */
    void rest();
    
    
    int getAttackStrength();
    
    
    
    int getAttackElement();
    
    
    int getElementalWeakness();
    
    
    int getElementalStrength();

    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Attacks this creature with the amount and element.
     *   Returns the amount of damage done.
     */
    int damage(int amount, int element);
};

#endif /* defined(__CreatureTrainer__Creature__) */
