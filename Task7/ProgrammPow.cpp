#include "ProgrammPow.h"

ISXProgrammPow::ProgrammPow::ProgrammPow()
{
	m_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number"; 
}

void ISXProgrammPow::ProgrammPow::Start(const int& argc, char** argv)
{
	if (argc != 2) {
		ManagerConsole::PrintMessage("You passed wrong number of parameters!");
		ManagerConsole::PrintMessage(m_instruction);
		return;
	}
	
	unsigned long long number = Parse(argv[1]);

	if (number >= 1 && number <= 4294967296) {

		Generator start;
		Generator end(number);
		for (auto it = start; it != end; ++it) {
			ManagerConsole::PrintMessage(std::to_string(*it));
			ManagerConsole::PrintMessage(", ");
		}
	}
	else {
		ManagerConsole::PrintMessage(m_instruction);
	}
}

unsigned long long ISXProgrammPow::ProgrammPow::Parse(const std::string& number)
{
	unsigned long long res = 0;

	if (!number.empty() && number != " " && number.size() <= 10 && IsCorrectNumber(number)) {
		res = std::stoull(number);
	}

	if (number.compare(std::to_string(res)) != 0) {
		res = 0;
	}

	return res;
}

bool ISXProgrammPow::ProgrammPow::IsCorrectNumber(const std::string& number)
{
	for (size_t i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}
