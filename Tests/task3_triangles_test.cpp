#include "pch.h"

#include "TriangleParser.h"
#include "Triangle.h"
#include "Program.h"

TEST(TriangleParserisValidTest1, ShouldTrue) {
	std::string number = "234234.343";

	ASSERT_EQ(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest2, ShouldTrue) {
	std::string number = "0.1";

	ASSERT_EQ(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest3, ShouldTrue) {
	std::string number = "23423434334.343";

	ASSERT_EQ(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest4, ShouldTrue) {
	std::string number = "1";

	ASSERT_EQ(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest1, ShouldFalse) {
	std::string number = "dfddf";

	ASSERT_NE(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest2, ShouldFalse) {
	std::string number = "23423dfd4.343";

	ASSERT_NE(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest3, ShouldFalse) {
	std::string number = "23423dfd4.343";

	ASSERT_NE(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserisValidTest4, ShouldFalse) {
	std::string number = "-34";

	ASSERT_NE(true, ISXTriangleParser::TriangleParser::IsValid(number));
}

TEST(TriangleParserTest1, ShouldTrue) {
	int number = 324234237.343;
	std::string str = "324234237.343";
	int result_parsing = ISXTriangleParser::TriangleParser::ParseToDouble(str);

	ASSERT_EQ(number, result_parsing);
}

TEST(TriangleParserTest2, ShouldTrue) {
	int number = 0;
	std::string str = "0";
	int result_parsing = ISXTriangleParser::TriangleParser::ParseToDouble(str);

	ASSERT_EQ(number, result_parsing);
}

TEST(TriangleParserTest4, ShouldTrue) {
	int number = -1;
	std::string str = "-1";
	int result_parsing = ISXTriangleParser::TriangleParser::ParseToDouble(str);

	ASSERT_EQ(number, result_parsing);
}

TEST(TriangleParserTest5, ShouldWork) {
	std::string str = "23d7.343";

	ASSERT_NO_THROW(ISXTriangleParser::TriangleParser::ParseToDouble(str));
}

TEST(TriangleParserTest6, ShouldWork) {
	std::string str = "gfgfg";

	ASSERT_NO_THROW(ISXTriangleParser::TriangleParser::ParseToDouble(str));
}

TEST(TriangleParserTest7, ShouldWork) {
	std::string str = "23345345345435345353543533534543333333333343";

	ASSERT_NO_THROW(ISXTriangleParser::TriangleParser::ParseToDouble(str));
}

TEST(TriangleTest1, ShouldTrue) {
	std::string name = "myTriangle";
	double first_side = 3;
	double second_side = 4;
	double third_side = 5;

	ISXTriangle::Triangle triangle(name, first_side, second_side, third_side);

	ASSERT_EQ(name, triangle.GetName());
}

TEST(TriangleTest2, ShouldTrue) {
	std::string name = "myTriangle";
	double first_side = 3;
	double second_side = 4;
	double third_side = 5;

	double semi_perimeter = (first_side + second_side + third_side) / 2;
	double square = std::sqrt(semi_perimeter * (semi_perimeter - first_side) * (semi_perimeter - second_side) * (semi_perimeter - third_side));

	ISXTriangle::Triangle triangle(name, first_side, second_side, third_side);

	ASSERT_EQ(square, triangle.GetSquare());
}

TEST(TriangleTest3, ShouldTrue) {
	std::string name = "myTriangle";
	double first_side = 10;
	double second_side = 14;
	double third_side = 13;

	double semi_perimeter = (first_side + second_side + third_side) / 2;
	double square = std::sqrt(semi_perimeter * (semi_perimeter - first_side) * (semi_perimeter - second_side) * (semi_perimeter - third_side));

	ISXTriangle::Triangle triangle(name, first_side, second_side, third_side);

	std::string expected = "[Triangle " + triangle.GetName() + "]: " + std::to_string(triangle.GetSquare()) + " cm\n";
	ASSERT_EQ(expected, triangle.GetTriangleData());
}

TEST(TriangleTest4, ShouldTrue) {
	std::string name1 = "myTriangle";
	double first_side_1 = 10;
	double second_side_1 = 14;
	double third_side_1 = 13;

	std::string name2 = "mySmallerTriangle";
	double first_side_2 = 4;
	double second_side_2 = 5;
	double third_side_2 = 6;

	ISXTriangle::Triangle triangle(name1, first_side_1, second_side_1, third_side_1);
	ISXTriangle::Triangle smaller_triangle(name2, first_side_2, second_side_2, third_side_2);

	ASSERT_EQ(true, triangle > smaller_triangle);
}

TEST(TriangleTest4, ShouldFalse) {
	std::string name1 = "myTriangle";
	double first_side_1 = 10;
	double second_side_1 = 14;
	double third_side_1 = 13;

	std::string name2 = "mySmallerTriangle";
	double first_side_2 = 4;
	double second_side_2 = 5;
	double third_side_2 = 6;

	ISXTriangle::Triangle triangle(name1, first_side_1, second_side_1, third_side_1);
	ISXTriangle::Triangle smaller_triangle(name2, first_side_2, second_side_2, third_side_2);

	ASSERT_NE(true, triangle < smaller_triangle);
}