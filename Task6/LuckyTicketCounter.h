#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "MoscowMode.h"
#include "PiterMode.h"

namespace ISXLuckyTickets
{
	class LuckyTicketCounter
	{
	public:
		LuckyTicketCounter(const ISXMode::TicketsMode& mode, const unsigned int& ticket_length);

		int CountTickets(const std::vector<std::string>& tickets);
		unsigned int GetTicketLength();
	private:
		std::unique_ptr<ISXMode::CountingMode> CreateMode(const ISXMode::TicketsMode& mode, const unsigned int& ticket_length);

		std::unique_ptr<ISXMode::CountingMode> m_counting_mode;
	};
}

