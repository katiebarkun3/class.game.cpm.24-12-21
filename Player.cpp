#include "Player.h"
void Player::levelUp() {
	m_level++;
	m_damage++;
	m_health += 2;
}
bool Player::hasWon() { return m_level == 20; }
