#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "LuckyTicketCounter.h"
#include "LuckyTicketView.h"
#include "TicketParser.h"

using ISXTicketParser::TicketParser;
using ISXLuckyTickets::LuckyTicketCounter;
using ISXTicketView::LuckyTicketView;
using std::string;
using std::vector;

namespace ISXProgramTickets
{
	class ProgramTickets
	{
	public:
		ProgramTickets();

		void Start(const int& argc, char** argv1);
	private:
		ISXMode::TicketsMode ReadAlgorythmFromFile(const string& path);
		std::unique_ptr<LuckyTicketCounter> CreateTicketsCounter(ISXMode::TicketsMode mode);
		void ShowCalculatedLuckyTickets(const vector<string>& tickets);

		std::unique_ptr<LuckyTicketCounter> m_ticket_counter;
		string m_instruction;
	};

}


