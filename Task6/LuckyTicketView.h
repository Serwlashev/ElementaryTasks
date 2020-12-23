#pragma once
#include <iostream>
#include <string>

namespace ISXTicketView
{
	class LuckyTicketView
	{
	public:
		static bool WantContinue();
		static void PrintMessage(const std::string& message);
		static std::string GetStringValue(const std::string& message);
	};
}

