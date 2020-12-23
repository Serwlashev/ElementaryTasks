#include <iostream>

#include "ProgramPow.h"

int main(int argc, char* argv[]) {
	ISXProgramPow::ProgramPow program;
	std::cout << program.GetStringPows(argc, argv) << "\n";

	return 0;
}