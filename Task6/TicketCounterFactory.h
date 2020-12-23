#pragma once
#include <memory>
#include "TicketParser.h"
#include "LuckyTicketCounter.h"

namespace ISXTicketFactory
{
	class TicketCounterFactory
	{
	public:
		static std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> Create(std::unique_ptr<ISXAnalyzer::TicketAnalyzer> analyzer);
	};

}
