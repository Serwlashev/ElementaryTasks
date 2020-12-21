#pragma once
#include <vector>
#include <string>
#include "FibonacciGenerator.h"
#include "../AdditionalClasses/Console.h"
#include "../AdditionalClasses/Validator.h"
#include "../AdditionalClasses//Converter.h"

using std::string;
using std::vector;
using ISXNumberConverter::Converter;
using ISXValidator::Validator;
using ISXConsole::Console;
using ISXFibonacci::FibonacciGenerator;

namespace ISXProgrFibonacci
{
	class ProgramFibonacci
	{
	public:
		ProgramFibonacci();

		void Start(const int& argc, char** argv);

	private:
		vector<unsigned long long> GetNumbers(string start, string end);

		std::string m_instruction;
	};
}

