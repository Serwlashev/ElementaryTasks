#include "Cell.h"

namespace ISXCell {

	Cell::Cell() : m_symb(' ') {
	}
	
	void Cell::SetSymb(const char& symb) {
	
		m_symb = symb;
	}
	
	char Cell::GetSumbol() const {
	
		return m_symb;
	}


} // namespace ISXCell
