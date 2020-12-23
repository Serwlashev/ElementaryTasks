#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "Triangle.h"
#include "ViewTriangle.h"
#include "TriangleParser.h"

using ISXTriangleParser::TriangleParser;
using ISXTriangleView::ViewTriangle;
using ISXTriangle::Triangle;
using std::vector;
using std::string;

namespace ISXProg
{
	class TriangleStorage
	{
	public:
		TriangleStorage();
		~TriangleStorage();

		void Start(const int argc, char** argv);

	private:
		const int empty_params_list = 1;
		const int num_required_params = 5;

		void AddNewTriangle(const vector<string>& params_arr);
		void SortTriangles();
		void ShowAllTriangles() const;
		Triangle* CreateTriangle(const std::string& name, const double first_side, const double second_side, const double third_side);
		bool CanCreateTriangle(const std::string& name, const double first_side, const double second_side, const double third_side) const;
		vector<string> ExtractParamsFromString(const std::string& params) const;
		
		vector<Triangle*> m_triangles;
		string m_instruction;
	};
}

