#include "ConsoleManager.h"


void ISXManager::ConsoleManager::DrawField(const std::unique_ptr<Field>& field)
{
    for (size_t i = 0; i < field->get_height(); i++) {
        for (size_t j = 0; j < field->get_width(); j++) {
            cout << field.get()->operator()(i, j);
        }
        cout << "\n";
    }
}
