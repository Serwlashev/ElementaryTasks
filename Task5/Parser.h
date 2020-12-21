#pragma once
#include <string>

namespace ISXConverterParser
{
	class Parser
	{
	public:
		static bool IsValid(const std::string& number);
		static int ParseToInt(const std::string& number);
	};
}

