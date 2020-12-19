#pragma once
#include <string>
#include <map>
#include <vector>

#include "Triangle.h"
#include <algorithm>
#include "..\AdditionalClasses\Console.h"
#include "..\AdditionalClasses\Validator.h"
#include "..\AdditionalClasses\Converter.h"

using ISXConsole::Console;
using ISXValidator::Validator;
using ISXNumberConverter::Converter;
using ISXTriangle::Triangle;
using std::vector;

namespace ISXProg
{
	class TriangleStorage
	{
	public:
		TriangleStorage();
		~TriangleStorage();

		void Start(const int& argc, char** argv);

	private:
		void AddNewTriangle(const vector<string>& params_arr);
		void SortTriangles();
		void ShowAllTriangles() const;
		Triangle* CreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side);
		bool CanCreateTriangle(const std::string& name, const double& first_side, const double& second_side, const double& third_side) const;
		vector<string> ExtractParamsFromString(const std::string& params) const;
		
		vector<Triangle*> m_triangles;
		string m_instruction;
	};
}

