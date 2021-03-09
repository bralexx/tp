#include <iostream>
#include "main.h"
#include "gtest/gtest.h"

int Factorial(int x) {
	int ans = 1;
	for(int i = 1; i <= x; ++x) ans *= i;
	return ans;
}

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(Factorial(0), 1);
}
//TEST(test1, test11) {
	//ASSERT_EQ(1,1);
//}

int main() {
	Class_test t1, t2;
	std::cout << aaa;
	//ASSERT_EQ(1, 1);
	//std::cout << b;
	std::cout << t1.f(144);
}
