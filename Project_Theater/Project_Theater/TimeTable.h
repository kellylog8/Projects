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
	bool SelectTable(string roomName, int title_index, Movie*& movieInfo);
	void Print();

private:
	unordered_map<string, vector<TimeTableType>> m_tableList;


};

