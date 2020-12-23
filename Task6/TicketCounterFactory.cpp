#include "TicketCounterFactory.h"

std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> ISXTicketFactory::TicketCounterFactory::Create(std::unique_ptr<ISXAnalyzer::TicketAnalyzer> analyzer)
{
    std::unique_ptr<ISXLuckyTickets::LuckyTicketCounter> counter = std::make_unique<ISXLuckyTickets::LuckyTicketCounter>(std::move(analyzer));
    return std::move(counter);
}
