#include "MoscowAnalyzer.h"

ISXMoscowAnalyzer::MoscowAnalyzer::MoscowAnalyzer(const unsigned int ticket_length) : ISXAnalyzer::TicketAnalyzer(ticket_length) { }

bool ISXMoscowAnalyzer::MoscowAnalyzer::IsLuckyTicket(const std::string& ticket) const
{
	if (ticket.size() != m_ticket_length) {
		return false;
	}

	int first_half = 0;
	int second_half = 0;

	for (size_t i = 0; i < ticket.size(); i++) {
		if (i < ticket.size() / 2)
			first_half += ticket[i];
		else
			second_half += ticket[i];
	}

	if (first_half == second_half) {
		return true;
	}
    return false;
}
