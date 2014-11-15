//
//  CreatureType.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "CreatureType.h"
#include "EECSRandom.h"
using namespace std;


const string CreatureType::CREATURE_NAMES[] = { "Axolotyl", "Bittern", "C-lacanth",
    "Dugong", "Echidna", "Fossa", "Guanaco", "Honeybdgr", "Ibex", "Jackal",
    "Kiwi", "Loris", "Megapode", "Narwhal", "Ovenbird", "Pika", "Quagga",
    "RockHyrax", "Solenodon", "Tuatara", "Uromastyx", "Vaquita", "Wolverine",
    "Xenops", "Yaminon", "Zebu" } ;

const string CreatureType::ELEMENT_NAMES[] = { "Air", "Bombast", "Cool", "Dark",
    "Earth", "Funk", "Gamma", "Hammer" };

std::vector<CreatureType> CreatureType::TYPES = {};

//int CreatureType::healthMaxBaseMin = 10;
//int CreatureType::healthMaxBaseMax = 20;
//
//int CreatureType::healthMaxPerLevelMin = 2;
//int CreatureType::healthMaxPerLevelMax = 6;
//
//int CreatureType::healthRestIncreaseMin = 6;
//int CreatureType::healthRestIncreaseMax = 6;
//
//int CreatureType::attackBaseMin = 6;
//int CreatureType::attackBaseMax = 12;
//
//int CreatureType::attackPerLevelMin = 2;
//int CreatureType::attackPerLevelMax = 4;

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Default contructor.
 */
CreatureType::CreatureType() {
    // Do nothing
}


//NOTE: We may want to delete this constructor
/**
 * Requires: cType must be in the range [0…NUM_TYPES].
 * Modifies: Nothing.
 * Effects:  Default contructor.
 */
CreatureType::CreatureType(int cType) {
    // Generate random values for this type
    randomizeType();
}


void CreatureType::randomizeTypes() {
    CreatureType::TYPES.resize(NUM_TYPES);
    for (int i=0; i<NUM_TYPES; i++) {
        CreatureType ct;
        ct.setType(i);
        ct.randomizeType();
        TYPES[i] = ct;
    }
}

/**
 * Requires: Nothing.
 * Modifies: CreatureType data.
 * Effects:  Randomizes the various stats for this CreatureType.
 */
void CreatureType::randomizeType() {
    // Randomize the different CreatureType stats
    int num = EECSRandom::range( healthMaxBaseMin, healthMaxBaseMax+1 );
    healthMaxBase = num;
    num = EECSRandom::range( healthMaxPerLevelMin, healthMaxPerLevelMax+1 );
    healthMaxPerLevel = num;
    num = EECSRandom::range( healthRestIncreaseMin, healthRestIncreaseMax+1 );
    healthRestIncrease = num;
    num = EECSRandom::range( attackBaseMin, attackBaseMax+1 );
    if (num % 2 == 1) num--;
    attackBase = num;
    num = EECSRandom::range( attackPerLevelMin, attackPerLevelMax+1 );
    attackPerLevel = num;
    
    elementalAttackType = EECSRandom::range( 0, NUM_ELEMENTS );
    elementalWeakness   = EECSRandom::range( 0, NUM_ELEMENTS );
    elementalStrength   = EECSRandom::range( 0, NUM_ELEMENTS );
}


///**
// * Requires: cType must be in the range [0…NUM_TYPES].
// * Modifies: CreatureType data.
// * Effects:  Randomizes the various stats for this CreatureType.
// */
//Creature CreatureType::creatureFactory(int cType) {
//    Creature c;
//    c.setType( cType );
//    return c;
//}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns the name of the CreatureType.
 */
string CreatureType::typeName(int tN, int pad) {
    // Note: in CreatureType.h pad is set to TYPE_NAME_LENGTH by default.
    string name = CREATURE_NAMES[tN];
    while (name.length() < pad) {
        name += " ";
    }
    return( name );
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns the name of the CreatureType.
 */
string CreatureType::elementName(int eN, int pad) {
    // Note: in CreatureType.h pad is set to ELEM_NAME_LENGTH by default.
    string name = ELEMENT_NAMES[eN];
    while (name.length() < pad) {
        name += " ";
    }
    return( name );
}





/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns type.
 */
int CreatureType::getType() {
    return type;
}


/**
 * Requires: Nothing.
 * Modifies: Sets type.
 * Effects:  Nothing.
 */
void CreatureType::setType(int num) {
    type = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns healthMaxBase.
 */
int CreatureType::getHealthMaxBase() {
    return healthMaxBase;
}


/**
 * Requires: Nothing.
 * Modifies: Sets healthMaxBase.
 * Effects:  Nothing.
 */
void CreatureType::setHealthMaxBase(int num) {
    healthMaxBase = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns healthMaxPerLevel.
 */
int CreatureType::getHealthMaxPerLevel() {
    return healthMaxPerLevel;
}


/**
 * Requires: Nothing.
 * Modifies: Sets healthMaxPerLevel.
 * Effects:  Nothing.
 */
void CreatureType::setHealthMaxPerLevel(int num) {
    healthMaxPerLevel = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns healthRestIncrease.
 */
int CreatureType::getHealthRestIncrease() {
    return healthRestIncrease;
}


/**
 * Requires: Nothing.
 * Modifies: Sets healthRestIncrease.
 * Effects:  Nothing.
 */
void CreatureType::setHealthRestIncrease(int num) {
    healthRestIncrease = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns attackBase.
 */
int CreatureType::getAttackBase() {
    return attackBase;
}


/**
 * Requires: Nothing.
 * Modifies: Sets attackBase.
 * Effects:  Nothing.
 */
void CreatureType::setAttackBase(int num) {
    attackBase = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns attackPerLevel.
 */
int CreatureType::getAttackPerLevel() {
    return attackPerLevel;
}


/**
 * Requires: Nothing.
 * Modifies: Sets attackPerLevel.
 * Effects:  Nothing.
 */
void CreatureType::setAttackPerLevel(int num) {
    attackPerLevel = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns elementalAttackType.
 */
int CreatureType::getElementalAttackType() {
    return elementalAttackType;
}


/**
 * Requires: Nothing.
 * Modifies: Sets elementalAttackType.
 * Effects:  Nothing.
 */
void CreatureType::setElementalAttackType(int num) {
    elementalAttackType = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns elementalWeakness.
 */
int CreatureType::getElementalWeakness() {
    return elementalWeakness;
}


/**
 * Requires: Nothing.
 * Modifies: Sets elementalWeakness.
 * Effects:  Nothing.
 */
void CreatureType::setElementalWeakness(int num) {
    elementalWeakness = num;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Gets and returns elementalStrength.
 */
int CreatureType::getElementalStrength() {
    return elementalStrength;
}


/**
 * Requires: Nothing.
 * Modifies: Sets elementalStrength.
 * Effects:  Nothing.
 */
void CreatureType::setElementalStrength(int num) {
    elementalStrength = num;
}


