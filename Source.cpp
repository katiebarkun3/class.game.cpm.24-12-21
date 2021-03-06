#include<iostream>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <ctime>
using namespace std;

/*Суть:
   +Игрок сталкивается с одним случайно выбранным монстром.
   С каждым монстром игрок может либо (R)un, либо (F)ight.
   Если игрок решает Run, то шансы на удачный побег составляют 50%.
   Если игроку удается сбежать, то ​​он благополучно переходит к следующему монстру (его здоровье/урон/золото при этом не уменьшается).
   Если игроку не удается сбежать, то монстр его атакует. Здоровье игрока уменьшается от урона монстра. Затем игрок выбирает свое следующее действие.
   Если игрок выбирает Fight, то он атакует монстра. Здоровье монстра уменьшается от урона игрока.
   Если монстр умирает, то игрок забирает всё золото монстра + увеличивает свой level и урон на 1.
   Если монстр не умирает, то он атакует игрока. Здоровье игрока уменьшается от урона монстра.
   Игра заканчивается, если игрок умер (проигрыш) или достиг 20 уровня (выигрыш).
   Если игрок умирает, то программа должна сообщить игроку, какой уровень у него был и сколько золота он имел.
   Если игрок побеждает, то игра должна сообщить игроку, что он выиграл и сколько у него есть золота.*/

void attackMonster(Player& p, Monster& mon);
void attackPlayer(Player& p, Monster& mon);



int main() {
	//настраиваем генератор случайных чисел
	srand(unsigned int (time(0)));
	rand();
	//создаём игрока, передаём только имя,
	//в остальные поля устанавливается значение по умолчанию из конструктора
	Player p("ibragim");
	//основной игровой цикл
	//пока игрок не умер и не выиграл
	while (!p.isDead() && !p.hasWon()) {
		//создаётся монстр
		Monster mon = Monster::getRandomMonster();
		//выводим имя монстра, которого мы встретили
		cout << "You have encountered a " << mon.getName() << endl;
		char input;
		//предлагаем побег или бой
		cout << "(R)un or (F)ight" << endl;
		cin >> input;
		//игрок выбрал побег
		if (input == 'R' || input == 'r') {
			// задаём вероятность 50% что сбежать удaлось
			if (rand() % 100 < 50) {
				cout << "You succesfully fled" << endl;
				continue;
			}
			//сбежать не удалось
			else {
				//монстр бьёт игрока
				attackPlayer(p, mon);
			}
		}
		//игрок выбрал сражение
		if (input == 'F' || input == 'f') {
			//игрок бьёт монстра
			attackMonster(p, mon);
			//монстр бьёт игрока
			attackPlayer(p, mon);
		}
	}
	if (p.isDead()) {
		cout << "You died ;(" << endl;
	}
	else if (p.hasWon()) {
		cout << "You win :)" << endl;
	}


	return 0;
}
	void attackMonster(Player & p, Monster & mon) {
		cout << "You hit " << mon.getName() << " for " << p.getDamage() << " damage" << endl;
		mon.reduceHealth(p.getDamage());
		if (mon.isDead()) {
			cout << "You kill " << mon.getName() << endl;
		    p.levelUp();
			cout << "Your level is " << p.getLevel() << endl;
			p.addGold(mon.getGold());
			cout << " You found " << mon.getGold() << " gold " << endl;
		}
	}
	void attackPlayer(Player& p, Monster& mon) {
		if (mon.isDead()) return;
		cout << mon.getName() << " hit you for " << mon.getDamage() << " damage" << endl;
		p.reduceHealth(mon.getDamage());
	}




	