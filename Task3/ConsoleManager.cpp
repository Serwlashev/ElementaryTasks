#include "ConsoleManager.h"

bool ISXConsole::ConsoleManager::WantContinue()
{
    std::string user_wish;
    std::cout << "\nDo you want to add a new triange? (Please, enter \"y\" or \"yes\" if you want or any other if not): ";
    std::getline(std::cin, user_wish);

    for (size_t i = 0; i < user_wish.length(); i++) {      // Make all letters in lower case
        user_wish[i] = std::tolower(user_wish[i]);
    }

    if (user_wish.compare("yes") == 0 || user_wish.compare("y") == 0) {
        return true;
    }

    return false;
}

void ISXConsole::ConsoleManager::GetTriangleValues(std::string& name, double& first_side, double& second_side, double& thirs_side)
{
    std::string params = "";

    std::cout << "Please, enter all parameters of the triangle.\n";
    std::cout << "Input format (separator - comma) <name>, <first side>, <second side>, <third side>:\n";
    std::getline(std::cin, params);

    ExtractParamsFromString(params, name, first_side, second_side, thirs_side);
}

void ISXConsole::ConsoleManager::ExtractParamsFromString(std::string params, std::string& name, double& first_side, double& second_side, double& thirs_side)
{
    int count_params = 0;
    std::string tmp_param = "";

    for (size_t i = 0; i < params.length(); i++) {
        if (params[i] == ' ' || params[i] == '\t') {
            continue;
        }

        if (params[i] != ',') {
            tmp_param += params[i];
        }

        if (params[i] == ',' || i == params.length() - 1) {
            count_params++;

            if (count_params == 1) {
                name = tmp_param;
            }
            else if (count_params == 2 && HasStringOnlyDigitsPoint(tmp_param)) {
                first_side = ConvertToDouble(tmp_param);
            }
            else if (count_params == 3 && HasStringOnlyDigitsPoint(tmp_param)) {
                second_side = ConvertToDouble(tmp_param);
            }
            else if (count_params == 4 && HasStringOnlyDigitsPoint(tmp_param)) {
                thirs_side = ConvertToDouble(tmp_param);
            }
            else {
                first_side = second_side = thirs_side = -1;
            }

            tmp_param = "";
        }
    }
}

void ISXConsole::ConsoleManager::PrintMessage(const std::string& msg)
{
    std::cout << msg << "\n";
}

void ISXConsole::ConsoleManager::PrintInstruction()
{
    std::cout << "You should enter all parameters of the triangle.\n";
    std::cout << "Input format (separator - comma) <name>, <first side>, <second side>, <third side>\n";
    std::cout << "All sides should be numbers (they can be floating points numbers or integers), more than 0\n";

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
    for (size_t i = 0; i < str.length(); i++) {

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
