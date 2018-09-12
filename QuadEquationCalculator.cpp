#include "QuadEquationCalculator.h"
#include "InputParser.h"
#include "math.h"
void QuadEquationCalculator::showDescription()
{
	cliManager->writeMessage("Quadratic Equation calculator", true);
	cliManager->writeMessage("In this calculator you can solve quadratic equations like ax^2+bx+c = 0", true);
	cliManager->writeMessage("To solve type: quad {a} {b} {c}. For example: quad 3 4 5. Its equal to 3x^2 + 4x + 5 = 0", true);
	cliManager->writeMessage("To show this message again type -help", true);
}
std::string QuadEquationCalculator::cli()
{
	cliManager->writeMessage("Quadratic equation calculator: ");
	std::string input = cliManager->getInput();
	parseInput(input);
	return input;
}
void QuadEquationCalculator::parseInput(std::string input)
{
	if (input == "-exit")return;
	if (input == "-help")
	{
		showDescription();
		return;
	}

	InputParser inputParser = InputParser();
	std::vector<std::string> explodedCommands = inputParser.explodeData(input);
	if (explodedCommands.size() < 4 || explodedCommands.at(0) != "quad")return;
	double a = std::stod(explodedCommands.at(1));
	double b = std::stod(explodedCommands.at(2));
	double c = std::stod(explodedCommands.at(3));
	if (a < 0)
	{
		cliManager->writeMessage("a cant be less then zero", true);
		return;
	}
	double d = sqrt(pow(b,2) - 4*a*c);
	double x1 = (-b + d) / (2 * a);
	double x2 = (-b - d) / (2 * a);
	cliManager->writeMessage("Solving of equation...", true);
	cliManager->writeMessage("Result:", true);
	cliManager->writeMessage("D = " + std::to_string(d), true);
	cliManager->writeMessage("X1 = " + std::to_string(x1), true);
	if (d != 0) {
		cliManager->writeMessage("X2 = " + std::to_string(x2), true);
	}
}
void QuadEquationCalculator::displayResults()
{

}