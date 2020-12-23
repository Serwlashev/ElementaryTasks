#pragma once
#include <string>

namespace ISXParseFibonacci
{
	class ParserFibonacci
	{
	public:
		static unsigned long long ParseULL(const std::string& number);
	private:
		static const int max_numer_length = 10;

		static bool IsValid(const std::string& number);
	};
}

