#pragma once
#include <string>

namespace ISXConverterParser
{
	// Class for convertion from string to int and validation string value
	class Parser
	{
	public:
		//The method can check check if this string is valid and can be converted to int
		static bool IsValid(const std::string& number);
		// The method to get an integer value from the string
		static int ParseToInt(const std::string& number);

	private:
		static const int max_allowed_length = 10;
	};
}

