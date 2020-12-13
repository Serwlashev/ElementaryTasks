#pragma once
#include <iostream>
#include <string>
#include <cmath>

namespace ISXTriangle 
{
	class Triangle
	{
	public:
		Triangle(std::string name, double first_side, double second_side, double third_side);

		friend bool operator >(const Triangle& tr1, const Triangle& tr2);
		friend bool operator <(const Triangle& tr1, const Triangle& tr2);

		double GetSquare() const;
		std::string GetName() const;
		std::string GetTriangleData() const;

	private:
		std::string m_name;
		double m_first_side;
		double m_second_side;
		double m_third_side;
	};
}

