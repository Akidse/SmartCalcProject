#pragma once
#include <string>
#include "CliManager.h"
class ICalculator
{
protected:
	CliManager* cliManager;
public:
	ICalculator(CliManager* cliManager) { this->cliManager = cliManager; }
	std::string name;
	virtual void displayResults() = 0;
	virtual std::string cli() = 0;
	virtual void showDescription() = 0;
};