//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"
cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url) {
	cpr::Response answer;
	answer.text = "{\"main\":{\"temp\":";
	std::string name = "", list = "";
	bool is_name = true;

	for(int i = 0; i < city.size(); ++i) {
		if(is_name && city[i] == ' ') {
			is_name = false;
			answer.text += + "},\"list\":[\"\",\"\",\"\",\"\",\"\",\"\",\"\",{\"main\":{\"temp\":";
		} else answer.text += city[i];
	}
    	answer.text += "}}]}";
	if(answer.text== "{\"main\":{\"temp\":},\"list\":[\"\",\"\",\"\",\"\",\"\",\"\",\"\",{\"main\":{\"temp\":") {
		answer.status_code = 10;
        	return answer;
	}
 	answer.status_code = 200;
    	return answer;
}
