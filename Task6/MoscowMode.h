#pragma once
#include "CountingMode.h"


namespace ISXMoscowMode
{
	class MoscowMode : public ISXMode::CountingMode
	{
	public:
		MoscowMode(const unsigned int& ticket_length);
		bool IsLuckyTicket(const std::string& ticket) const override;
	};
}


