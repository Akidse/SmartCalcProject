#pragma once
#include <string>

class CliManager
{
	bool isActive = false;
	std::string userInput;
public:
	void writeMessage(std::string message, bool newLine = false);
	std::string getInput();
};