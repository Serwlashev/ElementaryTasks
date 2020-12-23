#include "TriangleParser.h"

double ISXTriangleParser::TriangleParser::ParseToDouble(const std::string& number)
{
	double res = -1;

	if (!number.empty() && number != "" && number != " " && number.size() < max_allowed_length && IsValid(number)) {
		res = stod(number);
	}

	return res;
}

bool ISXTriangleParser::TriangleParser::IsValid(const std::string& number)
{
	int count_points = 0;
	for (int i = 0; i < number.length(); i++) {

		if (number[i] == '.') {
			count_points++;
			if (count_points <= 1) {    // If we have more than one point we get false as result
				continue;
			}
		}

		if (!isdigit(number[i])) {			// If we have other symbol
			return false;
		}
	}
	return true;
}
