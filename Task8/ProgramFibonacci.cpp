#include "ProgramFibonacci.h"

ISXProgrFibonacci::ProgramFibonacci::ProgramFibonacci()
{
	m_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";
}

void ISXProgrFibonacci::ProgramFibonacci::Start(const int& argc, char** argv)
{
	if (argc != 3) {
		MngrConsole::PrintMessage("You passed wrong number of parameters!");
		MngrConsole::PrintMessage(m_instruction);
		return;
	}

	unsigned long long num_min = Parse(argv[1]);
	unsigned long long num_max = Parse(argv[2]);

	if (num_min >= 1 && num_min <= 4294967296 && num_max >= 1 && num_max <= 4294967296) {

		FibonacciGenerator start(num_min, num_max);
		FibonacciGenerator end(num_max);
		for (FibonacciGenerator it = start; it != end; ++it) {
			MngrConsole::PrintMessage(std::to_string(*it));
			MngrConsole::PrintMessage(", ");
		}
	}
	else {
		MngrConsole::PrintMessage(m_instruction);
	}
}

unsigned long long ISXProgrFibonacci::ProgramFibonacci::Parse(const std::string& number)
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

bool ISXProgrFibonacci::ProgramFibonacci::IsCorrectNumber(const std::string& number)
{
	for (size_t i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}