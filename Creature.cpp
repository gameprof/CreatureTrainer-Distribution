//
//  Creature.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "Creature.h"


Creature::Creature() {
    // Do nothing
}


/**
 * Requires: cType must be in the range [0…NUM_TYPES].
 * Modifies: CreatureType data.
 * Effects:  Randomizes the various stats for this CreatureType.
 */
Creature Creature::factory(int cType) {
    Creature c;
    c.setType( cType );
    return c;
}


string Creature::getTypeName(int pad) {
    // Note: In Creature.h, pad is set to a default value of -1
    // CT::typeName() also has a default value for pad
    if (pad == -1) {
        return( CreatureType::typeName(type) );
    } else {
        // Override the default of CT::typeName
        return( CreatureType::typeName(type, pad) );
    }
}

CreatureType& Creature::getCreatureType() {
    return CreatureType::TYPES[type];
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns type.
 */
int Creature::getType() {
    return type;
}


/**
 * Requires: cType must be a valid number.
 * Modifies: Sets type.
 * Effects:  Nothing.
 */
void Creature::setType(int cType) {
    type = cType;
    level = 0;
    healthMax = CreatureType::TYPES[cType].getHealthMaxBase();
    healthCurr = healthMax;
    xp = 0;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns level.
 */
int Creature::getLevel() {
    return level;
}


/**
 * Requires: Nothing.
 * Modifies: Sets level.
 * Effects:  Nothing.
 */
void Creature::setLevel(int num) {
    level = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns healthCurr.
 */
int Creature::getHealthCurr() {
    return healthCurr;
}


/**
 * Requires: Nothing.
 * Modifies: Sets healthCurr.
 * Effects:  Nothing.
 */
void Creature::setHealthCurr(int num) {
    healthCurr = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns xp.
 */
int Creature::getXp() {
    return xp;
}


/**
 * Requires: Nothing.
 * Modifies: Sets xp.
 * Effects:  Nothing.
 */
void Creature::setXp(int num) {
    xp = num;
}


void Creature::rest() {
    if (healthCurr == 0) return;
    healthCurr += getCreatureType().getHealthRestIncrease();
    if (healthCurr > healthMax) {
        healthCurr = healthMax;
    }
}



int Creature::getAttackStrength() {
    int attack = getCreatureType().getAttackBase();
    attack += getLevel() * getCreatureType().getAttackPerLevel();
    return attack;
}



int Creature::getAttackElement() {
    return getCreatureType().getElementalAttackType();
}


int Creature::getElementalWeakness() {
    return getCreatureType().getElementalWeakness();
}


int Creature::getElementalStrength() {
    return getCreatureType().getElementalStrength();
}



int Creature::damage(int amount, int element) {
    if (element == getElementalWeakness()) {
        amount *= 2;
    } else if (element == getElementalStrength()) {
        amount /= 2;
    }
    if (amount > healthCurr) amount = healthCurr;
    healthCurr -= amount;
    return amount;
}







