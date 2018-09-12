#include "CliManager.h"
#include <iostream>
#include <string>
#include "SmartCalc.h"

void CliManager::writeMessage(std::string message, bool newLine)
{
	std::cout << message;
	if (newLine)std::cout << std::endl;
}

std::string CliManager::getInput()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}