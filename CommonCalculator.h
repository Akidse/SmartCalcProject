#pragma once
#include "ICalculator.h"
#include "CliManager.h"
#include <string>
class CommonCalculator : public ICalculator
{
public:
	CommonCalculator(CliManager* cliManager)
		: ICalculator(cliManager) {}
	void displayResults();
	std::string cli();
	void showDescription();
	void parseInput(std::string input);
};