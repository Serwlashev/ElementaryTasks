#pragma once
#include "TicketAnalyzer.h"

namespace ISXPiterAnalyzer
{
	class PiterAnalyzer : public ISXAnalyzer::TicketAnalyzer
	{
	public:
		PiterAnalyzer(const unsigned int& ticket_length);
		bool IsLuckyTicket(const std::string& ticket) const override;
	};
}



