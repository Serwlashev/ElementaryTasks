#include "ConsoleManager.h"


void ISXManager::ConsoleManager::DrawField(const ISXField::Field* field)
{
    for (int i = 0; i < field->get_height(); i++) {
        for (int j = 0; j < field->get_width(); j++) {
            if (i % 2 == 0) {
                cout << "*  ";
            }
            else {
                cout << "  *";
            }
        }
        cout << "\n";
    }
}
