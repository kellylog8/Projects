#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <sstream>
using namespace std;

#include "Movie.h"
#include "Room.h"

struct TimeTableType
{
	int start_hour;
	int start_min;
	int end_hour;
	int end_min;
	Movie* movie;
	Room room;
};

class TimeTable
{
public:
	TimeTable();
	
	bool Add(Room room, Movie* movie, int startHour, int startMin);
	bool Remove(string roomName, int tableOrder);
	bool SelectTable(string roomName, int title_index, Movie*& movieInfo, string& selectedTime, Room*& room);
	void Print();

private:
	unordered_map<string, vector<TimeTableType>> m_tableList;


};

