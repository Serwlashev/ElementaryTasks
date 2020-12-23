#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "MoscowAnalyzer.h"
#include "PiterAnalyzer.h"

namespace ISXLuckyTickets
{
	class LuckyTicketCounter
	{
	public:
		LuckyTicketCounter(std::unique_ptr<ISXAnalyzer::TicketAnalyzer> analyzer);
		
		int CountTickets(const std::vector<std::string>::const_iterator& begin, const std::vector<std::string>::const_iterator& end);
	private:

		std::unique_ptr<ISXAnalyzer::TicketAnalyzer> m_analyzer;
	};
}

