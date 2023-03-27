#include "player.h"
void player::AddGold(int amount) {
	m_gold += amount; 
}
void player::RemoveGold(int amount) {
	m_gold -= amount; 
}
void player::SetName(std::string name) {
	m_name = name; 
}

int player::GetGold() {
	return m_gold; 
}

std::string player::GetName() {
	return m_name;
}
int player::GetCurrentVegAmount() {
	for (int i = 0; i < 4; i++) {
		int amount =+ m_storage[i]; 
		return amount; 
	}
}
int player::GetLastVegAmount() {
	return m_lastVeg;
}
int player::GetVegOfType(char type) {
	if (type == 'C') return m_storage[0];
	if (type == 'S') return m_storage[1];
	if (type == 'T') return m_storage[2];
	if (type == 'M') return m_storage[3];
}

