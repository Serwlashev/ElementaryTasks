#pragma once
#include <vector>
#include <string>
#include "FibonacciGenerator.h"
#include "ParserFibonacci.h"

using std::string;
using std::vector;
using ISXFibonacci::FibonacciGenerator;
using ISXParseFibonacci::ParserFibonacci;

namespace ISXProgrFibonacci
{
	class ProgramFibonacci
	{
	public:
		ProgramFibonacci();

		string GetFibonacciNumbers(const int& argc, char** argv);

	private:
		vector<unsigned long long> GetNumbers(string start, string end);

		std::string m_instruction;
	};
}

