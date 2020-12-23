#pragma once
#include <iostream>
#include <string>

#include "NumberToTextConverter.h"
#include "Parser.h"

namespace ISXConverter
{
	class NumberConverter
	{
	public:
		NumberConverter();
		std::string ShowNumberAsText(const int& argc, char** argv);

	private:
		std::string ConvertNumberToText(const std::string& number);

		std::unique_ptr<ISXNumberConverter::NumberToTextConverter> m_converter;
	};
}

