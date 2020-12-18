#include "CountingMode.h"
#include "LuckyTicketCounter.h"

ISXMode::CountingMode::CountingMode(const unsigned int& ticket_length) : m_ticket_length(ticket_length) { }

unsigned int ISXMode::CountingMode::GetTicketLength() const
{
	return m_ticket_length;
}
