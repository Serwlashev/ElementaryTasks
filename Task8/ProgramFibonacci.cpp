#include "ProgramFibonacci.h"

ISXProgrFibonacci::ProgramFibonacci::ProgramFibonacci()
{
	m_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";
}

std::string ISXProgrFibonacci::ProgramFibonacci::GetFibonacciNumbers(const int argc, char** argv)
{
	std::string result;
	if (argc != num_requried_params) {
		result = m_instruction;
	}
	else {

		std::vector<unsigned long long> numbers = GetNumbers(argv[1], argv[2]);

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

std::vector<unsigned long long> ISXProgrFibonacci::ProgramFibonacci::GetNumbers(const std::string& start_num, const std::string& end_num)
{
	std::vector<unsigned long long> result = result;

	unsigned long long num_min = ParserFibonacci::ParseULL(start_num);
	unsigned long long num_max = ParserFibonacci::ParseULL(end_num);

	if (num_min >= ISXFibonacci::FibonacciGenerator::GetMinAlowedNumber() && num_min <= ISXFibonacci::FibonacciGenerator::GetMaxAlowedNumber() &&
		num_max >= ISXFibonacci::FibonacciGenerator::GetMinAlowedNumber() && num_max <= ISXFibonacci::FibonacciGenerator::GetMaxAlowedNumber()) {

		ISXFibonacci::FibonacciGenerator start(num_min, num_max);
		ISXFibonacci::FibonacciGenerator end(num_max);
		for (ISXFibonacci::FibonacciGenerator it = start; it != end; ++it) {
			result.push_back(*it);
		}
	}

	return result;
}
