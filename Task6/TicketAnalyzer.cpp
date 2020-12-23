#include "TicketAnalyzer.h"

ISXAnalyzer::TicketAnalyzer::TicketAnalyzer(const unsigned int& ticket_length) : m_ticket_length(ticket_length) { }

unsigned int ISXAnalyzer::TicketAnalyzer::GetTicketLength() const
{
	return m_ticket_length;
}
