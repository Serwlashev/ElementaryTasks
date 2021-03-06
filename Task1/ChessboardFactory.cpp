#include "ChessboardFactory.h"

std::unique_ptr<ISXField::Field> ISXBoardFactory::ChessboardFactory::Create(const std::string& height, const std::string& width)
{
	unsigned int converted_height = 0;
	unsigned int converted_width = 0;

	converted_height = ISXChessParser::ChessboardParser::ParseToUI(height);
	converted_width = ISXChessParser::ChessboardParser::ParseToUI(width);

	if (converted_height > 0U && converted_width > 0U) {

		std::unique_ptr<ISXChessboard::ChessBoard> field = std::make_unique<ISXChessboard::ChessBoard>(converted_height, converted_width);

		if (field) {
			return std::move(field);
		}
	}

	return nullptr;
}
