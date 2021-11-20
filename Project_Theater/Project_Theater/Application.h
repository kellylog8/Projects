#pragma once

#include "Room.h"

class Application
{
public:
	void Initialize();
	void Run();

private:
	vector<Room> m_roomList;

};

