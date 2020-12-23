#include "pch.h"
#include "Cell.h"
#include "Chessboard.h"
#include "Application.h"
#include "ChessboardFactory.h"
#include "ChessboardParser.h"

TEST(CellSetGetTest, ShouldEqual) {
	ISXCell::Cell cell;
	cell.SetSymb('a');
	
	ASSERT_EQ('a', cell.GetSumbol());
}

TEST(CellDefaultGetTest, ShouldEqual) {
	ISXCell::Cell cell;

	ASSERT_EQ(' ', cell.GetSumbol());
}

TEST(ChessBoardGetTest, ShouldEqual) {
	const unsigned int size = 10;
	ISXChessboard::ChessBoard board(size, size);

	ASSERT_EQ(size, board.get_height());
	ASSERT_EQ(size, board.get_width());
}

TEST(FactoryTest, ShouldEqual) {
	const unsigned int size = 5;
	std::unique_ptr<ISXChessboard::ChessBoard> board = std::make_unique< ISXChessboard::ChessBoard>(size, size);
	
	std::string str_size = "5";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> created_board = factory.Create(str_size, str_size);

	ASSERT_NE(nullptr, board);
	ASSERT_NE(nullptr, created_board);
	ASSERT_EQ(created_board.get()->GetField()[1][1].GetSumbol(), board.get()->GetField()[1][1].GetSumbol());
	ASSERT_EQ(created_board.get()->GetField()[4][4].GetSumbol(), board.get()->GetField()[4][4].GetSumbol());
	ASSERT_EQ(created_board.get()->GetField()[2][0].GetSumbol(), board.get()->GetField()[2][0].GetSumbol());
}

TEST(FactoryTestFalse, ShouldFalse) {
	const unsigned int size = 5;
	std::unique_ptr<ISXChessboard::ChessBoard> board = std::make_unique< ISXChessboard::ChessBoard>(size, size);

	std::string str_size = "5";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> created_board = factory.Create(str_size, str_size);

	ASSERT_NE(nullptr, board);
	ASSERT_NE(nullptr, created_board);
	ASSERT_NE(created_board.get()->GetField()[1][1].GetSumbol(), board.get()->GetField()[2][1].GetSumbol());
	ASSERT_NE(created_board.get()->GetField()[4][4].GetSumbol(), board.get()->GetField()[3][4].GetSumbol());
	ASSERT_NE(created_board.get()->GetField()[2][0].GetSumbol(), board.get()->GetField()[2][1].GetSumbol());
}

TEST(FactoryTestWrongParameterNeqative, ShouldTrue) {
	std::string str_size = "-5";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(FactoryTestWrongParameterLetters, ShouldTrue) {
	std::string str_size = "sdsf";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(FactoryTestWrongParameterNumLetters, ShouldTrue) {
	std::string str_size = "344sf3";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(FactoryTestWrongParameterTooLong, ShouldTrue) {
	std::string str_size = "2544343454353452354345";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(FactoryTestWrongParameterSpaces, ShouldTrue) {
	std::string str_size = "244 434 5";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(FactoryTestWrongParameterFloats, ShouldTrue) {
	std::string str_size = "244.5";
	ISXBoardFactory::ChessboardFactory factory;
	std::unique_ptr<ISXField::Field> board = factory.Create(str_size, str_size);

	ASSERT_EQ(nullptr, board);
}

TEST(ParserTest, ShouldTrue) {
	unsigned int number = 244;
	std::string str = std::to_string(number);
	unsigned int result_parsing = ISXChessParser::ChessboardParser::ParseToUI(str);
	ASSERT_EQ(number, result_parsing);
}

TEST(ParserTestWrongParametersString, ShouldTrue) {
	int number = 0;
	std::string str = "sdfsdfds";
	int result_parsing = ISXChessParser::ChessboardParser::ParseToUI(str);
	ASSERT_EQ(number, result_parsing);
}

TEST(ParserTestWrongParametersFloat, ShouldTrue) {
	unsigned int number = 0;
	std::string str = "23.3";
	unsigned int result_parsing = ISXChessParser::ChessboardParser::ParseToUI(str);
	ASSERT_EQ(number, result_parsing);
}

TEST(ParserTestWrongParametersTooLong, ShouldTrue) {
	int number = 0;
	std::string str = "2342342342343242423268767";
	int result_parsing = ISXChessParser::ChessboardParser::ParseToUI(str);
	ASSERT_EQ(number, result_parsing);
}
