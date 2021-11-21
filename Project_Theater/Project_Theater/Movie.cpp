#include "Movie.h"

int Movie::m_count = 0;

Movie::Movie()
{
	m_title = " ";
	m_releasedDate = " ";
	m_runningTime = 0;
	m_price = 0;
}

Movie::Movie(string title, string releasedDate, int runningTime, int price)
{
	Initialize(title, releasedDate, runningTime, price);
}

Movie::~Movie()
{
}

bool Movie::Initialize(string title, string releasedDate, int runningTime, int price)
{
	if (title.empty() || releasedDate.empty())
	{
		cout << "Error : ������ �Է����ּ���. (����or������) \n";
		return false;
	}

	m_title = title;
	m_releasedDate = releasedDate;

	if (runningTime < 0)
	{
		cout << "Error : ����� �Է����ּ���. (�󿵽ð�) \n";
		return false;
	}
	if (price < 0)
	{
		cout << "Error : ����� �Է����ּ���. (����) \n";
		return false;
	}

	m_runningTime = runningTime;
	m_price = price;

	return true;
}
