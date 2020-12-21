#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "LuckyTicketCounter.h"
#include "..\AdditionalClasses\Validator.h"
#include "..\AdditionalClasses\Console.h"

using ISXConsole::Console;
using std::string;
using std::vector;
using ISXLuckyTickets::LuckyTicketCounter;

namespace ISXProgramTickets
{
	class ProgramTickets
	{
	public:
		ProgramTickets();

		void Start(const int& argc, char** argv1);
	private:
		ISXMode::TicketsMode ReadAlgorythmFromFile(const string& path);
		unsigned int GetTicketLength();
		std::unique_ptr<LuckyTicketCounter> CreateTicketsCounter(ISXMode::TicketsMode mode);
		void ShowCalculatedLuckyTickets(const vector<string>& tickets);

		std::unique_ptr<LuckyTicketCounter> m_ticket_counter;
		string m_instruction;
	};

}


