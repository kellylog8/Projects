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
	string m_title;			// 제목
	string m_releasedDate;	// 개봉일
	int m_runningTime;		// 상영시간
	int m_price;			// 가격

	static int m_count;


};

