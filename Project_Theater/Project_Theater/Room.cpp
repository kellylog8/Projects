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
		cout << "���� �¼��� �����ϼ̽��ϴ�. \n";
		return false;
	}
	
	if (m_seats[row][col] == 1)
	{
		cout << "�̹� ����� �¼��Դϴ�. \n";
		return false;
	}

	m_seats[row][col] = 1;
	cout << "���� ����! \n";
	return true;
}

void Room::Print()
{
	cout << "--- " << m_name << "��" << endl;

	for (int i = 0; i < m_seats.size(); i++)
	{
		for (int j = 0; j < m_seats[i].size(); j++)
		{
			cout << m_seats[i][j] << " ";
		}
		cout << endl;
	}
}
