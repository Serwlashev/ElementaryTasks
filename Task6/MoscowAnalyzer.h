#pragma once
#include "TicketAnalyzer.h"

namespace ISXMoscowAnalyzer
{
	class MoscowAnalyzer : public ISXAnalyzer::TicketAnalyzer
	{
	public:
		MoscowAnalyzer(const unsigned int ticket_length);
		bool IsLuckyTicket(const std::string& ticket) const override;
	};
}


