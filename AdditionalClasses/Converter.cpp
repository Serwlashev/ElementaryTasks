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
