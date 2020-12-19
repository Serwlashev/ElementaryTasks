#include "Application.h"


void ISXApplication::Application::Start(const int& argc, char** argv)
{
	if (argc == 3) {
		if (TryCreateField(argv[1], argv[2])) {
			PrintField();
		}
		else {
			ISXManager::ConsoleManager::PrintMessage("You entered wrong numbers of parameters");
		}
	}
	else {
		ISXManager::ConsoleManager::PrintMessage("To print chess field with specific values of height and width, please, pass two integers to the main class call");
	}
}

bool ISXApplication::Application::TryCreateField(const std::string& passed_height, const std::string& passed_width)
{
	bool success = false;
	if (ISXValidator::Validator::IsValid(ISXValidator::ValidationMode::UnsignedInteger, passed_height) &&
		ISXValidator::Validator::IsValid(ISXValidator::ValidationMode::UnsignedInteger, passed_width)) {

		unsigned int height = ISXParser::Parser::ParseUI(passed_height);
		unsigned int width = ISXParser::Parser::ParseUI(passed_width);

		if(height > 0 && width > 0){
			m_field = CreateField(height, width);
			success = true;
		}
	}

	return success;
}

std::unique_ptr<Field> ISXApplication::Application::CreateField(unsigned int height, unsigned int width)
{

	std::unique_ptr<Field> field = std::make_unique<Field>(height, width);

	return std::move(field);
}


void ISXApplication::Application::PrintField() const
{
	if (m_field) {
		ISXManager::ConsoleManager::DrawField(m_field);
	}
	else {
		ISXManager::ConsoleManager::PrintMessage("Field doesn't exist!");
	}
}

