#pragma once
#include <string>

namespace ISXValidator
{
	enum class ValidationMode {
		Integer,
		UnsignedInteger,
		Double
	};

	class Validator
	{
	public:
		static bool IsValid(ValidationMode mode, const std::string& number);

	private:
		static bool IsStringUnsignedInt(const std::string number);
	};
}

