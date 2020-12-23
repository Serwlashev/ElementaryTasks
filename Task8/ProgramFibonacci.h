#pragma once
#include <vector>
#include <string>
#include "FibonacciGenerator.h"
#include "ParserFibonacci.h"


using ISXParseFibonacci::ParserFibonacci;

namespace ISXProgrFibonacci
{
	class ProgramFibonacci
	{
	public:
		ProgramFibonacci();

		std::string GetFibonacciNumbers(const int argc, char** argv);

	private:
		const int num_requried_params = 3;

		std::vector<unsigned long long> GetNumbers(const std::string& start, const std::string& end);

		std::string m_instruction;
	};
}

