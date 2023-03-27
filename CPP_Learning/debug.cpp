#include "debug.h"
#include <string> 
#include <iostream>
debug::debug() {
	m_debugLVL = 3; 
}
void debug::SetDebugLvl(int lvl) {
	if (lvl < 4) {
		m_debugLVL = lvl; 
	}
}


void debug::Warn(std::string message) {
	if (m_debugLVL == ShowWarning || m_debugLVL == ShowAll)
	std::cout <<"[WARNING] " << message << std::endl;
}
void debug::Error(std::string message) {
	if (m_debugLVL == ShowError || m_debugLVL == ShowAll)
	std::cout << "[ERROR] " << message << std::endl; 
}
void debug::Info(std::string message) {
	if (m_debugLVL == ShowInfo || m_debugLVL == ShowAll)
	std::cout << "[INFO]" << message << std::endl; 
}

void debug::Print(std::string message) {
	std::cout << message << std::endl; 
}
std::string debug::Get() {
	std::string value; 
	std::cout << ">"; 
	std::cin >> value; 

	std::cout << " " << std::endl; 
	return value; 
}