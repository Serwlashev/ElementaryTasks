#include "TicketParser.h"

unsigned int ISXTicketParser::TicketParser::ParseToUI(const std::string& number)
{
	unsigned int res = 0U;

	if (!number.empty() && number != " " && number.size() < max_allowed_length && IsValid(number)) {

		res = std::stoul(number);
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
