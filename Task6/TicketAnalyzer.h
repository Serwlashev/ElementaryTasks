#pragma once
#include <string>

namespace ISXAnalyzer
{
	enum class TicketsMode {
		Undefined,
		Piter,
		Moscow
	};

	class TicketAnalyzer
	{
	public:
		TicketAnalyzer(const unsigned int ticket_length);
		virtual bool IsLuckyTicket(const std::string& ticket) const = 0;
		unsigned int GetTicketLength() const;
	protected:
		unsigned int m_ticket_length;
	};
}

