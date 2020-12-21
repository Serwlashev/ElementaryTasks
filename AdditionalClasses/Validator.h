#pragma once
#include <string>

namespace ISXValidator
{
	enum class ValidationMode {
		Integer,
		Double,
		UnsignedInteger,
		UnsignedLongLong
	};

	class Validator
	{
	public:
		static bool IsValid(ValidationMode mode, const std::string& number);

	private:
		static bool IsStringULL(const std::string number);
		static bool IsStringUnsignedInt(const std::string number);
		static bool IsStringDouble(const std::string number);
	};
}

