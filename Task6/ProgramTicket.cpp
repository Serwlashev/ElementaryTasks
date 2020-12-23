#include "ProgramTicket.h"

ISXProgramTicket::ProgramTicket::ProgramTicket()
{
	m_instruction = "Pass to the main class call path to the file with algorythm for counting and we'll count lucky tickets according to it";
}

void ISXProgramTicket::ProgramTicket::Start(const int& argc, char** argv)
{
	bool want_continue = true;
	std::string ticket = "";
	std::vector<std::string> tickets;
	ISXMode::TicketsMode ticket_mode;

	if (argc != 2) {
		ISXTicketView::LuckyTicketView::PrintMessage(m_instruction);
		return;
	}
	else {
		ticket_mode = ReadAlgorythmFromFile(argv[1]);
	}

	if (ticket_mode == ISXMode::TicketsMode::Undefined) {
		ISXTicketView::LuckyTicketView::PrintMessage("Cannot find algorythm in the give file");
		return;
	}
	m_ticket_counter = CreateTicketsCounter(ticket_mode);

	while (want_continue) {

		ticket = ISXTicketView::LuckyTicketView::GetStringValue("Please, enter all digits from ticket\n");

		if (ticket.size() == m_ticket_counter.get()->GetTicketLength() && 
			ISXTicketParser::TicketParser::IsValid(ticket)) {
			tickets.push_back(ticket);
		}
		else {
			ISXTicketView::LuckyTicketView::PrintMessage("You entered the wrong ticket!\n");
		}

		want_continue = ISXTicketView::LuckyTicketView::WantContinue();
	}

	ShowCalculatedLuckyTickets(tickets);

	ISXTicketView::LuckyTicketView::PrintMessage("Goodbay!\n");
}

ISXMode::TicketsMode ISXProgramTicket::ProgramTicket::ReadAlgorythmFromFile(const std::string& path)
{
	std::string temp_str;
	std::ifstream is(path, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0, std::ios::beg);

		while (!is.eof()) {
			is >> temp_str;
			if (temp_str.compare("Moscow") == 0) {
				is.close();
				return ISXMode::TicketsMode::Moscow;
			}
			else if (temp_str.compare("Piter") == 0) {
				is.close();
				return ISXMode::TicketsMode::Piter;
			}
		}
		is.close();
	}

	return ISXMode::TicketsMode::Undefined;
}

std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> ISXProgramTicket::ProgramTicket::CreateTicketsCounter(ISXMode::TicketsMode mode)
{
	std::string length_str = ISXTicketView::LuckyTicketView::GetStringValue("Please, enter the length of the ticket. It should be even positive number from 2 to 100\n");

	if (ISXTicketParser::TicketParser::IsValid(length_str)) {
		unsigned int ticket_length = ISXTicketParser::TicketParser::ParseToUI(length_str);

		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> counter = std::make_unique<ISXLuckyTickets::LuckyTicketCounter>(mode, ticket_length);

		return std::move(counter);
	}
	return nullptr;
}

void ISXProgramTicket::ProgramTicket::ShowCalculatedLuckyTickets(const std::vector<std::string>& tickets)
{
	if (m_ticket_counter) {
		int count = m_ticket_counter.get()->CountTickets(tickets);
		ISXTicketView::LuckyTicketView::PrintMessage("You entered " + std::to_string(count) + " lucky tickets\n");
	}
	else {
		ISXTicketView::LuckyTicketView::PrintMessage("Cannot calculate lucky tickets!\n");
	}
}
