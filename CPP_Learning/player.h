#pragma once
#include <vector>
#include <string>

class player {
private: 
	std::string m_name; 
	int m_storage[4] = { 0, 0, 0, 0 }; // C, S, T, M
	int m_lastVeg = 0;
	int m_gold = 0; 
	std::vector<std::string> buildings;  // 12Fi, 03B,
public:
	void SetName(std::string name); 
	void AddGold(int amount); 
	void RemoveGold(int amount); 
	std::string GetName();
public:
	int GetGold(); 
	int GetLastVegAmount(); 
	int GetCurrentVegAmount(); 
	int GetVegOfType(char type);
};
