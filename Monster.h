#pragma once
#include "Creature.h"

class Monster : public Creature {

public:
	enum MonsterType { DRAGON, ORC, SLIME, MAX_TYPE };
	struct MonsterData {
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	static MonsterData monsters_array[MAX_TYPE];
	Monster(MonsterType type) :
		Creature(
			monsters_array[type].name,
			monsters_array[type].symbol,
			monsters_array[type].health,
			monsters_array[type].damage,
			monsters_array[type].gold
		)
	{}
	//статический метод
	static Monster getRandomMonster() {
		//int tmp = rand() % 3;
		return Monster(MonsterType(rand() % MAX_TYPE));
	}

};
Monster::MonsterData Monster::monsters_array[Monster::MAX_TYPE]{
	{"dragon", 'd', 20, 4, 100},
	{"orc", 'o', 4, 2, 25},
	{"slime", 's', 1, 1, 10}
};