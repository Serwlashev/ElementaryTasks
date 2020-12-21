#include "Programm.h"

ISXProg::TriangleStorage::TriangleStorage()
{
	m_instruction = "You should enter all parameters of the triangle.\n"
					"Input format (separator - comma) <name>, <first side>, <second side>, <third side>\n"
					"All sides should be numbers (they can be floating points numbers or integers), more than 0\n\n";
}

ISXProg::TriangleStorage::~TriangleStorage()
{
    if (!m_triangles.empty()) {
        for (auto it = m_triangles.begin(); it != m_triangles.end(); it++)
        {
            delete* it;
        }
        m_triangles.clear();
    }
}

void ISXProg::TriangleStorage::Start(const int& argc, char** argv)
{
	bool should_continue = true;
    vector<string> params_arr;

    if (argc == 1) {
        ViewTriangle::PrintMessage(m_instruction);
    }
    else if (argc == 5) {
        for (int i = 1; i < 5; i++) {
            params_arr.push_back(argv[i]);
        }
        AddNewTriangle(params_arr);

        should_continue = ViewTriangle::WantContinue();
    }
    else {
        ViewTriangle::PrintMessage("You passed wrong number of parameters\n");
        ViewTriangle::PrintMessage(m_instruction);

        should_continue = ViewTriangle::WantContinue();
    }

    while (should_continue) {
        ViewTriangle::PrintMessage("The progamm allows you to add a new triangle to the list of triangles\n\n");

        ViewTriangle::PrintMessage("Please, enter all parameters of the triangle.\n");
        params_arr = ExtractParamsFromString(ViewTriangle::GetStringValue("Input format (separator - comma) <name>, <first side>, <second side>, <third side>:\n"));

		AddNewTriangle(params_arr);

		should_continue = ViewTriangle::WantContinue();
	}

    SortTriangles();
	ShowAllTriangles();
    ViewTriangle::PrintMessage("\nGoodbay!\n");
}

void ISXProg::TriangleStorage::AddNewTriangle(const vector<string>& params_arr)
{
    if (params_arr.size() == 4) {

        std::string name = params_arr[0];
        double first_side = TriangleParser::ParseToDouble(params_arr[1]);
        double second_side = TriangleParser::ParseToDouble(params_arr[2]);
        double third_side = TriangleParser::ParseToDouble(params_arr[3]);

        Triangle* newTriangle = CreateTriangle(name, first_side, second_side, third_side);

        if (newTriangle != nullptr) {
            m_triangles.push_back(newTriangle);
        }
        else {
            ViewTriangle::PrintMessage("Cannot create an instance of the triangle\n");
        }
    }
    else {
        ViewTriangle::PrintMessage("You passed wrong parameters for the triangle!\n");
    }
}

void ISXProg::TriangleStorage::SortTriangles()
{
    std::sort(m_triangles.begin(), m_triangles.end(), [](const Triangle* tr1, const Triangle* tr2) {return *tr1 > *tr2; });
}

void ISXProg::TriangleStorage::ShowAllTriangles() const
{
	if (!m_triangles.empty()) {
		for (auto it = m_triangles.begin(); it != m_triangles.end(); it++)
		{
            ViewTriangle::PrintMessage((*it)->GetTriangleData());
		}
	}
}

Triangle* ISXProg::TriangleStorage::CreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side)
{
    if (CanCreateTriangle(name, first_side, second_side, third_side)) {

        return new Triangle(name, first_side, second_side, third_side);
    }
    return nullptr;;
}

bool ISXProg::TriangleStorage::CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side) const
{
	if (!name.empty() && name != "" && name != " " && first_side > 0 && second_side > 0 && third_side > 0 &&
		first_side + second_side > third_side && first_side + third_side > second_side && third_side + second_side > first_side) {
		return true;
	}
	return false;
}

std::vector<string> ISXProg::TriangleStorage::ExtractParamsFromString(const std::string& params) const
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
            else if (count_params == 2 && TriangleParser::IsValid(tmp_param)) {
                result_params.push_back(tmp_param);
            }
            else if (count_params == 3 && TriangleParser::IsValid(tmp_param)) {
                result_params.push_back(tmp_param);
            }
            else if (count_params == 4 && TriangleParser::IsValid(tmp_param)) {
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
