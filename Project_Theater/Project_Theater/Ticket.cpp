#include "Ticket.h"

void Ticket::Generate(string room, string seat, string title, string time, int runningTime, int price)
{
	m_room = room;
	m_seat = seat;
	m_title = title;
	m_time = time;
	m_runningTime = runningTime;
	m_price = price;
}

void Ticket::Print()
{
	cout << "\n";
	cout << "────────────────────────────\n";
	cout << m_title << "\n";
	cout << m_room << "관 | 좌석 : " << m_seat << "\n";
	cout << "상영시간 : " << m_time << " | ";
	cout << m_runningTime << "분\n";
	cout << "입장인원 : 1명 | " << m_price << "원\n";
	cout << "----------------------------- \n";
	cout << "영화시작 10분전까지 입장해주세요. \n";
	cout << "────────────────────────────\n";

}

void Ticket::ShowTicket()
{

}
