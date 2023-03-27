#pragma once
#include <string>
class debug
{
private: 
	enum m_logTypes {
		error, warning, info
	};
	enum m_logLVL {
		ShowError, ShowWarning, ShowInfo, ShowAll
	};
	int m_debugLVL = 3; 
	std::string message = "0";
public: 
	debug();
	void SetDebugLvl(int lvl); 

	void Warn(std::string message);
	void Error(std::string message); 
	void Info(std::string message); 
	void Print(std::string message); 
	std::string Get();
};

