#include <iostream>
#include <string>
#include "Creature.h"
#include "Trainer.h"
#include "EECSRandom.h"
#include "Party.h"
using namespace std;

void runBattle(Trainer &player1, Party &party, stringstream& ss);

void printError(stringstream& ss);


//we would do this if we want the format to be standardized
void printSpaces(int numSpaces);

/*
Horse_____ attacks enemy Elephant__ with Fire____ for 3__ damage and it faints.
Horse attacks enemy Elephant with Fire for 32 damage.
Enemy Elephant attacks Horse with Ice for 16 damage.
*/
void doPlayerAttack(Creature& enemy);
void printPlayerAttack(Creature &attacker, string &receiverName);

//situation
string starterSituation(Creature& enemy);
string updateSituation(Creature& enemy);


void creatureAttack(Creature& attacker, Creature& defender, bool isPlayer, stringstream& ss);

void creatureRest(Creature& rester, bool isPlayer, stringstream& ss);