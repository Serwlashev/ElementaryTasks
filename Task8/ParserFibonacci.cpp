#include "ParserFibonacci.h"
unsigned long long ISXParseFibonacci::ParserFibonacci::ParseULL(const std::string& number)
{
	unsigned long long res = 0;

	if (!number.empty() && number != " " && IsValid(number)) {
		res = std::stoull(number);
	}

	if (number.compare(std::to_string(res)) != 0) {
		res = 0;
	}

	return res;
}
bool ISXParseFibonacci::ParserFibonacci::IsValid(const std::string& number)
{
	if (number.size() > 10) {
		return false;
	}

	for (size_t i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}
	return true;
}