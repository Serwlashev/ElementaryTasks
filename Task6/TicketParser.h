#pragma once
#include <string>

namespace ISXTicketParser
{
	class TicketParser
	{
	public:
		static unsigned int ParseToUI(const std::string& number);
		static bool IsValid(const std::string& number);
	private:
		static const int max_allowed_length = 10;
	};
}

