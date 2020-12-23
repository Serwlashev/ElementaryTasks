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
	std::string result_str = "";

	if (number == 0) {
		return result_str.append(m_library.at(number));
	}

	if (number < 0) {
		result_str.append("minus ");
		number *= -1;
	}
	std::list<int> number_parts = PushToList(number);

	result_str.append(MakeStringFromList(number_parts));
 
	if (result_str[result_str.length() - 1] == ' ') {
		result_str.erase(result_str.length() - 1, 1);
	}

	return result_str;
}

std::string ISXNumberConverter::NumberToTextConverter::ConvertFromThreeDigits(int number)
{
	std::string result = "";

	if (number >= HUNDRED_DELIMITER) {	// First of all we should separate handreds from number
		result.append(m_library.at(number / HUNDRED_DELIMITER) + " ");
		result.append(m_library.at(HUNDRED_DELIMITER) + " ");
		number %= HUNDRED_DELIMITER;
	}
	if (number > LIBRARY_DELIMITER) {			// If number has dozens we separate them
		result.append(m_library.at((number / DOZENS_DELIMITER) * DOZENS_DELIMITER) + " ");
		number %= DOZENS_DELIMITER;
	}
	if (number >= MIN_DELIMITER) {			// If number is smaller than twenty he has definition in library
		result.append(m_library.at(number) + " ");
	}

	return result;
}

std::list<int> ISXNumberConverter::NumberToTextConverter::PushToList(int number) const
{
	std::list<int> number_list;

	while (number) {
		number_list.push_front(number % THOUSAND_DELIMITER);
		number /= THOUSAND_DELIMITER;
	}

	return number_list;
}

std::string ISXNumberConverter::NumberToTextConverter::MakeStringFromList(std::list<int> number_parts)
{
	std::string result = "";
	
	while (!number_parts.empty()) {
		result.append(ConvertFromThreeDigits(number_parts.front()));
		
		if (number_parts.front() != 0 && number_parts.size() > 1) {
			result.append(GetNumberRank(number_parts.size() - 1));
		}

		number_parts.pop_front();
	}

	return result;
}

std::string ISXNumberConverter::NumberToTextConverter::GetNumberRank(int number_rank) const
{
	return m_library.at(std::pow(1000, number_rank)) + " ";
}
