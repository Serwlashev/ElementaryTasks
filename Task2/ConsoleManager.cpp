#include "ConsoleManager.h"

bool ISXConsole::ConsoleManager::WantContinue()
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

void ISXConsole::ConsoleManager::GetEnvelopeSize(const std::string& name, double& height, double& width)
{
    std::string entered_height = "";
    std::string entered_wight = "";

    std::cout << "\tEnter size of the " << name << ":\n";
    
    // We take a string as a result to have possibility to get an empty string from user and check input
    std::cout << "\tEnter height: ";
    std::getline(std::cin, entered_height);

    std::cout << "\tEnter width: ";
    std::getline(std::cin, entered_wight);

    height = ConvertToDouble(entered_height);
    width = ConvertToDouble(entered_wight);
}

void ISXConsole::ConsoleManager::PrintMessage(const std::string& msg)
{
    std::cout << msg << "\n";
}

void ISXConsole::ConsoleManager::PrintInstruction()
{
    std::cout << "Enter width and height of two envelopes and we will check if the first envelope can fit in the second envelope\n";
    std::cout << "All parameters must be greater than zero, enter them only in numbers. They can also be floating point numbers.\n\n";
}

double ISXConsole::ConsoleManager::ConvertToDouble(const std::string& str)
{
    double res = -1;

    if (!str.empty() && str != "" && str != " " && HasStringOnlyDigitsPoint(str)) {
        res = stod(str);
    }

    return res;
}

bool ISXConsole::ConsoleManager::HasStringOnlyDigitsPoint(const std::string& str)
{
    int count_points = 0;
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == '.') {        
            count_points++;
            if (count_points <= 1) {    // If we have more than one point we get false as result
                continue;
            }
        }

        if (!isdigit(str[i])) {        
            return false;
        }
    }
    return true;
}
