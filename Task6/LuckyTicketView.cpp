#include "LuckyTicketView.h"

bool ISXTicketView::LuckyTicketView::WantContinue()
{
    std::string user_wish;
    std::cout << "\nDo you want to continue? (Please, enter \"y\" or \"yes\" if you want or any other if not): ";
    std::getline(std::cin, user_wish);

    for (int i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = std::tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

void ISXTicketView::LuckyTicketView::PrintMessage(const std::string& message)
{
    std::cout << message;
}

std::string ISXTicketView::LuckyTicketView::GetStringValue(const std::string& message)
{
    std::string str = "";

    std::cout << message;

    // We take a string as a result to have possibility to get an empty string from user and check input

    std::getline(std::cin, str);

    return str;
}

void ISXTicketView::LuckyTicketView::ShowNumberTickets(const std::string& num)
{
    std::cout << num << " lucky ticket(s) found.\n";
}
