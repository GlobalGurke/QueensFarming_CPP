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

void player::AddVegOfType(char type, int amount) {
	int lastAmount = GetCurrentVegAmount();
	m_lastVeg = lastAmount;
	if (type == 'C') m_storage[0] += amount; 
	if (type == 'S') m_storage[1] += amount;
	if (type == 'T') m_storage[2] += amount;
	if (type == 'M') m_storage[3] += amount;
}

int player::GetGold() {
	return m_gold; 
}

std::string player::GetName() {
	return m_name;
}
int player::GetCurrentVegAmount() {
	int amount = 0;
	for (int i = 0; i < 4; i++) {
		amount += m_storage[i];
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

