#pragma once
#include <string>
#include <fstream>
#include <io.h>
#include <memory>
#include "ReplacerForString.h"

namespace ISXParse
{
	class FileParser
	{
	public:
		FileParser();

		int CountNumberOfOccurenses(const std::string& path, const std::string& line_to_count);
		bool ReplaceStringToOther(const std::string& path, const std::string& search_line, const std::string& replacing_line);

	private:
		bool RenameFileToDefault(const std::string& old_name, const std::string& file_name);
		std::string GetFileName(const std::string& path);
		std::string GetPathToFile(const std::string& full_path, const std::string& name);
		std::unique_ptr<ISXReplacer::ReplacerForString>CreateReplacer(const std::string& search_line, const std::string& replacing_line);

		std::string m_default_file_name;
		std::unique_ptr<ISXReplacer::ReplacerForString> replacer;
	};

}

