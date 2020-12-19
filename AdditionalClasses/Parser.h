#pragma once
#include <string>
#include <iostream>

namespace ISXParser
{
	enum class ParseMode
	{
		Integer, 
		UnsignedInteger,
		Double
	};
	class Parser
	{
	public:
		static unsigned int ParseUI(const std::string& number);
	};
}

