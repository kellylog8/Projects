#pragma once

#include <iomanip>
#include <algorithm>

#include "Room.h"
#include "Movie.h"
#include "Member.h"
#include "TimeTable.h"

class Application
{
public:
	Application();
	~Application();

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
		//CANCLE,
		CHECK,
		EXIT,

		ROOM_INSERT,
		ROOM_REMOVE,
		MOVIE_INSERT,
		MOVIE_MODIFY,
		MOVIE_REMOVE,
		SCHEDULE_INSERT,
		SCHEDULE_REMOVE,
	};

	MENU SelectMenu();
	void SignUp();
	void Login();
	void Logout();
	void Reserve();
	void Check();

	void ShowAllRoom();
	void ShowAllMovies();

	void InsertRoom();
	void RemoveRoom();
	void InsertMovie();
	void ModifyMovie();
	void RemoveMovie();

	void InsertSchedule();
	void RemoveSchedule();

private:
	vector<Room> m_roomList;
	vector<Movie> m_movieList;
	vector<Member> m_memberList;

	TimeTable m_timeTable;

	Member* m_member;	// login member
	bool m_isLogin;
	bool m_isAdmin;


};

