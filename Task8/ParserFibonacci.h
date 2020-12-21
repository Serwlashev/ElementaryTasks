#pragma once
#include <string>

namespace ISXParseFibonacci
{
	class ParserFibonacci
	{
	public:
		static unsigned long long ParseULL(const std::string& number);
	private:
		static bool IsValid(const std::string& number);
	};
}

