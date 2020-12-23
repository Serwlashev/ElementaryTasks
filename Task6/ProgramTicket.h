#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "LuckyTicketCounter.h"
#include "LuckyTicketView.h"
#include "TicketParser.h"
#include "TicketCounterFactory.h"
#include "TicketAnalyzerFactory.h"

namespace ISXProgramTicket
{
	class ProgramTicket
	{
	public:
		ProgramTicket();

		void Start(const int argc, char** argv1);
		std::string GetNumLuckyTickets(const std::vector<std::string>& tickets);

	private:
		const int num_required_params = 2;

		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> CreateTicketsCounter(ISXAnalyzer::TicketsMode mode);
		ISXAnalyzer::TicketsMode ReadAlgorythmFromFile(const std::string& path);

		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> m_ticket_counter;
		std::string m_instruction;
	};

}


