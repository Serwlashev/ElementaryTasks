#include "pch.h"
#include "../Task1/Cell.h"
#include "../Task1/Field.h"
#include "../Task1/Application.h"


TEST(CellSetGetTest, ShouldEqual) {
	ISXCell::Cell cell;
	cell.SetSymb('a');
	
	EXPECT_EQ('a', cell.GetSumbol());
	EXPECT_TRUE(true);
}

TEST(CellDefaultGetTest, ShouldEqual) {
	ISXCell::Cell cell;

	EXPECT_EQ(' ', cell.GetSumbol());
	EXPECT_TRUE(true);
}

TEST(FieldCreationTest, ShouldEqual) {
	unsigned int height = 3;
	unsigned int width = 3;
	
	ISXField::Field field(height, width);

	char symb = field(0, 0);
	char symb2 = field(2, 1);
	char symb3 = field(0, 1);
	char symb4 = field(0, 2);

	EXPECT_EQ(symb, '*');
	EXPECT_EQ(symb2, ' ');
	EXPECT_EQ(symb3, ' ');
	EXPECT_EQ(symb4, '*');

	EXPECT_TRUE(true);
}

//TEST(AppTryCreateFieldTest, ShouldTrue) {
//	ISXApplication::Application app;
//
//	app.
//
//	EXPECT_EQ(' ', cell.GetSumbol());
//	EXPECT_TRUE(true);
//}
