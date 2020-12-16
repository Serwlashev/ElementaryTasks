#pragma once

#include "FibonacciGenerator.h"
#include "MngrConsole.h"

using ISXFibonacci::FibonacciGenerator;
using ISXMngrConsole::MngrConsole;

namespace ISXProgrFibonacci
{
	class ProgramFibonacci
	{
	public:
		ProgramFibonacci();

		void Start(const int& argc, char** argv);

	private:
		unsigned long long Parse(const std::string& number);
		bool IsCorrectNumber(const std::string& number);

		std::string m_instruction;
	};
}

