#include "Parser.h"

bool ISXConverterParser::Parser::IsValid(const std::string& number)
{
	if (number.length() >= max_allowed_length) {
		return false;
	}

	for (size_t i = 0; i < number.length(); i++) {
		// if it is first symb from  number and it has sign "minus" and more than one symbol in it
		if (i == 0 && number.length() > 1 && number[i] == '-') {
			continue;
		}
		else if (!isdigit(number[i])) {
			return false;
		}
	}

	return true;
}

int ISXConverterParser::Parser::ParseToInt(const std::string& number)
{
	int res = 0;

	if (!number.empty() && number != " " && number.size() < max_allowed_length && IsValid(number)) {

		res = std::stoi(number);
	}

	return res;
}
