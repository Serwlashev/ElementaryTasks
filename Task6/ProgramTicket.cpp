#include "ProgramTicket.h"

ISXProgramTicket::ProgramTicket::ProgramTicket()
{
	m_instruction = "Pass to the main class call path to the file with algorythm for counting and we'll count lucky tickets according to it";
}

void ISXProgramTicket::ProgramTicket::Start(const int argc, char** argv)
{
	bool want_continue = true;
	std::string ticket;
	std::vector<std::string> tickets;
	ISXAnalyzer::TicketsMode ticket_mode;

	if (argc != num_required_params) {
		ISXTicketView::LuckyTicketView::PrintMessage(m_instruction);
		return;
	}
	else {
		ticket_mode = ReadAlgorythmFromFile(argv[1]);
	}

	if (ticket_mode == ISXAnalyzer::TicketsMode::Undefined) {
		ISXTicketView::LuckyTicketView::PrintMessage("Cannot find algorythm in the give file");
		return;
	}
	m_ticket_counter = CreateTicketsCounter(ticket_mode);

	while (want_continue) {

		ticket = ISXTicketView::LuckyTicketView::GetStringValue("Please, enter all digits from ticket\n");

		if (ISXTicketParser::TicketParser::IsValid(ticket)) {
			tickets.push_back(ticket);
		}
		else {
			ISXTicketView::LuckyTicketView::PrintMessage("You entered the wrong ticket!\n");
		}

		want_continue = ISXTicketView::LuckyTicketView::WantContinue();
	}

	ISXTicketView::LuckyTicketView::PrintMessage(GetNumLuckyTickets(tickets));

	ISXTicketView::LuckyTicketView::PrintMessage("Goodbay!\n");
}

ISXAnalyzer::TicketsMode ISXProgramTicket::ProgramTicket::ReadAlgorythmFromFile(const std::string& path)
{
	std::string temp_str;
	std::ifstream is(path, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0, std::ios::beg);

		while (!is.eof()) {
			is >> temp_str;
			if (temp_str.compare("Moscow") == 0 || temp_str.compare("moscow") == 0) {
				is.close();
				return ISXAnalyzer::TicketsMode::Moscow;
			}
			else if (temp_str.compare("Piter") == 0 || temp_str.compare("poscow") == 0) {
				is.close();
				return ISXAnalyzer::TicketsMode::Piter;
			}
		}
		is.close();
	}

	return ISXAnalyzer::TicketsMode::Undefined;
}

std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> ISXProgramTicket::ProgramTicket::CreateTicketsCounter(ISXAnalyzer::TicketsMode mode)
{
	std::string length_str = ISXTicketView::LuckyTicketView::GetStringValue("Please, enter the length of the ticket. It should be even positive number from 2 to 100\n");

	if (ISXTicketParser::TicketParser::IsValid(length_str)) {
		unsigned int ticket_length = ISXTicketParser::TicketParser::ParseToUI(length_str);

		std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> counter = ISXTicketFactory::TicketCounterFactory::Create(ISXAnalyzerFactory::TicketAnalyzerFactory::Create(mode, ticket_length));

		return std::move(counter);
	}
	return nullptr;
}

std::string ISXProgramTicket::ProgramTicket::GetNumLuckyTickets(const std::vector<std::string>& tickets)
{
	std::string result;

	if (m_ticket_counter) {
		int num_tickets = m_ticket_counter.get()->CountTickets(tickets.begin(), tickets.end());
		result += std::to_string(num_tickets);
		result += num_tickets > 1 ? " lucky tickets were passed" : " lucky ticket was passed";
	}
	else {
		result = "Cannot count lucky tickets, you passed wrong parameters for the ticket counter";
	}
	return result;
}
