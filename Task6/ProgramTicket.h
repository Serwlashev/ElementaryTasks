#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "LuckyTicketCounter.h"
#include "LuckyTicketView.h"
#include "TicketParser.h"

namespace ISXProgramTicket
{
	class ProgramTicket
	{
	public:
		ProgramTicket();

		void Start(const int& argc, char** argv1);

	private:
		ISXMode::TicketsMode ReadAlgorythmFromFile(const std::string& path);
		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> CreateTicketsCounter(ISXMode::TicketsMode mode);
		void ShowCalculatedLuckyTickets(const std::vector<std::string>& tickets);

		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> m_ticket_counter;
		std::string m_instruction;
	};

}


