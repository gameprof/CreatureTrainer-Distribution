#include <iostream>
#include <string>
#include <sstream>
#include "Creature.h"
#include "Trainer.h"
#include "EECSRandom.h"
#include "Battle.h"
#include "PrintHelper.h"
#include "Party.h"

using namespace std;

//const int MAX_PARTY_SIZE = 4;
//const int MAX_TYPE_SIZE = 9; //longest creature name




//to run a battle
//we need a trainer, 
//their party, 
//the creature they are currently using to battle (carries over from previous battles),
//and an enemy creature
void runBattle(Trainer &player1, Party &party, stringstream& ss){
    //the battle is a series of informative outputs of situations
    
    // WHAT SHOULD THE ENEMIES BE??
    int tNum = EECSRandom::range(0,CreatureType::NUM_TYPES);
    Creature enemy = Creature::factory( tNum );
    
    //This simply introduces the enemy. The trainer can make the first move.
    PrintHelper::printHR(ss);
    ss << "\nA new challenger approaches…\n";
    ss << "It's an enemy " << enemy.getTypeName(0) << "!\n\n";
    
    string playerMove;
    while ( party.alive() && enemy.getHealthCurr() > 0 ) {
        // Set up the current move
        PrintHelper::printHR(ss);
        party.printStatus(ss);
        PrintHelper::printHR(ss);
        
        if (party.getActiveCreature().getHealthCurr() == 0) {
            ss << "You must swap to another creature!\n";
        }
        
        ss << "Trainer, make your move. (a-Attack, s#-Swap to slot #): ";
        
        // Ask the player for her next move…
        playerMove = player1.makeMove(ss);
        ss.str("");
        ss << "\n\n";
        PrintHelper::printHRL(ss);
        ss << "\n";
        
        // Act on it
        switch (playerMove[0]){
            case 'a': // Attack
                creatureAttack( party.getActiveCreature(), enemy, true, ss);
                break;
                
            case 's': // Swap for another party member
                // You cannot swap to a fainted party member
                {
                    int oldIndex = party.getActiveCreatureNum();
                    int swapIndex = playerMove[1] - '1'; //because atoi won't work
                    if (swapIndex >= Party::MAX_PARTY_SIZE || swapIndex < 0) {
                        printError(ss);
                    } else {
                        party.setActiveCreatureNum(swapIndex);
                        if (party.getActiveCreatureNum() == oldIndex) {
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " couldn't swap in! ";
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " is still fighting.\n";
                        } else {
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " swaps out, and ";
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " swaps in!\n";
                        }
                    }
                }
                break;
                
            case 'r': // Rest and regain a bit of health. Usually a bad move.
                creatureRest(party.getActiveCreature(), true, ss);
                break;
                
            default:
                printError(ss);
        }
        
        // Everyone in the party who is not the active creature rest()s
        party.restInactive();
        
        // Enemy move
        // For now, this is always to attack
        if (enemy.getHealthCurr() > 0) {
            if (party.getActiveCreature().getHealthCurr() > 0) {
                creatureAttack(enemy, party.getActiveCreature(), false, ss);
            } else {
                creatureRest(enemy, false, ss);
            }
        }
        
    }
    
    if (enemy.getHealthCurr() == 0) {
        ss << "\nYou have defeated the Enemy ";
        ss << enemy.getTypeName(0) << "! Congratulations!\n";
        ss << "Your party also gets to rest a turn and regains some health.\n\n";
        party.getActiveCreature().rest();
        party.restInactive();
    }
}
//
//    string situation = starterSituation(enemy);
//    //trainer attacks first
//    PrintHelper::printOptions();
//    //While none have fainted, loop through the battle
//    while (party[0].getHealthCurr() > 0 && party[1].getHealthCurr() > 0 &&
//        party[2].getHealthCurr() > 0 && party[3].getHealthCurr() > 0){
//        //print some situation
//        situation = updateSituation(enemy);
//        stringstream ss;
//        ss << situation;
//        PrintHelper::printTeamStatus(party, currentCreatureIndex, ss);
//        //pass that situation in trainer
//        string playerMove = player1.makeMove(situation);
//        //or for testing, 
//        //string playerMove;
//        //cin >> playerMove;
//
//        //enemy's name
//        string enemyName = "enemy " + CreatureType::CREATURE_NAMES[enemy.getType()];
//
//        //switch based on move
//        int partyIndex;
//        switch (playerMove[0]){
//        case 'a':
//            doPlayerAttack(enemy);
//            PrintHelper::printPlayerAttack(party[currentCreatureIndex], enemyName);
//            break;
//        case 's':
//            partyIndex = playerMove[1] - '0'; //because atoi won't work
//            if (partyIndex < MAX_PARTY_SIZE && partyIndex >= 0){
//                currentCreatureIndex = partyIndex;
//            }
//            else{
//                printError();
//            }
//            break;
//        default:
//            printError();
//        }
//    }



void printError(stringstream& ss) {
    ss << "ERROR: INVALID MOVE" << endl;
    ss << "You lost your turn." << endl;
}

/*
|*Horse____# 012/123| Elephant   123/123| Aardvark__ 233/300| Echidna    234/345
|Enemy A________# Level _|
*/





/*
Horse_____ attacks enemy Elephant__ with Fire____ for 3__ damage and it faints.
Horse attacks enemy Elephant with Fire for 32 damage.
Enemy Elephant attacks Horse with Ice for 16 damage.
*/
void creatureAttack(Creature& attacker, Creature& defender, bool isPlayer, stringstream& ss) {
    int aStrength = attacker.getAttackStrength();
    int aElement = attacker.getAttackElement();
    
    int damageDone = defender.damage(aStrength, aElement);
    
    string aName, dName;
    if (isPlayer) {
        aName = "Your  " + attacker.getTypeName();
        dName = "Enemy " + defender.getTypeName();
    } else {
        aName = "Enemy " + attacker.getTypeName();
        dName = "Your  " + defender.getTypeName();
    }
    
    // Only allow Attack if the creature has not fainted
    if (attacker.getHealthCurr() == 0) {
        ss << aName << " can't attack because it has fainted!\n";
        return;
    }

    ss << aName << " attacks " << dName;
    ss << " with " << CreatureType::elementName(aElement);
    ss << " for " << damageDone << " damage.\n";
    
    if (defender.getHealthCurr() == 0) {
        ss << dName << " faints!\n";
    }
    
}


void creatureRest(Creature& rester, bool isPlayer, stringstream& ss) {
    string resterName;
    if (isPlayer) {
        resterName = "Your  " + rester.getTypeName();
    } else {
        resterName = "Enemy " + rester.getTypeName();
    }
    // Don't allow rest for fainted Creatures
    if (rester.getHealthCurr() == 0) {
        ss << resterName << " could not rest because it has fainted.\n";
        return;
    }
    
    // Rest should be okay
    int preHealth = rester.getHealthCurr();
    rester.rest();
    int increase = rester.getHealthCurr() - preHealth;
    
    ss << resterName << " rests and regains ";
    ss << increase << " health.\n";
    
    rester.rest();
}


//situation
string starterSituation(Creature& enemy) {
    return "Enemy " + CreatureType::CREATURE_NAMES[enemy.getType()] + " has begun battle with you!";
}

string updateSituation(Creature& enemy) {
    return "";
}

