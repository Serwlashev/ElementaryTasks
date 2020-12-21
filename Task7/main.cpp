#include <iostream>

#include "ProgrammPow.h"

int main(int argc, char* argv[]) {
	ISXProgrammPow::ProgrammPow programm;
	std::cout << programm.GetStringPows(argc, argv) << "\n";

	return 0;
}