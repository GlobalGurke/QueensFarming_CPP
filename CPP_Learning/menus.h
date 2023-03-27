#pragma once
#include <vector>
#include <string>
class menus
{
public: 
	enum MenuTypes {
		m_MainMenu, m_Game, m_End
	};
private:
	int m_currentMenu; 
	int m_gameTurn; 
	int m_playerAmount;
	int m_startMoney; 
	int m_winCond; 
	int m_currentTurn; 
	int m_seed; 
	int m_spoilTimer;
	
public: 
	void ShowBarn(int playerID);
	menus();
	void SetMenu(int type); 
	int GetMenu();
	void AddNames(int value);
	void MainMenu();
	void NextTurn();
	
	//void End(); 

};

