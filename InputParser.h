#pragma once
#include <string>
#include <vector>
class InputParser {
	std::string inputData;
public:
	void setInputData(std::string input);
	std::vector<std::string> explodeData(std::string input);
	std::vector<double> parseCommonMathOperation(std::string operation);
	std::vector<std::string> parseCommandWithParams(std::string command);
};