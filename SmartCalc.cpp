#include "SmartCalc.h"
#include "CliManager.h"
#include "CommonCalculator.h"
#include "QuadEquationCalculator.h"
SmartCalc::SmartCalc(CliManager* cliManager)
{
	this->cliManager = cliManager;
}

void SmartCalc::start()
{
	isStarted = true;
	loop();
}

void SmartCalc::showAllCalcsDescriptions()
{
	cliManager->writeMessage("All calculators available:", true);
	for (auto it = calculators.begin(); it != calculators.end(); ++it)
	{
		cliManager->writeMessage(std::to_string(it->first) + " - " + it->second, true);
	}
	cliManager->writeMessage("Write -all to see this information  again", true);
}

void SmartCalc::loop()
{
	showAllCalcsDescriptions();
	std::string input;
	while (isStarted)
	{
		if (chosenCalc == 0)
		{
			cliManager->writeMessage("Choose calculator: ");
			input = cliManager->getInput();
			parseInput(input);
		}
		else
		{
			std::string backInput = currentCalc->cli();
			if (backInput == "-exit")
			{
				chosenCalc = 0;
			}
		}

	}
}

void SmartCalc::parseInput(std::string input)
{
	if (input == "-all")
	{
		showAllCalcsDescriptions();
		return;
	}
	int parsedNumber = std::atoi(input.c_str());
	if (parsedNumber)
	{
		switch (parsedNumber)
		{
			case 1:
				currentCalc = new CommonCalculator(cliManager);
				currentCalc->showDescription();
				chosenCalc = 1;
			break;
			case 2:
				currentCalc = new QuadEquationCalculator(cliManager);
				currentCalc->showDescription();
				chosenCalc = 2;
			break;
			default:
				cliManager->writeMessage("Your input is wrong!", true);
			break;
		}
	}
	else cliManager->writeMessage("Your input is wrong!", true);
}

void SmartCalc::stop()
{
	isStarted = false;
}