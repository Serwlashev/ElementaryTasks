#pragma once
#include <string>
#include "Generator.h"
#include "ParserPow.h"

using ISXPowParser::Parser;
using std::string;
using ISXGenerator::Generator;

namespace ISXProgramPow
{
	class ProgramPow
	{
	public:
		ProgramPow();

		string GetStringPows(const int& argc, char** argv);

	private:
		std::string m_instruction;
	};
}
