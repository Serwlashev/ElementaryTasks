#include "ParserApplication.h"

ISXApplication::ParserApplication::ParserApplication()
{
	parser = std::make_unique<FileParser>();
	m_instructions = "Pass to the main class call the path to the file and line to count and we'll count all lines in the given file\n"
		"or the path to the file, a line which should be replaced and a line for replacing and we'll replace all of them\n";
}

void ISXApplication::ParserApplication::Parse(const int& argc, char** argv)
{
	if (argc == should_count_lines) {
		CountLineOccurences(argv[1], argv[2]);
	}
	else if (argc == should_replace_string) {
		ReplaceLine(argv[1], argv[2], argv[3]);
	}
	else {
		FileParserView::PrintMessage(m_instructions);
	}
}

void ISXApplication::ParserApplication::CountLineOccurences(const std::string& path, const std::string& line)
{
	int count = 0;
	count = parser.get()->CountNumberOfOccurenses(path, line);

	if (count > 0) {
		FileParserView::PrintMessage("We found " + std::to_string(count) + " lines\n");
	}
	else {
		FileParserView::PrintMessage("Cannot find any string to count!\n");
	}
}

void ISXApplication::ParserApplication::ReplaceLine(const std::string& path, const std::string& search_line, const std::string& replacing_line)
{
	bool result = parser.get()->ReplaceStringToOther(path, search_line, replacing_line);

	if (result) {
		FileParserView::PrintMessage("The string was successfully replaced\n");
	}
	else {
		FileParserView::PrintMessage("Cannot replace the string\n");
	}

}
