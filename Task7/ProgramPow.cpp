#include "ProgramPow.h"

ISXProgramPow::ProgramPow::ProgramPow()
{
	m_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number"; 
}

string ISXProgramPow::ProgramPow::GetStringPows(const int& argc, char** argv)
{
	string result = "";

	if (argc != 2) {
		result = m_instruction;
	}
	else {
		unsigned long long number = Parser::ParseULL(argv[1]);

		if (number >= Generator::GetMinAllowedNumber() && number <= Generator::GetMaxAllowedNumber()) {

			Generator start;
			Generator end(number);
			for (auto it = start; it <= end; ++it) {
				result += std::to_string(*it);
				result += ", ";
			}
		}
		else {
			result = m_instruction;
		}
	}
	

	return result;
}

