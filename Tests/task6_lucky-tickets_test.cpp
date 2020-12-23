#include "pch.h"
#include "../Task6/CountingMode.h"
#include "../Task6/PiterMode.h"
#include "../Task6/MoscowMode.h"
#include "../Task6/LuckyTicketCounter.h"
#include "../Task6/TicketParser.h"

TEST(MoscowModeTest1, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "654456";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeTest2, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "365383";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeTest3, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "900261";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeTest4, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "110002";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeTest5, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(4);
	std::string ticket = "3609";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeTest6, ShouldTrue) {
	ISXMoscowMode::MoscowMode mode(10);
	std::string ticket = "4806759434";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeFalseTest1, ShouldFalse) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "110092";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeFalseTest2, ShouldFalse) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "78667666";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeFalseTest3, ShouldFalse) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "56500000";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(MoscowModeFalseTest4, ShouldFalse) {
	ISXMoscowMode::MoscowMode mode(6);
	std::string ticket = "34";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeTest1, ShouldTrue) {
	ISXPiterMode::PiterMode mode(6);
	std::string ticket = "268235";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeTest2, ShouldTrue) {
	ISXPiterMode::PiterMode mode(2);
	std::string ticket = "55";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeTest3, ShouldTrue) {
	ISXPiterMode::PiterMode mode(4);
	std::string ticket = "3740";

	ASSERT_EQ(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeFalseTest1, ShouldFalse) {
	ISXPiterMode::PiterMode mode(4);
	std::string ticket = "34";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeFalseTest2, ShouldFalse) {
	ISXPiterMode::PiterMode mode(4);
	std::string ticket = "4546544";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(PiterModeFalseTest3, ShouldFalse) {
	ISXPiterMode::PiterMode mode(6);
	std::string ticket = "666000";

	ASSERT_NE(true, mode.IsLuckyTicket(ticket));
}

TEST(TicketParserIsValidTest, ShouldTrue) {
	std::string ticket1 = "666000";
	std::string ticket2 = "2222";
	std::string ticket3 = "33333333";
	std::string ticket4 = "3333333333";
	std::string ticket5 = "333333333333";

	ASSERT_EQ(true, ISXTicketParser::TicketParser::IsValid(ticket1));
	ASSERT_EQ(true, ISXTicketParser::TicketParser::IsValid(ticket2));
	ASSERT_EQ(true, ISXTicketParser::TicketParser::IsValid(ticket3));
	ASSERT_EQ(true, ISXTicketParser::TicketParser::IsValid(ticket4));
	ASSERT_EQ(true, ISXTicketParser::TicketParser::IsValid(ticket5));
}

TEST(TicketParserFalseTestLetters, ShouldFalse) {
	std::string ticket1 = "666dfd000";
	std::string ticket2 = "dfs2222";
	std::string ticket3 = "33333dfs";
	std::string ticket4 = "dsfsdf";
	std::string ticket5 = "333!3333333";

	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket1));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket2));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket3));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket4));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket5));
}

TEST(TicketParserFalseTestPoints, ShouldFalse) {
	std::string ticket1 = "343.";
	std::string ticket2 = "242343.0";
	std::string ticket3 = "3.34434";
	std::string ticket4 = "4343.3434";

	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket1));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket2));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket3));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket4));
}

TEST(TicketParserFalseTestMinus, ShouldFalse) {
	std::string ticket1 = "-343";
	std::string ticket2 = "-43243423";

	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket1));
	ASSERT_NE(true, ISXTicketParser::TicketParser::IsValid(ticket2));
}

TEST(TicketParserParseTest, ShouldTrue) {
	std::string ticket1 = "666000";
	std::string ticket2 = "2222";
	std::string ticket3 = "33333333";
	std::string ticket5 = "234223";

	int number1 = 666000;
	int number2 = 2222;
	int number3 = 33333333;
	int number5 = 234223;

	ASSERT_EQ(number1, ISXTicketParser::TicketParser::ParseToUI(ticket1));
	ASSERT_EQ(number2, ISXTicketParser::TicketParser::ParseToUI(ticket2));
	ASSERT_EQ(number3, ISXTicketParser::TicketParser::ParseToUI(ticket3));
	ASSERT_EQ(number5, ISXTicketParser::TicketParser::ParseToUI(ticket5));
}

TEST(TicketParserParseTest, WithoutErrs) {
	std::string ticket1 = "666234234000";
	std::string ticket2 = "-3432432234222";
	std::string ticket3 = "333dfd33333";
	std::string ticket4 = "df234223";
	std::string ticket5 = "2342f23";
	std::string ticket6 = "df234223f";

	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket1));
	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket2));
	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket3));
	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket4));
	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket5));
	ASSERT_NO_THROW(ISXTicketParser::TicketParser::ParseToUI(ticket6));
}

TEST(LuckyTicketCounterTest, ShouldTrue) {
	const unsigned int ticket_length = 6;
	ISXLuckyTickets::LuckyTicketCounter counter(ISXMode::TicketsMode::Moscow, ticket_length);

	std::vector<std::string> tickets;
	tickets.push_back("456456");
	tickets.push_back("555555");
	tickets.push_back("367934");
	tickets.push_back("933456");

	ASSERT_EQ(4, counter.CountTickets(tickets));
}

TEST(LuckyTicketCounterFalseTest, ShouldTrue) {
	const unsigned int ticket_length = 6;
	ISXLuckyTickets::LuckyTicketCounter counter(ISXMode::TicketsMode::Moscow, ticket_length);

	std::vector<std::string> tickets;
	tickets.push_back("123456");
	tickets.push_back("23");
	tickets.push_back("3679323234");
	tickets.push_back("778323");

	ASSERT_EQ(0, counter.CountTickets(tickets));
}

TEST(LuckyTicketLengthTest, ShouldTrue) {
	const unsigned int ticket_length = 6;
	ISXLuckyTickets::LuckyTicketCounter counter(ISXMode::TicketsMode::Moscow, ticket_length);

	ASSERT_EQ(ticket_length, counter.GetTicketLength());
}