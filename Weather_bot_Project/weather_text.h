#pragma once

#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>


#include <tgbot/tgbot.h>

#include "weather_api.h"
#include "json.hpp"


class Weather_text
{
public:
	Weather_text(std::string token);
	std::string _print(int const& cityID);//this funcuon return message string 
private:
	weather_bot::OpenWeatherMapApi m_weather;// ("8d24816b88b3cd441127465ebb1340a6");

	int cityId;

	nlohmann::json json_;//weather information, the value is assigned in the function _print(int const& cityID)
	nlohmann::json json; //the value is assigned in the class construct

	std::string convert_to_str(nlohmann::json const &_json);//json in string
	std::string transform_to_str(nlohmann::json const& _json);//string json in string
	std::string convert_unixtime(uint64_t subt);//convert unix time in normal time in string


	//weather string
	std::string temp();//this funcuon return temperature in string format
	std::string hum();//this funcuon return humidity in string format
	std::string cityName();//this funcuon return city name and weather description in string format
	std::string press();//this funcuon return pressure in string format
	std::string wind();//this funcuon return speed wind in string format
	std::string windDegree(nlohmann::json & _json);//this funcuon return degree wind in string format
	std::string sun();//this funcuon return sunset and sunrise in string format
};

