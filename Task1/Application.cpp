
#include "Application.h"
#include "Field.h"

namespace ISXApplication {

	void Application::Start(const int argc, char** argv) {
	
		if (argc == num_required_params) {
			m_field = m_board_creator.Create(argv[1], argv[2]);
	
			PrintField();
		}
		else {
			ISXManager::ConsoleManager::PrintMessage("To print chess field with specific values of height and width, please, pass two integers to the main class call");
		}
	}

	std::vector<std::vector<ISXCell::Cell>> Application::GetField() const
	{
		return m_field.get()->GetField();
	}
	
	void Application::PrintField() const {
	
		if (m_field) {
			ISXManager::ConsoleManager::DrawField(GetField());
		}
		else {
			ISXManager::ConsoleManager::PrintMessage("You entered wrong numbers of parameters!");
		}
	}


} // namespace ISXApplication
