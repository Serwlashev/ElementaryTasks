#pragma once
#include <string>

namespace ISXPowParser
{
	class Parser
	{
	public:
		static unsigned long long ParseULL(const std::string& number);
	private:
		static const int max_number_length = 10;

		static bool IsValid(const std::string& number);
	};

}