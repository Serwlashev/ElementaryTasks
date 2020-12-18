#pragma once
#include <string>

namespace ISXMode
{
	enum class TicketsMode {
		Undefined,
		Piter,
		Moscow
	};

	class CountingMode
	{
	public:
		CountingMode(const unsigned int& ticket_length);
		virtual bool IsLuckyTicket(const std::string& ticket) const = 0;
		unsigned int GetTicketLength() const;
	protected:
		unsigned int m_ticket_length;
	};
}

