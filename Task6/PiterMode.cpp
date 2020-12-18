#include "PiterMode.h"

ISXPiterMode::PiterMode::PiterMode(const unsigned int& ticket_length) : CountingMode(ticket_length) { }


bool ISXPiterMode::PiterMode::IsLuckyTicket(const std::string& ticket) const
{
	if (ticket.size() != m_ticket_length) {
		return false;
	}

	int first_half = 0;
	int second_half = 0;

	for (size_t i = 0; i < ticket.size(); i++) {
		if (i % 2 == 0)
			first_half += ticket[i];
		else
			second_half += ticket[i];
	}
	if (first_half == second_half) {
		return true;
	}
	return false;
}
