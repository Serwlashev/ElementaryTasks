#include "Converter.h"

double ISXNumberConverter::Converter::ConvertToDouble(const string number)
{
	double res = -1;

	try {
		if (!number.empty() && number != "" && number != " " && number.size() < 15) {
			res = stod(number);
		}
	}
	catch (std::bad_cast) {
		res = -1;
	}

	return res;
}

unsigned int ISXNumberConverter::Converter::ParseUI(const std::string& number)
{
	unsigned int res = 0;

	if (!number.empty() || number != " " && number.size() < 9) {

		try {
			res = std::stoi(number);
		}
		catch (std::invalid_argument) {
			res = 0;
		}

		if (number.compare(std::to_string(res)) != 0) {
			res = 0;
		}
	}

	return res;
}