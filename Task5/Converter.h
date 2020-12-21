#pragma once
#include <iostream>
#include <string>

#include "NumberToTextConverter.h"
#include "Parser.h"

using ISXConverterParser::Parser;
using ISXNumberConverter::NumberToTextConverter;

namespace ISXConverter
{
	class Converter
	{
	public:
		Converter();
		std::string ShowNumberAsText(const int& argc, char** argv);

	private:
		std::string ConvertNumberToText(const std::string& number);

		std::unique_ptr<NumberToTextConverter> m_converter;
	};
}

