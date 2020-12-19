#include "Validator.h"

bool ISXValidator::Validator::IsValid(ValidationMode mode, const std::string& number)
{
	if (number.empty() || number == "" || number.size() >= 9) {
		return false;
	}

	bool result = false;

	switch (mode) {
	case ValidationMode::UnsignedInteger:
		result = IsStringUnsignedInt(number);
		break;
	case ValidationMode::Double:
		result = IsStringDouble(number);
		break;
	}
	return result;
}

bool ISXValidator::Validator::IsStringUnsignedInt(const std::string number)
{
	for (size_t i = 0; i < number.length(); i++) {
		if (!isdigit(number[i])) {
			return false;
		}
	}

	return true;
}

bool ISXValidator::Validator::IsStringDouble(const std::string number)
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

