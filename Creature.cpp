//Баркун Екатерина
#include <iostream>
#include <ctime>
#include "Creature.h"
using namespace std;
void Creature::reduceHealth(int health) { m_health -= health; }
bool Creature::isDead() { return m_health <= 0; }
void Creature::addGold(int gold) { m_gold += gold; }



