#include "NumberConverter.h"

ISXConverter::NumberConverter::NumberConverter()
{
	m_converter = std::make_unique<ISXNumberConverter::NumberToTextConverter>();
}

std::string ISXConverter::NumberConverter::ShowNumberAsText(const int& argc, char** argv)
{
	std::string result = "";
	if (argc == 1) {
		result = "You can pass an integer number to the main class call and we translate it into the text\n";
	}
	else if (argc > 2) {
		result = "You passed wrong number of arguments!\n";
	}
	else {
		result = ConvertNumberToText(argv[1]);
	}
	return result;
}

std::string ISXConverter::NumberConverter::ConvertNumberToText(const std::string& value)
{
	std::string result = "";
	if (ISXConverterParser::Parser::IsValid(value)) {
		int number = ISXConverterParser::Parser::ParseToInt(value);

		if (m_converter) {
			result = m_converter.get()->Convert(number);
		}
		else{
			result = "Cannot create an instance of the number converter!\n";
		}
	}
	else {
		result = "You passed wrong number!";
	}

	return result;
}


