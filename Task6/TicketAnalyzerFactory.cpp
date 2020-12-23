#include "TicketAnalyzerFactory.h"

std::unique_ptr<ISXAnalyzer::TicketAnalyzer> ISXAnalyzerFactory::TicketAnalyzerFactory::Create(ISXAnalyzer::TicketsMode mode, const int ticket_length)
{
	std::unique_ptr<ISXAnalyzer::TicketAnalyzer> analizer;

	switch (mode) {
	case ISXAnalyzer::TicketsMode::Moscow:
		analizer = std::make_unique<ISXMoscowAnalyzer::MoscowAnalyzer>(ticket_length);
		break;
	case ISXAnalyzer::TicketsMode::Piter:
		analizer = std::make_unique<ISXPiterAnalyzer::PiterAnalyzer>(ticket_length);
		break;
	default:
		analizer = nullptr;
		break;
	}

	return analizer;
}
