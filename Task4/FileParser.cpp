#include "FileParser.h"

ISXParse::FileParser::FileParser()
{
	m_default_file_name = "MyTempFile1233.txt";
}

int ISXParse::FileParser::CountNumberOfOccurenses(const std::string& path, const std::string& line_to_count)
{
	std::ifstream is(path, std::ios::in | std::ios::binary);
	std::string buffer;
	int counter = 0;
	std::string line = line_to_count + "\r";

	if (is.is_open()) {
		
		while (!is.eof()) {
			getline(is, buffer);
			if (buffer.compare(line) == 0) {
				counter++;
			}
		}
		is.close();
	}
	return counter;
}

bool ISXParse::FileParser::ReplaceStringToOther(const std::string& path, const std::string& search_line, const std::string& replacing_line)
{
	bool result = false;
	std::string old_name = GetFileName(path);
	std::string old_path_without_name = GetPathToFile(path, old_name);
	std::string temp__file_path = old_path_without_name + m_default_file_name;
	replacer = CreateReplacer(search_line, replacing_line);

	if (old_name != "" && temp__file_path != "" && RenameFileToDefault(path, temp__file_path)) {

		std::ofstream readable_file = std::ofstream(path, std::ios::out, std::ios::binary);
		std::ifstream recordable_file = std::ifstream(temp__file_path, std::ios::in, std::ios::binary);
		std::string buffer = "";

		if (readable_file.is_open() && recordable_file.is_open() && replacer) {
			while (!recordable_file.eof()) {
				getline(recordable_file, buffer);

				readable_file << replacer.get()->Replace(buffer) << "\n";
			}

			readable_file.close();
			recordable_file.close();
			remove(temp__file_path.c_str());
		}
	}

	return result;
}

bool ISXParse::FileParser::RenameFileToDefault(const std::string& full_old_path, const std::string& temp_file_path)
{
	if (rename(full_old_path.c_str(), (temp_file_path).c_str()) == 0) {
		return true;
	}
	return false;
}

std::string ISXParse::FileParser::GetFileName(const std::string& path)
{
	std::string name = "";
	int position = 0;
	for (size_t i = path.size() - 1; i > 0; i--) {
		if (path[i] == '\\') {
			position = i + 1;
			break;
		}
	}

	if(position == 0) {
		name = path;
	}
	else {
		name = path.substr(position);
	}

	return name;
}

std::string ISXParse::FileParser::GetPathToFile(const std::string& full_path, const std::string& name)
{
	std::string path = "";

	if (full_path.compare(name) != 0) {
		path = full_path.substr(0, full_path.size() - name.size());
	}

	return path;
}

std::unique_ptr<ISXReplacer::ReplacerForString> ISXParse::FileParser::CreateReplacer(const std::string& search_line, const std::string& replacing_line)
{
	if (!search_line.empty() && replacing_line.empty() && search_line != "" && replacing_line != "") {
		std::unique_ptr<ISXReplacer::ReplacerForString> replacer = std::make_unique<ISXReplacer::ReplacerForString>(search_line, replacing_line);
		return std::move(replacer);
	}

	return nullptr;
}
