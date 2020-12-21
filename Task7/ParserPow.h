#pragma once
#include <string>

namespace ISXPowParser
{
	class Parser
	{
	public:
		static unsigned long long ParseULL(const std::string& number);
	private:
		static bool IsValid(const std::string& number);

	};

}