#include "CommonCalculator.h"
#include "CliManager.h"
#include "InputParser.h"
#include <vector>
#include <iostream>
void CommonCalculator::displayResults()
{

}

std::string CommonCalculator::cli()
{
	cliManager->writeMessage("Common calculator: ");
	std::string input = cliManager->getInput();
	parseInput(input);
	return input;
}

void CommonCalculator::parseInput(std::string input)
{
	InputParser inputParser = InputParser();
	if (input == "-exit")return;
	if (input == "-help")
	{
		showDescription();
		return;
	}
	std::vector<std::string> explodedInput = inputParser.explodeData(input);
	if (explodedInput.size() == 0 || explodedInput.size() > 2)return;

	std::vector<double> parsedOperation = inputParser.parseCommonMathOperation(explodedInput.at(0));
	if (parsedOperation.size() == 0)
	{
		cliManager->writeMessage("Your input is wrong, type again or try -help", true);
		return;
	}
	double result;
	switch ((int)parsedOperation.at(1))
	{
	case 0:
		result = parsedOperation.at(0) + parsedOperation.at(2);
		break;
	case 1:
		result = parsedOperation.at(0) - parsedOperation.at(2);
		break;
	case 2:
		result = parsedOperation.at(0) * parsedOperation.at(2);
		break;
	case 3:
		result = parsedOperation.at(0) / parsedOperation.at(2);
		break;
	}
	cliManager->writeMessage("Result: " + std::to_string(result), true);
}
void CommonCalculator::showDescription()
{
	cliManager->writeMessage("Common calculator - for simple mathematic operations.", true);
	cliManager->writeMessage("Write command like 1+1, 2-1, 3*5, 4/2", true);
	cliManager->writeMessage("Or write -help to show this info again.", true);
}