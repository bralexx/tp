#include "AddTestCase.h"
#include "Functions.h"

TEST(A, B) {
	for(int i= -1000; i < 1000; ++i) for(int j = -100; j < 100; ++j)
		ASSERT_EQ(i + j, Add(i,j));


	for(int i = -10; i < 10000; ++i) try {
		IsLeap(i);
	} catch(std::invalid_argument) {}

	for(int i = -10; i < 100; ++i) for(int j =-100; j < 100; ++j) try {
		GetMonthDays(i,j);
		} catch (std::invalid_argument) {}
}
