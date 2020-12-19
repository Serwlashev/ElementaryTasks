#pragma once
#include <iostream>
#include <string>
using std::string;

namespace ISXNumberConverter
{
	class Converter
	{
	public:
		static double ConvertToDouble(const string number);
		static unsigned int ParseUI(const std::string& number);

	};

}
