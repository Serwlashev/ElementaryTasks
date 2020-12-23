#include "ProgramFibonacci.h"

ISXProgrFibonacci::ProgramFibonacci::ProgramFibonacci()
{
	m_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";
}

string ISXProgrFibonacci::ProgramFibonacci::GetFibonacciNumbers(const int& argc, char** argv)
{
	string result = "";
	if (argc != 3) {
		result = m_instruction;
	}
	else {

		vector<unsigned long long> numbers = GetNumbers(argv[1], argv[2]);

		if (!numbers.empty()) {
			for (auto it = numbers.begin(); it != numbers.end(); it++) {
				if (it > numbers.begin()) {
					result.append(", ");
				}
				result.append(std::to_string(*it));
			}
		}
		else {
			result = m_instruction;
		}
	}

	return result;
}

vector<unsigned long long> ISXProgrFibonacci::ProgramFibonacci::GetNumbers(string start_num, string end_num)
{
	vector<unsigned long long> result = result;

	unsigned long long num_min = ParserFibonacci::ParseULL(start_num);
	unsigned long long num_max = ParserFibonacci::ParseULL(end_num);

	if (num_min >= FibonacciGenerator::GetMinAlowedNumber() && num_min <= FibonacciGenerator::GetMaxAlowedNumber() && num_max >= FibonacciGenerator::GetMinAlowedNumber() && num_max <= FibonacciGenerator::GetMaxAlowedNumber()) {

		FibonacciGenerator start(num_min, num_max);
		FibonacciGenerator end(num_max);
		for (FibonacciGenerator it = start; it != end; ++it) {
			result.push_back(*it);
		}
	}

	return result;
}
