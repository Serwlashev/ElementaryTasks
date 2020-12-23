#include "pch.h"
#include "../Task2/Envelope.h"
#include "../Task2/EnvelopeParser.h"

TEST(ParserTest, ShouldEqual) {
	std::string num_str = "234.4";
	double num = 234.4;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest2, ShouldEqual) {
	std::string num_str = "0";
	double num = 0;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest3, ShouldEqual) {
	std::string num_str = "2432";
	double num = 2432;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest4, ShouldEqual) {
	std::string num_str = "234.42343";
	double num = 234.42343;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest5, ShouldEqual) {
	std::string num_str = "34341231231";
	double num = 34341231231;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest6, ShouldEqual) {
	std::string num_str = "-12321";			// we ignore negative params
	double num = -1;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest7, ShouldEqual) {
	std::string num_str = "-34321.3434";
	double num = -1;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserTest8, ShouldEqual) {
	std::string num_str = "-19874679845.6234234";
	double num = -1;
	ASSERT_EQ(num, ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest1, ShouldWork) {
	std::string num_str = "23d4.4";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest2, ShouldWork) {
	std::string num_str = "234.34234d4";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest3, ShouldWork) {
	std::string num_str = "23d4.4";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest4, ShouldWork) {
	std::string num_str = "df2334344.4";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest5, ShouldWork) {
	std::string num_str = "fsdfs";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest6, ShouldWork) {
	std::string num_str = "-234234-334";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest7, ShouldWork) {
	std::string num_str = "22342342342334655676586786786787686868768768768678678678678678686786886867867867867878678345345345345345456767869462657687654364";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(ParserWrongParameterTest8, ShouldWork) {
	std::string num_str = "23d4.4";

	ASSERT_NO_THROW(ISXEnvelopeParser::EnvelopeParser::ParseToDouble(num_str));
}

TEST(EnvelopeTest1, ShouldTrue) {
	double height = 15;
	double width = 34;

	ISXEnvelope::Envelope env(height, 34);
	ASSERT_EQ(height, env.GetHeight());
	ASSERT_EQ(width, env.GetWidth());
}

TEST(EnvelopeTest2, ShouldTrue) {
	double height = 23432.3434;
	double width = 54646456.990535;

	ISXEnvelope::Envelope env(height, width);
	ASSERT_EQ(height, env.GetHeight());
	ASSERT_EQ(width, env.GetWidth());
}

TEST(EnvelopeChangeTest, ShouldTrue) {
	double width = 23432.3434;
	double height = 54646456.990535;

	ISXEnvelope::Envelope env(height, width);
	ASSERT_EQ(width, env.GetHeight());
	ASSERT_EQ(height, env.GetWidth());
}

TEST(EnvelopeCompareTest, ShouldTrue) {
	ISXEnvelope::Envelope env1(34, 23);
	ISXEnvelope::Envelope env2(53, 24);

	ASSERT_EQ(true, env2 > env1);
}

TEST(EnvelopeCompareTest2, ShouldTrue) {
	ISXEnvelope::Envelope env1(676, 5564);
	ISXEnvelope::Envelope env2(676.1, 5564.09);

	ASSERT_EQ(true, env2 > env1);
}

TEST(EnvelopeCompareTest3, ShouldFalse) {
	ISXEnvelope::Envelope env1(676, 5564);
	ISXEnvelope::Envelope env2(676.00001, 5564.000009);

	ASSERT_NE(true, env2 > env1);
}

TEST(EnvelopeCompareTest4, ShouldFalse) {
	ISXEnvelope::Envelope env1(676, 5564);
	ISXEnvelope::Envelope env2(676.1, 5563);

	ASSERT_NE(true, env2 > env1);
}

TEST(EnvelopeCompareTest5, ShouldFalse) {
	ISXEnvelope::Envelope env1(23, 14);
	ISXEnvelope::Envelope env2(50, 10);

	ASSERT_NE(true, env2 > env1);
}

TEST(EnvelopeCompareTest6, ShouldFalse) {
	ISXEnvelope::Envelope env1(23.32, 14.2);
	ISXEnvelope::Envelope env2(50, 14.1);

	ASSERT_NE(true, env2 > env1);
}