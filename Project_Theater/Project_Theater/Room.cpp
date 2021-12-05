#include "Room.h"

Room::Room()
{
	m_name = "nonamed";
	m_seats.clear();
}

Room::~Room()
{
}

void Room::Initialize(int row, int col, string name)
{
	m_name = name;

	m_seats.resize(row);
	for (int i = 0; i < row; i++)
	{
		m_seats[i].resize(col);
	}
	
}

int Room::GetSeatValue()
{
	return 0;
}

bool Room::Reserve(int row, int col)
{
	if (row >= m_seats.size() || row < 0
		|| col >= m_seats[row].size() || col < 0)
	{
		cout << "없는 좌석을 선택하셨습니다. \n";
		return false;
	}
	
	if (m_seats[row][col] == 1)
	{
		cout << "이미 예약된 좌석입니다. \n";
		return false;
	}

	m_seats[row][col] = 1;
	cout << "예약 성공! \n";
	return true;

}

void Room::Print()
{
	cout << "\n";
	//cout << "「 " << m_name << "관 」\n\n";
	cout << "[ " << m_name << "관 ]\n\n";

	for (int i = 0; i < m_seats.size(); i++)
	{
		if (i == 0)
		{
			cout << setw(4) << " ";
			for (int j = 0; j < m_seats[i].size(); j++)
			{
				//string rowStr = "C" + to_string(j);
				//string colStr = to_string(j+1);
				string colStr = GetColumeNum(j);
				cout << setw(2) << colStr << " ";
			}
			cout << endl;
		}

		//string rowStr = "R" + to_string(i);
		string rowStr = GetAlphabetName(i);

		cout << setw(3) << rowStr << " ";

		for (int j = 0; j < m_seats[i].size(); j++)
		{
			string seat = "□";
			if (m_seats[i][j] == 1)
			{
				seat = "■";
			}
			cout << seat << " ";
		}

		cout << endl;

	}

}

string Room::GetAlphabetName(int row)
{
	//아스키코드 참고
	char alphabet = 'A' + row;
	string str;
	str += alphabet;

	return str;
}

string Room::GetColumeNum(int col)
{
	return to_string(col + 1);
}
