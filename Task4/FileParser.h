#pragma once
#include <string>
#include <fstream>
#include <io.h>

using std::string;

namespace ISXParse
{
	class FileParser
	{
	public:
		FileParser();

		int CountNumberOfOccurenses(const string& path, const string& line_to_count);
		bool ReplaceStringToOther(const string& path, const string& search_line, const string& replacing_line);

	private:
		bool RenameFileToDefault(const string& old_name, const string& file_name);
		string GetFileName(const string& path);
		string GetPathToFile(const string& full_path, const string& name);

		string m_default_file_name;
	};

}

