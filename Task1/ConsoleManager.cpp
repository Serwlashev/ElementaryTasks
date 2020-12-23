
#include "ConsoleManager.h"
#include "Field.h"

namespace ISXManager {

void ConsoleManager::DrawField(const std::vector<std::vector<ISXCell::Cell>>& field)
{
    for (size_t i = 0; i < field.size(); i++) {
        for (size_t j = 0; j < field[1].size(); j++) {
            std::cout << field[i][j].GetSumbol();
        }
        std::cout << "\n";
    }
}

void ConsoleManager::PrintMessage(const std::string& message)
{
    std::cout << message << "\n";
}


} // namespace ISXManager
