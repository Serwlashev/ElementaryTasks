#include "ConsoleMngr.h"

void ISXManagerConsole::ConsoleMngr::PrintInstruction()
{
    cout << "Pass to the main class call path to the file with algorythm for counting and we'll count lucky tickets according to it";
}

bool ISXManagerConsole::ConsoleMngr::WantContinue()
{
    string user_wish;
    cout << "\nDo you want to add a new triange? (Please, enter \"y\" or \"yes\" if you want or any other if not): ";
    cin.clear();
    cin.ignore(256, '\n');
    getline(std::cin, user_wish);

    for (size_t i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

string ISXManagerConsole::ConsoleMngr::EnterNumber(string text)
{
    string number;

    cout << text;
    cin >> number;

    return number;
}

