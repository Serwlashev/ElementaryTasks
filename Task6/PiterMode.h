#pragma once
#include "CountingMode.h"

namespace ISXPiterMode
{
	class PiterMode : public ISXMode::CountingMode
	{
	public:
		PiterMode(const unsigned int& ticket_length);
		bool IsLuckyTicket(const std::string& ticket) const override;
	};
}



