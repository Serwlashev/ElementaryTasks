#pragma once
#include <string>
#include "Generator.h"
#include "ParserPow.h"

using ISXPowParser::Parser;
using ISXGenerator::Generator;

namespace ISXProgramPow
{
	class ProgramPow
	{
	public:
		ProgramPow();

		std::string GetStringPows(const int argc, char** argv);

	private:
		const int num_required_params = 2;

		std::string m_instruction;
	};
}

