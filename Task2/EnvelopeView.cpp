#include "EnvelopeView.h"

bool ISXEnvConsole::EnvelopeView::WantContinue()
{
    string user_wish;
    std::cout << "\nDo you want to continue? (Please, enter \"y\" or \"yes\" if you want or any other if not):\n";
    std::getline(std::cin, user_wish);

    for (int i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = std::tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

void ISXEnvConsole::EnvelopeView::PrintMessage(const string& message)
{
    std::cout << message << "\n";

}

string ISXEnvConsole::EnvelopeView::GetStringValue(const string& message)
{
    string str;

    std::cout << message << "\n";

    // We take a string as a result to have possibility to get an empty string from user and check input

    std::getline(std::cin, str);

    return str;
}
