#include "TimeTable.h"

TimeTable::TimeTable()
{
	m_tableList["M"] = {  };
}

//bool TimeTable::Add(string roomName, Movie* movie, int startHour, int startMin)
bool TimeTable::Add(Room room, Movie* movie, int startHour, int startMin)
{
	if (!room.IsInitialized() || movie == nullptr || startHour < 0 || startMin < 0)
	{
		return false;
	}

	TimeTableType data;
	data.room = room;
	data.movie = movie;
	data.start_hour = startHour;
	data.start_min = startMin;

	int hour = static_cast<int>(floor(movie->GetRunningTime() / 60));
	int min = movie->GetRunningTime() % 60;

	// 상영시간이 중복되는 경우 예외처리 필요 if() return false

	if ((startMin + min) >= 60)
	{
		hour += 1;
		min -= 60;
	}

	data.end_hour = startHour + hour;
	data.end_min = startMin + min;

	m_tableList[room.GetName()].push_back(data);

	return true;
}

bool TimeTable::SelectTable(string roomName, int title_index, Movie*& movieInfo, string& selectedTime, Room*& room)
{
	vector<TimeTableType>& table = m_tableList[roomName];
	if (table.empty())
	{
		cout << "없는 상영관입니다. \n";
		return false;
	}

	if (title_index >= 0 && title_index < table.size())
	{
		if (table[title_index].movie == nullptr)
		{
			cout << "영화정보가 없습니다. \n";
			return false;
		}

		movieInfo = table[title_index].movie;
		room = &(table[title_index].room);

		auto& time = table[title_index];
		stringstream ss;
		ss << time.start_hour << ":" << time.start_min << " ~ "
			<< time.end_hour << ":" << time.end_min;

		selectedTime = ss.str();

		return true;
	}

	return false;
}

void TimeTable::Print()
{
	for (auto value : m_tableList)
	{
		string roomName = value.first;
		auto movies = value.second;
		
		cout << "───────────────────────────────\n";
		cout << "\n";
		cout << "[" << roomName << "관] \n";
		cout << endl;
		for (int i = 0; i < movies.size(); i++)
		{
			auto table = movies[i];
			cout << " " << left << setw(10) << table.movie->GetTitle() << " (" << table.movie->GetRunningTime() << "분) ";
			cout << setfill('0') << right;
			cout << " " << setw(2) << table.start_hour << ":" << setw(2) << table.start_min
				 << "~" << setw(2) << table.end_hour << ":" << setw(2) << table.end_min << "\n";
			cout << setfill(' ');
			
		}
		cout << "\n";
		cout << "================================\n";
	}
	
	cout << "───────────────────────────────\n";
}
