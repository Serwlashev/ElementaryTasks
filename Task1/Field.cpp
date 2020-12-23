#include "Field.h"

ISXField::Field::Field(const unsigned int height, const unsigned int width) : m_height(height), m_width(width) { }

std::vector<std::vector<ISXCell::Cell>> ISXField::Field::GetField() const
{
    return m_field;
}
