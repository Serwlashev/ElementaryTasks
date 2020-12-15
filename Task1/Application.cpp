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
	else if (argc == 1) {
		ISXManager::ConsoleManager::PrintMessage("To print chess field with specific values of height and width, please, pass two integers to the main class call");
	}
	else {
		ISXManager::ConsoleManager::PrintMessage("You entered wrong numbers of parameters");
	}
}


bool ISXApplication::Application::CreateField(const std::string& passed_height, const std::string& passed_width)
{
	int height = Parse(passed_height);
	int width = Parse(passed_width);

	if (!height || !width) {
		ISXManager::ConsoleManager::PrintMessage("You passed wrong parameter!");
		return false;
	}
	else if (height < 0 || width < 0) {
		ISXManager::ConsoleManager::PrintMessage("Field size cannot be lass than zero!");
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
		ISXManager::ConsoleManager::DrawField(m_field);
	}
	else {
		ISXManager::ConsoleManager::PrintMessage("Field doesn't exist!");
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