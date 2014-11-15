//
//  CreatureType.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__CreatureType__
#define __CreatureTrainer__CreatureType__

class Creature;

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class CreatureType {
private:
    int type; // Creature's type (first letter of species name)
    int healthMaxBase;	// - The health for a L0 version of this creature
    int healthMaxPerLevel; // - The increase in healthMax for each increase in level
    int healthRestIncrease;// (POSSIBLE) the amount of health that regens for every turn this creature is not used
    int attackBase; // The attack strength for a L0 version
    int attackPerLevel; // The increase in attack strength per level
    int elementalAttackType; // The elemental type of the attack
    int elementalWeakness; // The elemental type that will do double damage to this creature
    int elementalStrength; // The elemental type that will do half damage to this creature
    
    
    
public:
    const static int    NUM_TYPES = 26;
    const static int    NUM_ELEMENTS = 8;
    const static string CREATURE_NAMES[];
    const static string ELEMENT_NAMES[];
    const static int    TYPE_NAME_LENGTH = 9;
    const static int    ELEM_NAME_LENGTH = 7;
    
    static std::vector<CreatureType> TYPES;
    
    const static int healthMaxBaseMin = 10;
    const static int healthMaxBaseMax = 20;
    
    const static int healthMaxPerLevelMin = 2;
    const static int healthMaxPerLevelMax = 6;
    
    const static int healthRestIncreaseMin = 4;
    const static int healthRestIncreaseMax = 6;
    
    const static int attackBaseMin = 4;
    const static int attackBaseMax = 6;
    
    const static int attackPerLevelMin = 2;
    const static int attackPerLevelMax = 4;
    
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    CreatureType();
    
    /**
     * Requires: cType must be in the range [0…NUM_TYPES].
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    CreatureType(int cType);
    
    static void randomizeTypes();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the CreatureType.
     */
    // Note: int pad below has a default value of TYPE_NAME_LENGTH.
    //       This is called a "default parameter"
    static string typeName(int tN, int pad=TYPE_NAME_LENGTH);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the CreatureType.
     */
    // Note: int pad below has a default value of ELEM_NAME_LENGTH.
    //       This is called a "default parameter"
    static string elementName(int eN, int pad=ELEM_NAME_LENGTH);
    
    
    /**
     * Requires: Nothing.
     * Modifies: CreatureType data.
     * Effects:  Randomizes the various stats for this CreatureType.
     */
    void randomizeType();
    
//    /**
//     * Requires: cType must be in the range [0…NUM_TYPES].
//     * Modifies: CreatureType data.
//     * Effects:  Randomizes the various stats for this CreatureType.
//     */
//    static Creature creatureFactory(int cType);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns type.
     */
    int getType();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets type.
     * Effects:  Nothing.
     */
    void setType(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns healthMaxBase.
     */
    int getHealthMaxBase();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets healthMaxBase.
     * Effects:  Nothing.
     */
    void setHealthMaxBase(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns healthMaxPerLevel.
     */
    int getHealthMaxPerLevel();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets healthMaxPerLevel.
     * Effects:  Nothing.
     */
    void setHealthMaxPerLevel(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns healthRestIncrease.
     */
    int getHealthRestIncrease();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets healthRestIncrease.
     * Effects:  Nothing.
     */
    void setHealthRestIncrease(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns attackBase.
     */
    int getAttackBase();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets attackBase.
     * Effects:  Nothing.
     */
    void setAttackBase(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns attackPerLevel.
     */
    int getAttackPerLevel();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets attackPerLevel.
     * Effects:  Nothing.
     */
    void setAttackPerLevel(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns elementalAttackType.
     */
    int getElementalAttackType();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets elementalAttackType.
     * Effects:  Nothing.
     */
    void setElementalAttackType(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns elementalWeakness.
     */
    int getElementalWeakness();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets elementalWeakness.
     * Effects:  Nothing.
     */
    void setElementalWeakness(int);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns elementalStrength.
     */
    int getElementalStrength();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Sets elementalStrength.
     * Effects:  Nothing.
     */
    void setElementalStrength(int);
    
    
};



#endif /* defined(__CreatureTrainer__CreatureType__) */
