#include <iostream>
#include "SmartCalc.h"
#include "CliManager.h"
using namespace std;

int main() {
	CliManager cli = CliManager();
	SmartCalc calc = SmartCalc(&cli);
	calc.start();
	system("pause");
	return 0;
}