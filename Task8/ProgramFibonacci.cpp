#include "ProgramFibonacci.h"

ISXProgrFibonacci::ProgramFibonacci::ProgramFibonacci()
{
	m_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";
}

void ISXProgrFibonacci::ProgramFibonacci::Start(const int& argc, char** argv)
{
	if (argc != 3) {
		Console::PrintMessage("You passed wrong number of parameters!");
		Console::PrintMessage(m_instruction);
		return;
	}

	vector<unsigned long long> numbers = GetNumbers(argv[1], argv[2]);

	if (!numbers.empty()) {
		for (auto it = numbers.begin(); it != numbers.end(); it++) {
			Console::PrintMessage(std::to_string(*it) + " ");
		}
	}
	else {
		Console::PrintMessage(m_instruction);
	}
}

vector<unsigned long long> ISXProgrFibonacci::ProgramFibonacci::GetNumbers(string start_num, string end_num)
{
	vector<unsigned long long> result = result;


	if (Validator::IsValid(ISXValidator::ValidationMode::UnsignedLongLong, start_num) && Validator::IsValid(ISXValidator::ValidationMode::UnsignedLongLong, end_num)) {
		unsigned long long num_min = Converter::ConvertToULL(start_num);
		unsigned long long num_max = Converter::ConvertToULL(end_num);

		if (num_min >= FibonacciGenerator::GetMinAlowedNumber() && num_min <= FibonacciGenerator::GetMaxAlowedNumber() && num_max >= FibonacciGenerator::GetMinAlowedNumber() && num_max <= FibonacciGenerator::GetMaxAlowedNumber()) {

			FibonacciGenerator start(num_min, num_max);
			FibonacciGenerator end(num_max);
			for (FibonacciGenerator it = start; it != end; ++it) {
				result.push_back(*it);
			}
		}
	}

	return result;
}
