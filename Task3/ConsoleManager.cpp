#include "ConsoleManager.h"

bool ISXConsole::ConsoleManager::WantContinue()
{
    string user_wish;
    cout << "\nDo you want to add a new triange? (Please, enter \"y\" or \"yes\" if you want or any other if not): ";
    getline(std::cin, user_wish);

    for (size_t i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

string ISXConsole::ConsoleManager::GetTriangleParameters()
{
    string params = "";

    cout << "Please, enter all parameters of the triangle.\n";
    cout << "Input format (separator - comma) <name>, <first side>, <second side>, <third side>:\n";
    getline(std::cin, params);

    return params;
}