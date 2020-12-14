#pragma once
#include <iostream>
#include <string>

#include "NumberToTextConverter.h"

namespace ISXConverter
{
	class Converter
	{
	public:
		Converter();
		~Converter();
		void ShowNumberAsText(const int& argc, char** argv);

	private:
		void ConvertNumber(const std::string& number);
		int Parse(const std::string& number);

		ISXNumberConverter::NumberToTextConverter* m_converter;
	};
}

