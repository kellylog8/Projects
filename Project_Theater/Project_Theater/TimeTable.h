#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;

#include "Movie.h"

struct TimeTableType
{
	int start_hour;
	int start_min;
	int end_hour;
	int end_min;
	Movie* movie;
};

class TimeTable
{
public:
	TimeTable();
	
	bool Add(string roomName, Movie* movie, int startHour, int startMin);
	void Print();

private:
	unordered_map<string, vector<TimeTableType>> m_tableList;



	/*
	M°ü : 09:00~13:00 movie1 | 19:00~23:00 movie1
	1°ü : 10:00~12:30 movie2 | 17:30~20:00 movie3
	2°ü : 11:00~13:30 movie3 | 21:00~23:30 movie2
	*/

};

