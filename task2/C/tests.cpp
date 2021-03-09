#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(IndexTest, test1) {
	EXPECT_EQ(get(1), get(1));
	EXPECT_EQ(get(0), get(0));
	EXPECT_EQ(get(4), get(10));
}

TEST(LibTest, test1) {
	Class_test t;
	EXPECT_EQ(t.f(1), t.f(1));
	EXPECT_EQ(t.f(5), t.f(5));
	EXPECT_EQ(t.f(2), t.f(3));
}
