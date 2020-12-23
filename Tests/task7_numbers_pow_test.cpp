#include "pch.h"
#include "Generator.h"
#include "ParserPow.h"
#include "ProgramPow.h"

TEST(ParserTest1, ShouldTrue) {
	std::string number_str = "23423";
	unsigned long long number = 23423;

	ASSERT_EQ(number, ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserTest2, ShouldTrue) {
	std::string number_str = "4543334543";
	unsigned long long number = 4543334543;

	ASSERT_EQ(number, ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserTest3, ShouldTrue) {
	std::string number_str = "0";
	unsigned long long number = 0;

	ASSERT_EQ(number, ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserTest4, ShouldTrue) {
	std::string number_str = "1";
	unsigned long long number = 1;

	ASSERT_EQ(number, ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest1, ShouldWork) {
	std::string number_str = "13243242342342342342342323432432434324";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest2, ShouldWork) {
	std::string number_str = "fefref";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest3, ShouldWork) {
	std::string number_str = "df2342324";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest4, ShouldWork) {
	std::string number_str = "323423423dfdf";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest5, ShouldWork) {
	std::string number_str = "132432dfds43244";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest6, ShouldWork) {
	std::string number_str = "-2323432432434324";

	ASSERT_NO_THROW(ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ParserWrongParamsTest7, ShouldFalse) {
	std::string number_str = "-2323432";
	unsigned long long number = 2323432;

	ASSERT_NE(number, ISXPowParser::Parser::ParseULL(number_str));
}

TEST(ProgramPowTest1, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = {"path", "25"};

	std::string expected_result = "1, 2, 3, 4, 5";

	ASSERT_EQ(expected_result, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest2, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "70" };

	std::string expected_result = "1, 2, 3, 4, 5, 6, 7, 8";

	ASSERT_EQ(expected_result, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest3, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "7234234234234234232430" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest4, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "723fads4232430" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest5, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "sdfdsf" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest6, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "df888" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest7, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "0" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest8, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "-4343" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}

TEST(ProgramPowTest9, ShouldTrue) {
	ISXProgramPow::ProgramPow program;
	const int argc = 2;
	char* argv[argc] = { "path", "343.343" };

	std::string expected_instruction = "Enter number from 1 to 4294967296 and we'll print a series of natural numbers whose square is less than a given number";

	ASSERT_EQ(expected_instruction, program.GetStringPows(argc, argv));
}
