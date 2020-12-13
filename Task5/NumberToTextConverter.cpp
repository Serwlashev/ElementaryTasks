#include "NumberToTextConverter.h"



void ISXConverter::NumberToTextConverter::InitLibrary()
{
	library.insert(std::make_pair(0, "zero"));
	library.insert(std::make_pair(1, "one"));
	library.insert(std::make_pair(2, "two"));
	library.insert(std::make_pair(3, "three"));
	library.insert(std::make_pair(4, "four"));
	library.insert(std::make_pair(5, "five"));
	library.insert(std::make_pair(6, "six"));
	library.insert(std::make_pair(7, "seven"));
	library.insert(std::make_pair(8, "eight"));
	library.insert(std::make_pair(9, "nine"));
	library.insert(std::make_pair(10, "ten"));
	library.insert(std::make_pair(11, "eleven"));
	library.insert(std::make_pair(12, "twelve"));
	library.insert(std::make_pair(13, "thirteen"));
	library.insert(std::make_pair(14, "fourteen"));
	library.insert(std::make_pair(15, "fifteen"));
	library.insert(std::make_pair(16, "sixteen"));
	library.insert(std::make_pair(17, "seventeen"));
	library.insert(std::make_pair(18, "eighteen"));
	library.insert(std::make_pair(19, "nineteen"));
	library.insert(std::make_pair(20, "twenty"));
	library.insert(std::make_pair(30, "thirty"));
	library.insert(std::make_pair(40, "forty"));
	library.insert(std::make_pair(50, "fifty"));
	library.insert(std::make_pair(60, "sixty"));
	library.insert(std::make_pair(70, "seventy"));
	library.insert(std::make_pair(80, "eighty"));
	library.insert(std::make_pair(90, "ninety"));
	library.insert(std::make_pair(100, "hundred"));
	library.insert(std::make_pair(1000, "thousand"));
	library.insert(std::make_pair(1000000, "million"));
	library.insert(std::make_pair(1000000000, "billion"));

}

ISXConverter::NumberToTextConverter::NumberToTextConverter()
{
	InitLibrary();
}

std::string ISXConverter::NumberToTextConverter::Convert(int number)
{
	std::string result = "";

	if (number < 0) {
		result.append("minus");
		number *= -1;
	}

	if (number == 0) {
		return result.append(library.at(number));
	}

	while (number) {
		if (number >= BILLION) {
			result += ConvertFromThreeDigits(number / BILLION);
			result.append(" " + library.at(BILLION));
			number %= BILLION;
		}
		else if (number >= MILLION) {
			result += ConvertFromThreeDigits(number / MILLION);
			result.append(" " + library.at(MILLION));
			number %= MILLION;
		}
		else if (number >= THOUSAND) {
			result += ConvertFromThreeDigits(number / THOUSAND);
			result.append(" " + library.at(THOUSAND));
			number %= THOUSAND;
		}
		else {
			result.append(ConvertFromThreeDigits(number));
			number /= THOUSAND;
		}
	}

	return result;
}

std::string ISXConverter::NumberToTextConverter::ConvertFromThreeDigits(int number)
{
	std::string result = "";

	if (number >= HUNDRED) {
		result.append(" " + library.at(number / HUNDRED));
		result.append(" " + library.at(HUNDRED));
		number %= HUNDRED;
	}
	if (number > 20) {
		result.append(" " + library.at((number / 10) * 10));
		number %= 10;
	}
	if (number >= 1) {
		result.append(" " + library.at(number));
	}

	return result;
}
