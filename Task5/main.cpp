#include <iostream>
#include <string>

#include "NumberToTextConverter.h"

int main() {
	ISXConverter::NumberToTextConverter converter;
	std::cout << converter.Convert(1561070565) << "\n";


	system("pause");
	return 0;
}