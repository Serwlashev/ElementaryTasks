#include "pch.h"

#include "ReplacerForString.h"

TEST(ReplaserTest1, ShouldTrue) {
	std::string should_be_replaced = "this is a bad string";
	std::string for_replacing = "this is a good line";

	ISXReplacer::ReplacerForString replacer(should_be_replaced, for_replacing);

	ASSERT_EQ(for_replacing, replacer.Replace(should_be_replaced));
}

TEST(ReplaserTest2, ShouldTrue) {
	std::string should_be_replaced = "this is a bad string";
	std::string for_replacing = "this is a good line";
	std::string another_line = "this is another line";

	ISXReplacer::ReplacerForString replacer(should_be_replaced, for_replacing);

	ASSERT_EQ(another_line, replacer.Replace(another_line));
}

TEST(ReplaserTest3, ShouldFalse) {
	std::string should_be_replaced = "this is a bad string";
	std::string for_replacing = "this is a good line";
	std::string another_line = "this is another line";

	ISXReplacer::ReplacerForString replacer(should_be_replaced, for_replacing);

	ASSERT_NE(for_replacing, replacer.Replace(another_line));
}
