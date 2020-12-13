#include "ConsoleManager.h"


void Console::ConsoleManager::PrintErrorMessage(const std::string& message)
{
    std::cout << message << "\n";
}

void Console::ConsoleManager::DrawField(const ISXField::Field* field)
{
    for (int i = 0; i < field->get_height(); i++) {
        for (int j = 0; j < field->get_width(); j++) {
            if (i % 2 == 0) {
                std::cout << "*  ";
            }
            else {
                std::cout << "  *";
            }
        }
        std::cout << "\n";
    }
}
