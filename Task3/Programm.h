#pragma once
#include <string>
#include <map>
#include <vector>
//#include <memory>

#include "ConsoleManager.h"
#include "Triangle.h"
#include <algorithm>

using ISXConsole::ConsoleManager;
using ISXTriangle::Triangle;

namespace ISXProg
{
	class Programm
	{
	public:
		//Programm();
		~Programm();

		void Start();

	private:
		void AddNewTriangle();
		void ShowAllTriangles();
		bool CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side);
		//std::multimap<double, std::unique_ptr<Triangle>> m_triangles_map;
		std::vector<Triangle*> m_triangles;
		//std::unique_ptr<Triangle> triangle;
	};
}

