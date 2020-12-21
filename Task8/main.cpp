#include <iostream>

#include "ProgramFibonacci.h"

int main(int argc, char* argv[]) {
	ISXProgrFibonacci::ProgramFibonacci programm;
	std::cout << programm.GetFibonacciNumbers(argc, argv) << "\n";

	return 0;
}