#include "pch.h"
#include "FibonacciGenerator.h"
#include "ProgramFibonacci.h"
#include "ParserFibonacci.h"


TEST(FibonacciParserTest1, ShouldTrue) {
	std::string number_str = "23423";
	unsigned long long number = 23423;

	ASSERT_EQ(number, ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserTest2, ShouldTrue) {
	std::string number_str = "4543334543";
	unsigned long long number = 4543334543;

	ASSERT_EQ(number, ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserTest3, ShouldTrue) {
	std::string number_str = "0";
	unsigned long long number = 0;

	ASSERT_EQ(number, ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserTest4, ShouldTrue) {
	std::string number_str = "1";
	unsigned long long number = 1;

	ASSERT_EQ(number, ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest1, ShouldWork) {
	std::string number_str = "13243242342342342342342323432432434324";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest2, ShouldWork) {
	std::string number_str = "fefref";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest3, ShouldWork) {
	std::string number_str = "df2342324";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest4, ShouldWork) {
	std::string number_str = "323423423dfdf";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest5, ShouldWork) {
	std::string number_str = "132432dfds43244";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest6, ShouldWork) {
	std::string number_str = "-2323432432434324";

	ASSERT_NO_THROW(ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(FibonacciParserWrongParamsTest7, ShouldFalse) {
	std::string number_str = "-2323432";
	unsigned long long number = 2323432;

	ASSERT_NE(number, ISXParseFibonacci::ParserFibonacci::ParseULL(number_str));
}

TEST(ProgramFibonacciTest1, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "1", "25" };

	std::string expected_result = "1, 2, 3, 5, 8, 13, 21";

	ASSERT_EQ(expected_result, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest2, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "6", "35" };

	std::string expected_result = "8, 13, 21, 34";

	ASSERT_EQ(expected_result, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest3, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "8", "100" };

	std::string expected_result = "8, 13, 21, 34, 55, 89";

	ASSERT_EQ(expected_result, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest4, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "1", "5000" };

	std::string expected_result = "1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181";

	ASSERT_EQ(expected_result, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest5, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 1;
	char* argv[argc] = { "path"};

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest6, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 2;
	char* argv[argc] = { "path", "221" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest7, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "5000", "1" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest8, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "-4", "10" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest9, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "0", "100" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest10, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "1", "8769767896986897698678678" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest11, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "one", "ten" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest12, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "23", "123j2" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest13, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 3;
	char* argv[argc] = { "path", "", "243.34" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}

TEST(ProgramFibonacciTest14, ShouldTrue) {
	ISXProgrFibonacci::ProgramFibonacci program;
	const int argc = 4;
	char* argv[argc] = { "path", "2", "3", "4" };

	std::string expected_instruction = "To use the programm passed two positive numbers to the main class call and we show all Fibonacci numbers between them";

	ASSERT_EQ(expected_instruction, program.GetFibonacciNumbers(argc, argv));
}