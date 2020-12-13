#include "Field.h"

ISXField::Field::Field(int height, int width) : m_height(height), m_width(width) {}

int ISXField::Field::get_width() const
{
	return m_width;
}

int ISXField::Field::get_height() const
{
	return m_height;
}
