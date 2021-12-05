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
	cout << "��������������������������������������������������������\n";
	cout << m_title << "\n";
	cout << m_room << "�� | �¼� : " << m_seat << "\n";
	cout << "�󿵽ð� : " << m_time << " | ";
	cout << m_runningTime << "��\n";
	cout << "�����ο� : 1�� | " << m_price << "��\n";
	cout << "----------------------------- \n";
	cout << "��ȭ���� 10�������� �������ּ���. \n";
	cout << "��������������������������������������������������������\n";

}

void Ticket::ShowTicket()
{

}
