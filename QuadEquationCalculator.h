#pragma once
#include "ICalculator.h"
#include "CliManager.h"
class QuadEquationCalculator : public ICalculator
{
public:
	QuadEquationCalculator(CliManager* cliManager)
		: ICalculator(cliManager) {};
	void displayResults();
	std::string cli();
	void parseInput(std::string);
	void showDescription();
};
