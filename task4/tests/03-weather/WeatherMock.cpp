//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"
cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url) {
	cpr::Response answer;
	answer.text = "{\"main\":{\"temp\":";
	std::string name = "", list = "";

	for(i = 0; i < city.size() ++i) {
		if(is_name && city[i] == ' ') {
			answer.test += + "},\"list\":[\"\",\"\",\"\",\"\",\"\",\"\",\"\",{\"main\":{\"temp\":";
		} else answer.text += city[i];
	}
    	answer.text += "}}]}";
	answer.status_code = 10;
    	return answer;
}