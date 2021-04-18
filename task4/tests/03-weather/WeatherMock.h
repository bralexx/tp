//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

struct WeatherMock : public Weather {
	cpr::Response Get(const std::string& city, const cpr::Url& url) override;
};


