#pragma once
#include "CliManager.h"
#include <string>
#include <map>
#include "ICalculator.h"

class SmartCalc
{
	CliManager* cliManager;
	bool isStarted = false;
	std::map<int, std::string> calculators = {
		{1, "Common calculations(+,-,*, /)"},
		{2, "Quadratic equations"}
	};
	int chosenCalc = 0;
	ICalculator* currentCalc;
	void parseInput(std::string input);
public:
	SmartCalc(CliManager* cliManager);
	void start();
	void stop();
	void loop();
	void showAllCalcsDescriptions();
};