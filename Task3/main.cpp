#include <iostream>

#include "Programm.h"

int main(int argc, char* argv[]) {
	ISXProg::Programm programm;

	programm.Start(argc, argv);

	system("pause");
	return 0;
}