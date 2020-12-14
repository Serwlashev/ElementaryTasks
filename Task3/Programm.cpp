#include "Programm.h"

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

void ISXProg::Programm::Start()
{
	bool should_continue = false;

	ConsoleManager::PrintMessage("The progamm allows you to add a new triangle to the list of triangles\n");
	do {
		AddNewTriangle();

		should_continue = ConsoleManager::WantContinue();
	} while (should_continue);

	ShowAllTriangles();
	std::cout << "\nGoodbay!\n";
}

void ISXProg::Programm::AddNewTriangle()
{
	std::string name  = "";
	double first_side = -1;
	double second_side = -1;
	double third_side = -1;

	ConsoleManager::GetTriangleValues(name, first_side, second_side, third_side);

	if (CanCreateTriangle(name, first_side, second_side, third_side)) {
		
		m_triangles.push_back(new Triangle(name, first_side, second_side, third_side));
	}
	else {
		ConsoleManager::PrintMessage("You entered wrong parameters for the triangle");
	}
}

void ISXProg::Programm::ShowAllTriangles()
{
	std::sort(m_triangles.begin(), m_triangles.end(), [](const Triangle* tr1, const Triangle* tr2) {return *tr1 > *tr2; });

	if (!m_triangles.empty()) {
		for (auto it = m_triangles.begin(); it != m_triangles.end(); it++)
		{
			ConsoleManager::PrintMessage((*it)->GetTriangleData());
		}
	}
}

bool ISXProg::Programm::CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side)
{
	if (!name.empty() && name != "" && name != " " && first_side > 0 && second_side > 0 && third_side > 0 &&
		first_side + second_side > third_side && first_side + third_side > second_side && third_side + second_side > first_side) {
		return true;
	}
	return false;
}
