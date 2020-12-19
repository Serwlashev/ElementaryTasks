#include "Parser.h"

unsigned int ISXParser::Parser::ParseUI(const std::string& number)
{
	unsigned int res = 0;

	if (!number.empty() || number != " " && number.size() < 9) {

		try {
			res = std::stoi(number);
		}
		catch (std::invalid_argument) {
			res = 0;
		}

		if (number.compare(std::to_string(res)) != 0) {
			res = 0;
		}
	}

	return res;
}
