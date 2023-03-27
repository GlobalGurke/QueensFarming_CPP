#include "Run.h"
#include "debug.h"
menus menu; 
void Run::RunGame() {
	debug log;
	m_Run = true; 
	while (m_Run) {
		log.Info("Next Turn");
		if (menu.GetMenu() == -1) {
			menu.SetMenu(0); 
		}
		if (menu.GetMenu() == 2) {
			m_Run == false; 
		}
		menu.NextTurn(); 
	}
}