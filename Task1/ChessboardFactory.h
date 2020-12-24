#pragma once
#include <memory>

#include "FieldFactory.h"
#include "Chessboard.h"
#include "ChessboardParser.h"

namespace ISXBoardFactory
{
	class ChessboardFactory : public ISXFactory::FieldFactory
	{
	public:
		std::unique_ptr<ISXField::Field> Create(const std::string& height, 
			const std::string& width) override;

	};

}
