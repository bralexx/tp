//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(A, B) {
    	WeatherMock mock = WeatherMock();

    	mock.SetApiKey("smth");
	try {
        mock.GetDifferenceString("a", "b");
        ASSERT_EQ(1, 2);
    	} catch (...) {
    	}

	for(int i = 0; i < 100; ++i) for(int j = 0; j < 100; ++j)
    		ASSERT_EQ(a.GetDifferenceString(i + , "10 5"), "Weather in 5 10 is colder than in 10 5 by 5 degrees");
    	ASSERT_EQ(a.GetDifferenceString("10 5", "5 10"), "Weather in 10 5 is warmer than in 5 10 by 5 degrees");
    	ASSERT_EQ(a.FindDiffBetweenTwoCities("5 10", "10 5"), -5);
    	ASSERT_EQ(a.GetTomorrowDiff("5 1"), "The weather in 5 1 tomorrow will be much colder than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 2"), "The weather in 5 2 tomorrow will be colder than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 3"), "The weather in 5 3 tomorrow will be colder than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 4"), "The weather in 5 4 tomorrow will be colder than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 5"), "The weather in 5 5 tomorrow will be the same than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 6"), "The weather in 5 6 tomorrow will be warmer than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 7"), "The weather in 5 7 tomorrow will be warmer than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 8"), "The weather in 5 8 tomorrow will be warmer than today.");
    	ASSERT_EQ(a.GetTomorrowDiff("5 9"), "The weather in 5 9 tomorrow will be much warmer than today.");
}
