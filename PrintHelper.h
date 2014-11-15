#ifndef __CreatureTrainer__PrintHelper__
#define __CreatureTrainer__PrintHelper__


/*
80 Characters of width to work with—————————————————————————————|
12345678901234567890123456789012345678901234567890123456789012345678901234567890
|         |         |         |         |         |         |         |         

Horse_____ attacks enemy Elephant__ with Fire____ for 3__ damage and it faints.
Horse attacks enemy Elephant with Fire for 32 damage.
Enemy Elephant attacks Horse with Ice for 16 damage.
|*Horse____# 012/123| Elephant   123/123| Aardvark__ 233/300| Echidna    234/345
|Enemy A________# Level _|
*/

#include <iostream>
#include <sstream>
#include "Creature.h"

class PrintHelper {
public:
    static void printIntro(stringstream & ss);
    
    static void printTeamStatus(Creature creatures[], int currCreatureIndex, stringstream & ss);

    static void printSingleCreature(Creature& c, bool current, stringstream& ss);

    static void printOptions(stringstream & ss);

    static void printEnd(int count, stringstream & ss);
    
    static void printPlayerAttack(Creature &attacker, string &receiverName, stringstream & ss);
    
    // Prints an 80-character wide horizontal line
    static void printHR(stringstream& ss);
    
    // Prints an 80-character wide horizontal underscore line
    static void printHRL(stringstream& ss);
};

#endif