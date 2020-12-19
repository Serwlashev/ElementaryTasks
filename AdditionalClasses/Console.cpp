#include "Console.h"

bool ISXConsole::Console::WantContinue()
{
    string user_wish;
    cout << "\nDo you want to continue? (Please, enter \"y\" or \"yes\" if you want or any other if not): ";
    std::getline(cin, user_wish);

    for (int i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = std::tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

void ISXConsole::Console::PrintMessage(const string& message)
{
	cout << message;
}

string ISXConsole::Console::GetStringValue(const string& message)
{
    string str = "";

    cout << message;

    // We take a string as a result to have possibility to get an empty string from user and check input
    //cin.clear();
    //cin.ignore(255, '\n');
    getline(std::cin, str);

    return str;
}
