#pragma once
#include <string>
#include "Generator.h"
#include "..\AdditionalClasses\Console.h"

using ISXConsole::Console;
using ISXGenerator::Generator;

namespace ISXProgrammPow
{
	class ProgrammPow
	{
	public:
		ProgrammPow();

		void Start(const int& argc, char** argv);

	private:
		unsigned long long Parse(const std::string& number);
		bool IsCorrectNumber(const std::string& number);
		std::string m_instruction;
	};
}

