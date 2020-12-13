#include <iostream>
#include <string>

#include "NumberToTextConverter.h"

int main() {
	ISXConverter::NumberToTextConverter converter;
	std::cout << converter.Convert(-423002230) << "\n";


	system("pause");
	return 0;
}