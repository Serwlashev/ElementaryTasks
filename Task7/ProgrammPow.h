#pragma once
#include <string>
#include "ManagerConsole.h"
#include "Generator.h"

using ISXManagerConsole::ManagerConsole;
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

