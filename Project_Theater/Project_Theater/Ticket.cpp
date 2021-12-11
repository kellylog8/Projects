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
	cout << "����������������������������������������������������������������\n";
	cout << m_title << "\n\n";
	cout << "�󿵰� : " << m_room << "��\n";
	cout << "�¼� : " << m_seat << "\n";
	cout << "�󿵽ð� : " << m_time << "  ";
	cout << m_runningTime << "��\n";
	cout << m_price << "�� (1��)\n";
	cout << "--------------------------------- \n";
	cout << "��ȭ���� 10�������� �������ּ���. \n";
	cout << "����������������������������������������������������������������\n";

}

void Ticket::ShowTicket()
{
	cout << "\n";
	cout << "������������������������������������������������������������������������\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(22) << "��ȭ�����" << setw(15) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(33) << "===============================" << setw(4) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(20) << m_title << setw(17) << "��\n";
	cout << "��" << setw(20) << m_room << "�� " <<setw(3) << left << m_seat << right << setw(11) << "��\n";
	cout << "��" << setw(22) << m_time << " (" << m_runningTime << "��)" << setw(7) << "��\n";
	cout << "��" << setw(20) << m_price << "�� (�� 1��)" << setw(6) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(33) << "-------------------------------" << setw(4) << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "��" << setw(34) << "��ȭ���� 10�������� �������ּ���." << "��\n";
	cout << "��" << setw(37) << "��\n";
	cout << "������������������������������������������������������������������������\n";

}
