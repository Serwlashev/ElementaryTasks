#include "Field.h"

ISXField::Field::Field(unsigned int& height, unsigned int& width) : m_height(height), m_width(width * 2) 
{
	m_field = FillField(height, width * 2);
}

unsigned int ISXField::Field::get_width() const
{
	return m_width;
}

unsigned int ISXField::Field::get_height() const
{
	return m_height;
}

char ISXField::Field::operator()(const int& height, const int& width) const
{
	if (height >= 0 && height < m_height && width >= 0 && width < m_width) {
		return m_field[height][width].GetSumbol();
	}

	return '\n';
}

vector<vector<Cell>> ISXField::Field::FillField(const unsigned int& height, const unsigned int& width)
{
	vector<vector<Cell>> tmp_field(height, vector<Cell>(width));
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					tmp_field[i][j].SetSymb('*');
				}
			}
			else {
				if (j % 2 == 1) {
					tmp_field[i][j].SetSymb('*');
				}
			}
		}
	}
	return tmp_field;
}
