#include "LuckyTicketCounter.h"

ISXLuckyTickets::LuckyTicketCounter::LuckyTicketCounter(std::unique_ptr<ISXAnalyzer::TicketAnalyzer> analyzer)
{
	m_analyzer = std::move(analyzer);
}

int ISXLuckyTickets::LuckyTicketCounter::CountTickets(const std::vector<std::string>::const_iterator& begin, const std::vector<std::string>::const_iterator& end) {
	int counter_tickets = 0;

	if (m_analyzer) {
		for (auto it = begin; it != end; it++) {
			if (m_analyzer.get()->IsLuckyTicket(*it)) {
				counter_tickets++;
			}
		}
	}

	return counter_tickets;
}
