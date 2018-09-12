#include "InputParser.h"
#include <iostream>
#include <vector>
void InputParser::setInputData(std::string input)
{
	inputData = input;
	std::cout << inputData << std::endl;
}

std::vector<std::string> InputParser::explodeData(std::string input)
{
	std::vector<std::string> explodedData;
	bool isWriteString = false;
	for (int i = 0; i < input.length(); i++)
	{
		if (!isWriteString && input[i] != ' ')
		{
			isWriteString = true;
			explodedData.push_back("");
		}
		else if (isWriteString && input[i] == ' ')
		{
			isWriteString = false;
		}

		if (isWriteString)
		{
			explodedData.back() += input[i];
		}
	}
	return explodedData;
}

std::vector<double> InputParser::parseCommonMathOperation(std::string operation)
{
	std::vector<double> parsedOperation;
	for (int i = 0; i < operation.length(); i++)
	{
		
		if ((operation[i] == '+' || operation[i] == '-' || operation[i] == '*'
			|| operation[i] == '/') && i > 0 && i < operation.length() - 1)
		{
			parsedOperation.push_back(std::stod(operation.substr(0, i)));
			if (operation[i] == '+')parsedOperation.push_back(0);
			if (operation[i] == '-')parsedOperation.push_back(1);
			if (operation[i] == '*')parsedOperation.push_back(2);
			if (operation[i] == '/')parsedOperation.push_back(3);
			parsedOperation.push_back(std::stod(operation.substr(i+1, operation.length() - 1)));
		}
	}

	return parsedOperation;
}

std::vector<std::string> InputParser::parseCommandWithParams(std::string command)
{
	std::vector<std::string> explodedCommands = explodeData(command);
	std::vector<std::string> parsedCommand;
	for (int i = 0; i < explodedCommands.size(); i++)
	{

	}
	return parsedCommand;
}