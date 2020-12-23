#include "pch.h"
#include "../Task5/NumberConverter.h"
#include "../Task5/NumberToTextConverter.h"
#include "../Task5/Parser.h"

TEST(ParserValidationTest, ShouldTrue) {
	std::string number1 = "1234";
	std::string number2 = "-2342";
	std::string number3 = "0";
	std::string number4 = "23424233";

	EXPECT_EQ(true, ISXConverterParser::Parser::IsValid(number1));
	EXPECT_EQ(true, ISXConverterParser::Parser::IsValid(number2));
	EXPECT_EQ(true, ISXConverterParser::Parser::IsValid(number3));
	EXPECT_EQ(true, ISXConverterParser::Parser::IsValid(number4));
}

TEST(ParserValidationTestLetters, ShouldFalse) {
	std::string number1 = "234234f";
	std::string number2 = "sdfdsf";
	std::string number3 = "889dffd";
	std::string number4 = "-234-24233";

	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number1));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number2));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number3));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number4));
}

TEST(ParserValidationTestFloating, ShouldFalse) {
	std::string number1 = "234.23909";
	std::string number2 = "234234.4";
	std::string number3 = "324.";
	std::string number4 = "23432.0";

	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number1));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number2));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number3));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number4));
}

TEST(ParserValidationTestTooLong, ShouldFalse) {
	std::string number1 = "234234234234323909";
	std::string number2 = "-234234234234323909";

	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number1));
	EXPECT_NE(true, ISXConverterParser::Parser::IsValid(number2));
}

TEST(ParserToIntTest, ShouldTrue) {
	std::string number1 = "1234";
	std::string number2 = "-2342";
	std::string number3 = "0";
	std::string number4 = "23424233";

	int num_int_1 = 1234;
	int num_int_2 = -2342;
	int num_int_3 = 0;
	int num_int_4 = 23424233;

	EXPECT_EQ(num_int_1, ISXConverterParser::Parser::ParseToInt(number1));
	EXPECT_EQ(num_int_2, ISXConverterParser::Parser::ParseToInt(number2));
	EXPECT_EQ(num_int_3, ISXConverterParser::Parser::ParseToInt(number3));
	EXPECT_EQ(num_int_4, ISXConverterParser::Parser::ParseToInt(number4));
}

TEST(ParserToIntTestLetters, ShouldTrue) {
	std::string number1 = "123sdf4";
	std::string number2 = "-23-42";
	std::string number3 = "d0";
	std::string number4 = "2342423df";

	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number1));
	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number2));
	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number3));
	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number4));
}

TEST(ParserToIntTestTooLong, ShouldTrue) {
	std::string number1 = "4534534534534";
	std::string number2 = "-34543534534543543";

	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number1));
	EXPECT_NO_THROW(ISXConverterParser::Parser::ParseToInt(number2));
}

TEST(ParserToIntTestFloatingPoint, ShouldTrue) {
	std::string number1 = "4534.34";
	std::string number2 = "-345.0";

	int num1 = 4534;
	int num2 = -345;

	EXPECT_NE(num1, ISXConverterParser::Parser::IsValid(number1));
	EXPECT_NE(num2, ISXConverterParser::Parser::IsValid(number2));
}

TEST(NumToTextTest, ShouldTrue) {
	std::string number_text= "four thousand five hundred thirty four";
	int number = 4534;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest1, ShouldTrue) {
	std::string number_text = "four thousand five hundred thirty four";
	int number = 4534;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest2, ShouldTrue) {
	std::string number_text = "zero";
	int number = 0;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest3, ShouldTrue) {
	std::string number_text = "minus two million four hundred one";
	int number = -2000401;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest4, ShouldTrue) {
	std::string number_text = "one billion seven hundred twenty two million four hundred eighty six thousand twenty";
	int number = 1722486020;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest5, ShouldTrue) {
	std::string number_text = "fourteen";
	int number = 14;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest6, ShouldTrue) {
	std::string number_text = "one";
	int number = 1;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest7, ShouldTrue) {
	std::string number_text = "minus twenty two";
	int number = -22;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumToTextTest8, ShouldTrue) {
	std::string number_text = "one million one";
	int number = 1000001;

	ISXNumberConverter::NumberToTextConverter converter;

	EXPECT_EQ(number_text, converter.Convert(number));
}

TEST(NumberConverterTest1, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "-1000001" };
	std::string result_number = "minus one million one";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterTest2, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "-89200034" };
	std::string result_number = "minus eighty nine million two hundred thousand thirty four";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterTest3, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "0" };
	std::string result_number = "zero";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterTest4, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "18" };
	std::string result_number = "eighteen";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest1, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "1000dfd001" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest2, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "uiu" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest3, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "-8888888886766" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest4, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "2234242342342343244" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest5, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "-23423.3" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}

TEST(NumberConverterWrongParamTest6, ShouldTrue) {
	const int argc = 2;
	char* argv[argc] = { "path", "0.0" };
	std::string result_number = "You passed wrong number!";

	ISXConverter::NumberConverter converter;

	EXPECT_EQ(result_number, converter.ShowNumberAsText(argc, argv));
}