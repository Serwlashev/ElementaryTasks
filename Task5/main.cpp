#include <iostream>

#include "Converter.h"

int main(int argc, char* argv[]) {
	
	ISXConverter::Converter converter;
	std:: cout << converter.ShowNumberAsText(argc, argv) << std::endl;

	system("pause");
	return 0;
}