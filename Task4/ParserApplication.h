#pragma once
#include <string>
#include <iostream>

#include "FileParser.h"
#include "FileParserView.h"

using ISXFileParserView::FileParserView;
using ISXParse::FileParser;

namespace ISXApplication
{
	class ParserApplication
	{
	public:
		ParserApplication();
		void Parse(const int& argc, char** argv);

	private:
		const int should_count_lines = 3;
		const int should_replace_string = 4;

		void CountLineOccurences(const std::string& path, const std::string& line);
		void ReplaceLine(const std::string& path, const std::string& search_line, const std::string& replacing_line);
		
		std::unique_ptr<FileParser> parser;
		std::string m_instructions;
	};
}

