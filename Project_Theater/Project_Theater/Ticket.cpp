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
	cout << "────────────────────────────────\n";
	cout << m_title << "\n\n";
	cout << "상영관 : " << m_room << "관\n";
	cout << "좌석 : " << m_seat << "\n";
	cout << "상영시간 : " << m_time << "  ";
	cout << m_runningTime << "분\n";
	cout << m_price << "원 (1명)\n";
	cout << "--------------------------------- \n";
	cout << "영화시작 10분전까지 입장해주세요. \n";
	cout << "────────────────────────────────\n";

}

void Ticket::ShowTicket()
{
	//setfill(' ')
	cout << "\n";
	cout << "┌──────────────────────────────────┐\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(22) << "영화입장권" << setw(15) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(33) << "===============================" << setw(4) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(20) << m_title << setw(17) << "│\n";
	cout << "│" << setw(20) << m_room << "관 " << m_seat << setw(12) << "│\n";
	cout << "│" << setw(22) << m_time << " (" << m_runningTime << "분)" << setw(7) << "│\n";
	cout << "│" << setw(21) << m_price << "원 (총 1명)" << setw(5) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(33) << "-------------------------------" << setw(4) << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "│" << setw(34) << "영화시작 10분전까지 입장해주세요." << "│\n";
	cout << "│" << setw(37) << "│\n";
	cout << "└──────────────────────────────────┘\n";

}
