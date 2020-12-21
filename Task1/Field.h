#pragma once
#include "Cell.h"
#include <vector>

using std::vector;
using ISXCell::Cell;

namespace ISXField
{
	class Field
	{
	public:
		Field(unsigned int& height, unsigned int& width);

		unsigned int get_height() const;
		unsigned int get_width() const;

		char operator() (const int& height, const int& width) const;
	private:
		vector<vector<Cell>> FillField(const unsigned int& height, const unsigned int& width);

		vector<vector<Cell>> m_field;
		unsigned int m_height;
		unsigned int m_width;
	};
}