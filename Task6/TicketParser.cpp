#include "TicketParser.h"

unsigned int ISXTicketParser::TicketParser::ParseToUI(const std::string& number)
{
	unsigned int res = 0;

	if (!number.empty() && number != " " && number.size() < 9 && IsValid(number)) {

		res = std::stoi(number);
	}

	return res;
}

bool ISXTicketParser::TicketParser::IsValid(const std::string& number)
{

	for (size_t i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}
