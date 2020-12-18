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