#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Ticket
{
public:
	void Generate(string room, string seat, string title, string time, int runningTime, int price);
	void Print();
	void ShowTicket();
	void PrintTicket();

private:
	string m_room;
	string m_seat;
	string m_title;
	string m_time;
	int m_runningTime;
	int m_price;


};

