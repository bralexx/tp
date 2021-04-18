//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(A, B) {
    	WeatherMock mock = WeatherMock();

    	mock.SetApiKey("1");

    	ASSERT_EQ(mock.FindDiffBetweenTwoCities("1234 1234", "1234 1234"), 0);
    	ASSERT_EQ(mock.FindDiffBetweenTwoCities("9000 1000", "1000 9000"), 8000);
    	ASSERT_EQ(mock.GetDifferenceString("1111 9999", "9999 1111"), "Weather in 1111 9999 is colder than in 9999 1111 by 8888 degrees");
    	ASSERT_EQ(mock.GetDifferenceString("8888 4444", "4444 8888"), "Weather in 8888 4444 is warmer than in 4444 8888 by 4444 degrees");
    	ASSERT_EQ(mock.GetTomorrowDiff("1000 1"), "The weather in 1000 1 tomorrow will be much colder than today.");
    	ASSERT_EQ(mock.GetTomorrowDiff("1000 999"), "The weather in 1000 999 tomorrow will be colder than today.");
    	ASSERT_EQ(mock.GetTomorrowDiff("1000 1000"), "The weather in 1000 1000 tomorrow will be the same than today.");
    	ASSERT_EQ(mock.GetTomorrowDiff("1000 1001"), "The weather in 1000 1001 tomorrow will be warmer than today.");
    	ASSERT_EQ(mock.GetTomorrowDiff("1000 5000"), "The weather in 1000 5000 tomorrow will be much warmer than today.");

	try {
        mock.GetDifferenceString(" ", " ");
        ASSERT_EQ(1, 2);
    	} catch (...) {
    	}

}
