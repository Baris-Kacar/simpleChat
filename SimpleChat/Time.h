#pragma once
#include <time.h>
#include <string>
#pragma warning(disable: 4996)
class Time
{
public:
	Time() {

	}
	~Time();

	std::string getTime() {
		time_t time_ptr;
		time_ptr = time(NULL);

		tm* tm_local = localtime(&time_ptr);

		int h = tm_local->tm_hour;
		int m = tm_local->tm_min;
		int s = tm_local->tm_sec;

		return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
	}

private:

};