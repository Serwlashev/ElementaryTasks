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
	};

}
