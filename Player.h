#pragma once
#include "Creature.h"
class Player : public Creature {
private:
	int m_level;
public:
	Player(std::string name, 
		char symbol = '@', 
		int health = 10, 
		int damage = 1, 
		int gold = 0,
		int level = 1): 
		Creature(name,symbol,health,damage,gold), m_level{level}
	{}
	int getLevel() { return m_level; }
	void levelUp();
	bool hasWon();
};