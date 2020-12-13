#include "Application.h"

ISXApplication::Application::Application()
{
	m_field = nullptr;
}

ISXApplication::Application::~Application()
{
	if (m_field != nullptr) {
		delete m_field;
	}
}

void ISXApplication::Application::Start(const int& argc, char** argv)
{

	if (argc == 3) {

		if (CreateField(argv[1], argv[2])) {
			PrintField();
		}
	}
	else if (argc == 0) {
		Console::ConsoleManager::PrintErrorMessage("To print field size, please, pass two integers to the main class call");
	}
	else {
		Console::ConsoleManager::PrintErrorMessage("You entered wrong numbers of parameters");
	}
}


bool ISXApplication::Application::CreateField(const std::string& passed_height, const std::string& passed_width)
{
	int height = Parse(passed_height);
	int width = Parse(passed_width);

	if (!height || !width) {
		Console::ConsoleManager::PrintErrorMessage("You passed wrong parameter!");
		return false;
	}
	else if (height < 0 || width < 0) {
		Console::ConsoleManager::PrintErrorMessage("Field size cannot be lass than zero!");
		return false;
	}

	if (m_field != nullptr) {
		delete m_field;
	}
	m_field = new Field(height, width);
	return true;
}

void ISXApplication::Application::PrintField() const
{
	if (m_field != nullptr) {
		Console::ConsoleManager::DrawField(m_field);
	}
	else {
		Console::ConsoleManager::PrintErrorMessage("Field doesn't exist!");
	}
}

int ISXApplication::Application::Parse(const std::string& value)
{
	int res = 0;

	if (!value.empty() || value != " ") {

		try {
			res = std::stoi(value);
		}
		catch (std::invalid_argument) {
			res = 0;
		}

		if (value.compare(std::to_string(res)) != 0) {
			res = 0;
		}
	}

	return res;
}