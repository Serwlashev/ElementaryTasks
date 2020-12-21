#include "Cell.h"

ISXCell::Cell::Cell() : m_symb(' ') { }

void ISXCell::Cell::SetSymb(const char& symb)
{
	m_symb = symb;
}

char ISXCell::Cell::GetSumbol() const
{
	return m_symb;
}

