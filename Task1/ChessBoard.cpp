
#include "Chessboard.h"
#include "Cell.h"

namespace ISXChessboard {

	ChessBoard::ChessBoard(unsigned int height, unsigned int width) : Field(height, width)
	{
		m_field = FillField();
	}
	
	unsigned int ChessBoard::get_height() const {
	
		return m_height;
	}
	
	unsigned int ChessBoard::get_width() const {
	
		return m_width;
	}

	std::vector<std::vector<ISXCell::Cell>> ChessBoard::FillField() {
	
		std::vector<std::vector<ISXCell::Cell>> tmp_field(m_height, std::vector<ISXCell::Cell>(m_width));
		for (size_t i = 0; i < m_height; i++) {
			for (size_t j = 0; j < m_width; j++) {		
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
	
} // namespace ISXField
