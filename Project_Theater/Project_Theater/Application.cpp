#include "Application.h"

void Application::Initialize()
{
	m_roomList.resize(2);
	m_roomList[0].Initialize(5, 9, "M");
	m_roomList[1].Initialize(6, 4, "1");
}

void Application::Run()
{
	for (auto room : m_roomList)
	{
		room.Print();
	}

	m_roomList[0].Reserve(2, 3);

	m_roomList[0].Print();
}
