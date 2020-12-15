#pragma once
#include <string>
#include <map>
#include <vector>

#include "ConsoleManager.h"
#include "Triangle.h"
#include <algorithm>

using ISXConsole::ConsoleManager;
using ISXTriangle::Triangle;
using std::vector;

namespace ISXProg
{
	class Programm
	{
	public:
		Programm();
		~Programm();

		void Start(const int& argc, char** argv);

	private:
		void AddNewTriangle(const vector<string>& params_arr);
		void SortTriangles();
		void ShowAllTriangles() const;
		Triangle* CreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side);
		bool CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side) const;
		vector<string> ExtractParamsFromString(const std::string& params) const;
		double ConvertToDouble(const std::string& str) const ;
		bool HasStringOnlyDigitsPoint(const std::string& str) const;
		
		vector<Triangle*> m_triangles;
		string m_instruction;
	};
}

