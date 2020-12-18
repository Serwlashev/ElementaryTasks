#include "ProgramTickets.h"

ISXProgramTickets::ProgramTickets::ProgramTickets()
{

}

void ISXProgramTickets::ProgramTickets::Start(const int& argc, char** argv)
{
	bool want_continue = true;
	string ticket = "";
	vector<string> tickets;
	ISXMode::TicketsMode ticket_mode;

	if (argc != 2) {
		ConsoleMngr::PrintInstruction();
		return;
	}
	else {
		ticket_mode = ReadAlgorythmFromFile(argv[1]);
	}

	if (ticket_mode == ISXMode::TicketsMode::Undefined) {
		ConsoleMngr::PrintMessage("Cannot find algorythm in the give file");
		return;
	}
	m_ticket_counter = CreateTicketsCounter(ticket_mode);

	while (want_continue) {

		ticket = ConsoleMngr::EnterNumber("Please, enter all digits from ticket\n");

		if (ticket.size() == m_ticket_counter.get()->GetTicketLength() && 
			ISXValidator::Validator::IsValid(ISXValidator::ValidationMode::UnsignedInteger, ticket)) {
			tickets.push_back(ticket);
		}
		else {
			ConsoleMngr::PrintMessage("You entered the wrong ticket!\n");
		}

		want_continue = ConsoleMngr::WantContinue();
	}

	ShowCalculatedLuckyTickets(tickets);

	ConsoleMngr::PrintMessage("Goodbay!\n");
}

ISXMode::TicketsMode ISXProgramTickets::ProgramTickets::ReadAlgorythmFromFile(const std::string& path)
{
	string temp_str;
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


unsigned int ISXProgramTickets::ProgramTickets::GetTicketLength()
{
	unsigned int length = 0;
	string length_str; 

	while (true) {
		length_str = ConsoleMngr::EnterNumber("Please, enter the length of the ticket. It should be even positive number from 2 to 100\n");

		if (ISXValidator::Validator::IsValid(ISXValidator::ValidationMode::UnsignedInteger, length_str)) {
			length = stoi(length_str);
			if (length >= 2 && length <= 100 && length_str.length() % 2 != 0) {
				break;
			}
		}
	}
	return length;
}

std::unique_ptr<LuckyTicketCounter> ISXProgramTickets::ProgramTickets::CreateTicketsCounter(ISXMode::TicketsMode mode)
{
	unsigned int ticket_length = GetTicketLength();

	std::unique_ptr<LuckyTicketCounter> counter = std::make_unique<LuckyTicketCounter>(mode, ticket_length);

	return std::move(counter);
}

void ISXProgramTickets::ProgramTickets::ShowCalculatedLuckyTickets(const vector<string>& tickets)
{
	if (m_ticket_counter) {
		int count = m_ticket_counter.get()->CountTickets(tickets);
			ConsoleMngr::PrintMessage("You entered " + std::to_string(count) + " lucky tickets\n");
	}
	else {
		ConsoleMngr::PrintMessage("Cannot calculate lucky tickets!\n");
	}
}
