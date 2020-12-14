#include "NumberToTextConverter.h"

void ISXNumberConverter::NumberToTextConverter::InitLibrary()
{
	m_library.insert(std::make_pair(0, "zero"));
	m_library.insert(std::make_pair(1, "one"));
	m_library.insert(std::make_pair(2, "two"));
	m_library.insert(std::make_pair(3, "three"));
	m_library.insert(std::make_pair(4, "four"));
	m_library.insert(std::make_pair(5, "five"));
	m_library.insert(std::make_pair(6, "six"));
	m_library.insert(std::make_pair(7, "seven"));
	m_library.insert(std::make_pair(8, "eight"));
	m_library.insert(std::make_pair(9, "nine"));
	m_library.insert(std::make_pair(10, "ten"));
	m_library.insert(std::make_pair(11, "eleven"));
	m_library.insert(std::make_pair(12, "twelve"));
	m_library.insert(std::make_pair(13, "thirteen"));
	m_library.insert(std::make_pair(14, "fourteen"));
	m_library.insert(std::make_pair(15, "fifteen"));
	m_library.insert(std::make_pair(16, "sixteen"));
	m_library.insert(std::make_pair(17, "seventeen"));
	m_library.insert(std::make_pair(18, "eighteen"));
	m_library.insert(std::make_pair(19, "nineteen"));
	m_library.insert(std::make_pair(20, "twenty"));
	m_library.insert(std::make_pair(30, "thirty"));
	m_library.insert(std::make_pair(40, "forty"));
	m_library.insert(std::make_pair(50, "fifty"));
	m_library.insert(std::make_pair(60, "sixty"));
	m_library.insert(std::make_pair(70, "seventy"));
	m_library.insert(std::make_pair(80, "eighty"));
	m_library.insert(std::make_pair(90, "ninety"));
	m_library.insert(std::make_pair(100, "hundred"));
	m_library.insert(std::make_pair(1000, "thousand"));
	m_library.insert(std::make_pair(1000000, "million"));
	m_library.insert(std::make_pair(1000000000, "billion"));

}

ISXNumberConverter::NumberToTextConverter::NumberToTextConverter()
{
	InitLibrary();
}

std::string ISXNumberConverter::NumberToTextConverter::Convert(int number)
{
	std::string result = "";

	if (number == 0) {
		return result.append(m_library.at(number));
	}

	if (number < 0) {
		result.append("minus");
		number *= -1;
	}

	while (number) {			// While we have a number we separate each part of the number (billions, millions, thousands and other) from the number and add it to the result
		if (number >= BILLION) {
			result += ConvertFromThreeDigits(number / BILLION);
			result.append(" " + m_library.at(BILLION));
			number %= BILLION;
		}
		else if (number >= MILLION) {
			result += ConvertFromThreeDigits(number / MILLION);
			result.append(" " + m_library.at(MILLION));
			number %= MILLION;
		}
		else if (number >= THOUSAND) {
			result += ConvertFromThreeDigits(number / THOUSAND);
			result.append(" " + m_library.at(THOUSAND));
			number %= THOUSAND;
		}
		else {
			result.append(ConvertFromThreeDigits(number));
			number /= THOUSAND;
		}
	}

	return result;
}

std::string ISXNumberConverter::NumberToTextConverter::ConvertFromThreeDigits(int number)
{
	std::string result = "";

	if (number >= HUNDRED) {	// First of all we should separate handreds from number
		result.append(" " + m_library.at(number / HUNDRED));
		result.append(" " + m_library.at(HUNDRED));
		number %= HUNDRED;
	}
	if (number > 20) {			// If number has dozens we separate them
		result.append(" " + m_library.at((number / 10) * 10));
		number %= 10;
	}
	if (number >= 1) {			// If number is smaller than twenty he has definition in library
		result.append(" " + m_library.at(number));
	}

	return result;
}
