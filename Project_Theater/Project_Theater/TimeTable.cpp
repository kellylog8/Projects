#include "TimeTable.h"

TimeTable::TimeTable()
{
	m_tableList["M"] = {  };
}

bool TimeTable::Add(string roomName, Movie* movie, int startHour, int startMin)
{
	if (roomName.empty() || movie == nullptr || startHour < 0 || startMin < 0)
	{
		return false;
	}

	TimeTableType data;
	data.movie = movie;
	data.start_hour = startHour;
	data.start_min = startMin;

	int hour = floor(movie->GetRunningTime()/60);
	int min = movie->GetRunningTime() % 60;

	// 상영시간이 중복되는 경우 예외처리 필요 if() return false

	if ((startMin + min) >= 60)
	{
		hour += 1;
		min -= 60;
	}

	data.end_hour = startHour + hour;
	data.end_min = startMin + min;

	m_tableList[roomName].push_back(data);

	return true;
}

bool TimeTable::SelectTable(string roomName, int title_index, Movie& movieInfo)
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

		movieInfo = *(table[title_index].movie);

		return true;
	}

	cout << "없는. \n";
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
