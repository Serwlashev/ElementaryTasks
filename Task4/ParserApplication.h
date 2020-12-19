#pragma once
#include <string>
#include <iostream>

#include "FileParser.h"
#include "../AdditionalClasses/Console.h"

using ISXConsole::Console;
using ISXParse::FileParser;

namespace ISXApplication
{
	class ParserApplication
	{
	public:
		ParserApplication();
		void Parse(const int& argc, char** argv);

	private:
		void CountLineOccurences(const std::string& path, const std::string& line);
		void ReplaceLine(const string& path, const string& search_line, const string& replacing_line);
		
		std::unique_ptr<FileParser> parser;
		string m_instructions;
	};
}

