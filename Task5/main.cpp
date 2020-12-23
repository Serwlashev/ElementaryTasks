#include <iostream>

#include "NumberConverter.h"

int main(int argc, char* argv[]) {
	
	ISXConverter::NumberConverter converter;
	std:: cout << converter.ShowNumberAsText(argc, argv) << std::endl;

	system("pause");
	return 0;
}