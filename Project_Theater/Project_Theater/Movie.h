#pragma once

#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
	Movie();
	Movie(string title, string releasedDate, int runningTime, int price);
	~Movie();

	bool Initialize(string title, string releasedDate, int runningTime, int price);

public:
	const string& GetTitle() { return m_title; }
	const string& GetReleasedDate() { return m_releasedDate; }
	int GetRunningTime() { return m_runningTime; }
	int GetPrice() { return m_price; }

	static int GetCount() { return m_count; };

private:
	string m_title;			// ����
	string m_releasedDate;	// ������
	int m_runningTime;		// �󿵽ð�
	int m_price;			// ����

	static int m_count;


};

