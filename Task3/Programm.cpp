#include "Programm.h"

ISXProg::Programm::Programm()
{
	m_instruction = "You should enter all parameters of the triangle.\n"
					"Input format (separator - comma) <name>, <first side>, <second side>, <third side>\n"
					"All sides should be numbers (they can be floating points numbers or integers), more than 0\n\n";
}

ISXProg::Programm::~Programm()
{
	if (!m_triangles.empty()) {
		for (auto it = m_triangles.begin(); it != m_triangles.end(); it++)
		{
			delete *it;
		}
		m_triangles.clear();
	}
}

void ISXProg::Programm::Start(const int& argc, char** argv)
{
	bool should_continue = true;
    vector<string> params_arr;

    if (argc == 1) {
        ConsoleManager::PrintMessage(m_instruction);
    }
    else if (argc == 5) {
        for (int i = 1; i < 5; i++) {
            params_arr.push_back(argv[i]);
        }
        AddNewTriangle(params_arr);

        should_continue = ConsoleManager::WantContinue();
    }
    else {
        ConsoleManager::PrintMessage("You passed wrong number of parameters\n");
        ConsoleManager::PrintMessage(m_instruction);

        should_continue = ConsoleManager::WantContinue();
    }

    while (should_continue) {
        ConsoleManager::PrintMessage("The progamm allows you to add a new triangle to the list of triangles\n\n");

        params_arr = ExtractParamsFromString(ConsoleManager::GetTriangleParameters());

		AddNewTriangle(params_arr);

		should_continue = ConsoleManager::WantContinue();
	}

    SortTriangles();
	ShowAllTriangles();
	ConsoleManager::PrintMessage("\nGoodbay!\n");
}

void ISXProg::Programm::AddNewTriangle(const vector<string>& params_arr)
{
    if (params_arr.size() == 4) {

        std::string name = params_arr[0];
        double first_side = ConvertToDouble(params_arr[1]);
        double second_side = ConvertToDouble(params_arr[2]);
        double third_side = ConvertToDouble(params_arr[3]);

        Triangle* newTriangle = CreateTriangle(name, first_side, second_side, third_side);

        if (newTriangle != nullptr) {
            m_triangles.push_back(newTriangle);
        }
        else {
            ConsoleManager::PrintMessage("Cannot create an instance of the triangle\n");
        }
    }
    else {
        ConsoleManager::PrintMessage("You passed wrong parameters for the triangle!\n");
    }
}

void ISXProg::Programm::SortTriangles()
{
    std::sort(m_triangles.begin(), m_triangles.end(), [](const Triangle* tr1, const Triangle* tr2) {return *tr1 > *tr2; });
}

void ISXProg::Programm::ShowAllTriangles() const
{
	if (!m_triangles.empty()) {
		for (auto it = m_triangles.begin(); it != m_triangles.end(); it++)
		{
			ConsoleManager::PrintMessage((*it)->GetTriangleData());
		}
	}
}

Triangle* ISXProg::Programm::CreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side)
{
    if (CanCreateTriangle(name, first_side, second_side, third_side)) {

        return new Triangle(name, first_side, second_side, third_side);
    }
    return nullptr;
}

bool ISXProg::Programm::CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side) const
{
	if (!name.empty() && name != "" && name != " " && first_side > 0 && second_side > 0 && third_side > 0 &&
		first_side + second_side > third_side && first_side + third_side > second_side && third_side + second_side > first_side) {
		return true;
	}
	return false;
}


std::vector<string> ISXProg::Programm::ExtractParamsFromString(const std::string& params) const
{
    int count_params = 0;
    std::string tmp_param = "";
    std::vector<string> result_params;

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
                result_params.push_back(tmp_param);
            }
            else if (count_params == 2 && HasStringOnlyDigitsPoint(tmp_param)) {
                result_params.push_back(tmp_param);
            }
            else if (count_params == 3 && HasStringOnlyDigitsPoint(tmp_param)) {
                result_params.push_back(tmp_param);
            }
            else if (count_params == 4 && HasStringOnlyDigitsPoint(tmp_param)) {
                result_params.push_back(tmp_param);
            }
            else {
                result_params.clear();
            }

            tmp_param = "";
        }
    }
    return result_params;
}

double ISXProg::Programm::ConvertToDouble(const std::string& str) const
{
    double res = -1;

    try {
        if (!str.empty() && str != "" && str != " " && HasStringOnlyDigitsPoint(str)) {
            res = stod(str);
        }
    }
    catch (std::out_of_range) {
        ConsoleManager::PrintMessage("You passed too long number\n");
    }

    return res;
}

bool ISXProg::Programm::HasStringOnlyDigitsPoint(const std::string& str) const
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
