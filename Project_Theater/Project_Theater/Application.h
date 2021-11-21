#pragma once

#include <iomanip>

#include "Room.h"
#include "Movie.h"
#include "Member.h"

class Application
{
public:
	void Initialize();
	void Run();

private:
	enum class MENU { 
		NONE, 
		SIGNUP,
		WITHDRAWL,
		LOGIN,
		LOGOUT,
		RESERVE,
		CANCLE,
		CHECK,
		EXIT,
	};

	MENU SelectMenu();
	void SignUp();
	void Login();


private:
	vector<Room> m_roomList;
	vector<Movie> m_moveList;
	vector<Member> m_memberList;

	bool m_isLogin = false;
};

