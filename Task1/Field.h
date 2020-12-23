#pragma once
#include <vector>

#include "Cell.h"

namespace ISXField
{
	class Field
	{
	public:
		Field(const unsigned int height, const unsigned int width);
		virtual unsigned int get_height() const = 0;
		virtual unsigned int get_width() const = 0;

		std::vector<std::vector<ISXCell::Cell>> GetField() const;

	protected:
		unsigned int m_height;
		unsigned int m_width;

		std::vector<std::vector<ISXCell::Cell>> m_field;
	};
}
