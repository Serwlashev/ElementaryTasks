#include "LuckyTicketCounter.h"

ISXLuckyTickets::LuckyTicketCounter::LuckyTicketCounter(const ISXMode::TicketsMode& mode, const unsigned int& ticket_length)
{
	m_counting_mode = CreateMode(mode, ticket_length);
}

int ISXLuckyTickets::LuckyTicketCounter::CountTickets(const std::vector<std::string>& tickets)
{
	int counter_tickets = 0;

	for (size_t i = 0; i < tickets.size(); i++) {
		if (m_counting_mode.get()->IsLuckyTicket(tickets[i])) {
			counter_tickets++;
		}
	}

	return counter_tickets;
}

unsigned int ISXLuckyTickets::LuckyTicketCounter::GetTicketLength()
{
	return m_counting_mode.get()->GetTicketLength();
}


std::unique_ptr<ISXMode::CountingMode> ISXLuckyTickets::LuckyTicketCounter::CreateMode(const ISXMode::TicketsMode& mode, const unsigned int& ticket_length)
{
	std::unique_ptr<ISXMode::CountingMode> count_mode;

	switch (mode) {
	case ISXMode::TicketsMode::Moscow:
		count_mode = std::make_unique<ISXMoscowMode::MoscowMode>(ticket_length);
		break;
	case ISXMode::TicketsMode::Piter:
		count_mode = std::make_unique<ISXPiterMode::PiterMode>(ticket_length);
	}

	return std::move(count_mode);
}

