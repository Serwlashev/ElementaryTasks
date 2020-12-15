#include <iostream>

#include "Converter.h"

int main(int argc, char* argv[]) {
	
	ISXConverter::Converter converter;
	converter.ShowNumberAsText(argc, argv);

	system("pause");
	return 0;
}