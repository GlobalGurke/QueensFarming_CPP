#include "menus.h"
#include "debug.h"
#include "player.h"
#include "vegetables.h"
#include "console.h"
#include <iostream>
#include <vector>

std::vector<player> playerData;
player Player;

menus::menus() {
	inTurn = false;
	m_currentMenu = -1;
	m_playerAmount = 0;
	m_startMoney = 0;
	m_winCond = 0;
	m_currentTurn = -1;
	m_gameTurn = 1; 
	m_seed = 0;
	m_spoilTimer = 6;
}
void g_AddGold(int amount) {
	for (int i = 0; i < playerData.size(); i++) {
		playerData[i].AddGold(amount); 
	}
}
void g_RemoveGold(int amount) {
	for (int i = 0; i < amount; i++) {
		playerData[i].RemoveGold(amount); 
	}
}
void g_Reset() {
	for (int i = 0; i < playerData.size(); i++) {
		int gold = playerData[i].GetGold(); 
		playerData[i].RemoveGold(gold); 
	}
}
int trueInt(std::string string) {
	debug log; 
	char* p; 
	strtol(string.c_str(), &p, 10);
	if (*p == 0) {
		int n = stoi(string);
		return n; 
	}
	else {
		//log.Print(" Please use Int value! (1,2,3...)");
		return -1; 
	}
}
////////////////////////////Player Commands//////////////////////////////////////

void menus::CheckInput(std::string input) {
	if (input.find("show barn")) {
		ShowBarn(m_currentTurn);
		
	}


	


}




/// /////////////////////////////////////////////////////////////////////////////

void menus::ShowBarn(int playerID) {
	// Barn (Spoils in t rounds) 
	debug log; 
	int spoilTimer = m_spoilTimer - m_gameTurn;
	std::cout << "Barn (spoils in " << spoilTimer << " turns" << std::endl; 
	int mushroom = playerData[playerID].GetVegOfType('M');
	int tomato = playerData[playerID].GetVegOfType('T');
	int salad = playerData[playerID].GetVegOfType('S');
	int carrot = playerData[playerID].GetVegOfType('C');
	if (mushroom > 0) std::cout << "mushrooms:  " << mushroom << std::endl; 
	if (tomato > 0) std::cout << "tomatoes:   " << tomato << std::endl;
	if (carrot > 0) std::cout << "carrots:  " << carrot << std::endl;
	if (salad > 0) std::cout << "salads:     " << salad << std::endl;
	log.Print("-------------");
	std::cout << "Sum:       " << playerData[playerID].GetCurrentVegAmount() << std::endl; 
}
	

void menus::TurnSequence(int playerID) {
	debug log; 
	inTurn = true;
	int turnCount = 0; 
	while (inTurn && turnCount < 3) {
		std::string input = log.Get();
		if (input.find("end turn")) {
			inTurn = false;
			break;
		} else 
		CheckInput(input);
		turnCount += 1;
		
	}
}

int menus::GetMenu() {
	return m_currentMenu; 
}
void menus::SetMenu(int type) {
	 
	if (type == 0) {
		MainMenu();
		m_currentMenu = type; 
	} else 
		if (type == 2) {
		// End Screen ==> WInners usw. 
	}
	
	
}
void menus::AddNames(int namesAmount) {
	debug log; 
	m_playerAmount = namesAmount; 
	for (int a = 0; a < namesAmount; a++) {
		
		std::cout << "Enter name of player: " << a + 1 << std::endl;
		std::string name = log.Get();
		Player.SetName(name); 
		playerData.push_back(Player);
	}
	log.Info("Saved all playerData to Database");
}
int MainMenu_players() {
	debug log; 
	log.Print("How many players?");
	std::string players = log.Get();
	int pInt = trueInt(players);
	if (pInt == -1) {
		log.Print("Please use Int value! (e.g. 1, 2, 3...) ");
		MainMenu_players();
	}
	return pInt; 
}
int MainMenu_conditions() {
	debug log; 
	log.Print("Conditions");
	log.Print("With how much money should each player start?");
	std::string startMoney = log.Get();
	int sMoney = trueInt(startMoney);
	if (sMoney == -1) { log.Print(" Please use Int value"); MainMenu_conditions(); }
	log.Print(" "); 
	log.Print("With how much gold should the player win?");
	std::string money = log.Get();
	int winMoney = trueInt(money);
	if (winMoney == -1) { log.Print(" Please use Int value"); MainMenu_conditions(); }
	if (winMoney < sMoney) {
		log.Print("Wrong Win condition, start condition is higher than win condition!");
		MainMenu_conditions(); 
	}
	return sMoney, winMoney;
}

void menus::MainMenu() {
	debug log; 
	g_Reset(); 
	log.Print("WELCOME TO QUEENS FARMING"); 
	log.Print("=========================");
	log.Print("[GAME SETTINGS] ");
	int pInt = MainMenu_players();
	m_playerAmount = pInt; 
	log.Info("Starting to get Names");
	AddNames(pInt);
	int sMoney = 0;
	int winMoney = 0; 
	sMoney, winMoney = MainMenu_conditions(); 
	m_startMoney = sMoney; 
	m_winCond = winMoney; 
	g_AddGold(sMoney); 
	log.Print("Please enter the seed to shuffle the seeds");
	std::cout << ">"; 
	std::cin >> m_seed; 
	log.Info("Main Menu Settings finished "); 
}
void menus::NextTurn() {
	debug log; 
	console console; 
	log.Print(" ");
	if (m_currentTurn == -1) m_currentTurn += 1; 

	if (m_currentTurn < playerData.size()) {
		if (!inTurn) {
			std::string name = playerData[m_currentTurn].GetName();
			log.Print("It is " + name + "'s turn!");
			// ==> Got Players Turn, beginning his TURN
			log.Info("Beginning Turn of specific player");
			TurnSequence(m_currentTurn);
		}
		else {
			log.Info("current Turn is higher than playerData vector size");
			log.Info("Beginning new Game Round, setting currentTurn = 0");
			m_currentTurn = -1;
			m_gameTurn += 1;
			std::cout << m_currentTurn << " " << m_gameTurn << std::endl;

		}
	}
}