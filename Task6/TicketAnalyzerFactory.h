#pragma once
#include <memory>
#include "TicketAnalyzer.h"
#include "MoscowAnalyzer.h"
#include "PiterAnalyzer.h"

namespace ISXAnalyzerFactory
{
	class TicketAnalyzerFactory
	{
	public:
		static std::unique_ptr<ISXAnalyzer::TicketAnalyzer> Create(ISXAnalyzer::TicketsMode mode, const int ticket_length);
	};

}
