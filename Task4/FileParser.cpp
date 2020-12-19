#include "FileParser.h"

ISXParse::FileParser::FileParser()
{
	m_default_file_name = "MyTempFile1233.txt";
}

int ISXParse::FileParser::CountNumberOfOccurenses(const string& path, const string& line_to_count)
{
	std::ifstream is(path, std::ios::in | std::ios::binary);
	string buffer;
	int counter = 0;
	string line = line_to_count + "\r";

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

bool ISXParse::FileParser::ReplaceStringToOther(const string& path, const string& search_line, const string& replacing_line)
{
	bool result = false;
	string old_name = GetFileName(path);
	string old_path_without_name = GetPathToFile(path, old_name);
	string temp__file_path = old_path_without_name + m_default_file_name;

	if (old_name != "" && temp__file_path != "" && RenameFileToDefault(path, temp__file_path)) {

		std::ofstream readable_file(path, std::ios::out, std::ios::binary);
		std::ifstream recordable_file(temp__file_path, std::ios::in, std::ios::binary);
		string buffer = "";

		if (readable_file.is_open() && recordable_file.is_open()) {
			while (!recordable_file.eof()) {
				getline(recordable_file, buffer);

				if (buffer.compare(search_line) == 0) {
					readable_file << replacing_line << "\n";
					result = true;
				}
				else {
					readable_file << buffer << "\n";
				}
			}

			readable_file.close();
			recordable_file.close();
			remove(temp__file_path.c_str());
		}
	}

	return result;
}

bool ISXParse::FileParser::RenameFileToDefault(const string& full_old_path, const string& temp_file_path)
{
	if (rename(full_old_path.c_str(), (temp_file_path).c_str()) == 0) {
		return true;
	}
	return false;
}

string ISXParse::FileParser::GetFileName(const string& path)
{
	string name = "";
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

string ISXParse::FileParser::GetPathToFile(const string& full_path, const string& name)
{
	string path = "";

	if (full_path.compare(name) != 0) {
		path = full_path.substr(0, full_path.size() - name.size());
	}

	return path;
}
