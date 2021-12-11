#include "Application.h"

Application::Application()
{
	m_member = nullptr;
	m_isLogin = false;
}

Application::~Application()
{
	m_member = nullptr;
}

void Application::Initialize()
{
	m_roomList.resize(3);
	m_roomList[0].Initialize(10, 10, "M");
	m_roomList[1].Initialize(6, 4, "1");
	m_roomList[2].Initialize(5, 9, "2");

	m_movieList.reserve(100);

	Movie m1 ("Dune", "2021-10-20", 155, 12000);
	Movie m2 ("Avatar2", "2022-12-16", 230, 15000);
	Movie m3 ("Star Wars", "2021-11-13", 141, 9000);

	m_movieList.push_back(m1);
	m_movieList.push_back(m2);
	m_movieList.push_back(m3);


	// Admin
	Member memberAdmin;
	memberAdmin.Initialize("admin", "123", "manager", "010-0000-0000", "2000-01-01", "male");
	m_memberList.push_back(memberAdmin);


	// User (�׽�Ʈ�� ���)
	Member member;
	member.Initialize("qwe", "qwe", "ming jeong king", "010-1234-1234", "2000-12-24", "female");
	m_memberList.push_back(member);



	m_timeTable.Add(m_roomList[0], &m_movieList[0], 9, 0);
	m_timeTable.Add(m_roomList[0], &m_movieList[1], 12, 20);
	m_timeTable.Add(m_roomList[0], &m_movieList[0], 19, 10);
	m_timeTable.Add(m_roomList[0], &m_movieList[0], 22, 0);

	m_timeTable.Add(m_roomList[1], &m_movieList[1], 8, 0);
	m_timeTable.Add(m_roomList[1], &m_movieList[2], 15, 30);
	m_timeTable.Add(m_roomList[1], &m_movieList[2], 18, 30);

	m_timeTable.Add(m_roomList[2], &m_movieList[2], 11, 30);
	m_timeTable.Add(m_roomList[2], &m_movieList[0], 18, 40);
	m_timeTable.Add(m_roomList[2], &m_movieList[1], 21, 30);



	//m_roomList[2].Print();
	//system("pause");

}

	//cout << sizeof(int) << "bytes" << endl;
	//cout << fixed << pow(2, 32) - 1 << endl;

void Application::Run()
{
	while (true)
	{
		system("cls");

		MENU menu = SelectMenu();

		switch (menu)
		{
		case MENU::SIGNUP:
			SignUp();
			break;
		case MENU::LOGIN:
			Login();
			break;
		case MENU::LOGOUT:
			Logout();
			break;
		case MENU::RESERVE:
			Reserve();
			break;
		case MENU::CHECK:
			Check();
			break;

		case MENU::ROOM_INSERT:
			InsertRoom();
			break;
		case MENU::ROOM_REMOVE:
			RemoveRoom();
			break;
		case MENU::MOVIE_INSERT:
			InsertMovie();
			break;
		case MENU::MOVIE_MODIFY:
			ModifyMovie();
			break;
		case MENU::MOVIE_REMOVE:
			RemoveMovie();
			break;
		}

		if (menu == MENU::EXIT)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		system("pause");
	}
	

	//for (auto room : m_roomList)
	//{
	//	room.Print();
	//}
	//
	//m_roomList[0].Reserve(2, 3);
	//
	//m_roomList[0].Print();
}

Application::MENU Application::SelectMenu()
{
	cout << "\n\n";
	cout << "��������������������������������������������������������\n";
	cout << "         �� MENU ��          \n"; 
	cout << "\n";

	if (!m_isLogin)
	{
		cout << "1. ȸ������ \n";
		cout << "2. �α��� \n";
	}
	else
	{
		if (m_isAdmin)
		{
			cout << "1. �󿵰� �߰� \n";
			cout << "2. �󿵰� ���� \n";
			cout << "3. ��ȭ �߰� \n";
			cout << "4. ��ȭ ����\n";
			cout << "5. ��ȭ ����\n";
		}
		else
		{
			cout << "1. �����ϱ� \n";
			cout << "2. ���� Ȯ���ϱ� \n";
		}

		cout << "\n User ID : " << m_member->GetID() << "\n";
		cout << "9. �α׾ƿ� \n";
	}
	cout << "----------------------------- \n";
	cout << "0. ���α׷� ���� \n";
	cout << "��������������������������������������������������������\n";

	int menuNum;
	cout << "�� Enter the menu number : ";
	cin >> menuNum;
	cout << "\n";

	MENU menu;
	if (!m_isLogin)
	{
		switch (menuNum)
		{
		case 1:
			menu = MENU::SIGNUP;
			break;
		case 2:
			menu = MENU::LOGIN;
			break;

		case 0:
			menu = MENU::EXIT;
			break;
		default:
			menu = MENU::NONE;
		}
	}
	else
	{
		if (m_isAdmin)
		{
			switch (menuNum)
			{
			case 1:
				menu = MENU::ROOM_INSERT;
				break;
			case 2:
				menu = MENU::ROOM_REMOVE;
				break;
			case 3:
				menu = MENU::MOVIE_INSERT;
				break;
			case 4:
				menu = MENU::MOVIE_MODIFY;
				break;
			case 5:
				menu = MENU::MOVIE_REMOVE;
				break;

			case 9:
				menu = MENU::LOGOUT;
				break;
			case 0:
				menu = MENU::EXIT;
				break;
			default:
				menu = MENU::NONE;
			}
		}
		else
		{
			switch (menuNum)
			{
			case 1:
				menu = MENU::RESERVE;
				break;
			case 2:
				menu = MENU::CHECK;
				break;

			case 9:
				menu = MENU::LOGOUT;
				break;
			case 0:
				menu = MENU::EXIT;
				break;
			default:
				menu = MENU::NONE;
			}
		}
		
	}
	
	return menu;
}

void Application::SignUp()
{
	cout << "--------- ȸ������ ----------\n";

	bool isSuccess = false;

	Member member;

	string id;
	string pw;

	string name;
	string phoneNumber;
	string birthDate;
	string gender;

	bool isTrue = true;
	while (isTrue)
	{
		isTrue = false;
		cout << setw(10) << " ID" << " : ";
		cin >> id;
		if (id == "q")
		{
			return;
		}

		for (int i = 0; i < m_memberList.size(); i++)
		{
			if (id == m_memberList[i].GetID())
			{
				cout << "�̹� �����ϴ� ���̵��Դϴ�. �ٽ� �Է����ּ���. \n";
				cout << "���� ȸ������ �޴��� ���������÷��� q�� �Է����ּ���. \n";
				isTrue = true;
				break;
			}
		}
	}
	

	cout << setw(10) << " PW" << " : ";
	cin >> pw;
	cout << setw(10) << " �̸�" << " : ";
	cin >> name;
	cout << setw(10) << " �ڵ�����ȣ" << ": ";
	cin >> phoneNumber;

	while (true)
	{
		cout << setw(10) << " �������" << " : ";
		cin >> birthDate;

		if (Member::IsBirthdateForm(birthDate))
		{
			break;
		}
	}

	while (true)
	{
		cout << setw(10) << " ����" << " : ";
		cin >> gender;

		if (Member::IsGenderForm(gender))
		{
			break;
		}
	}
	
	isSuccess =  member.Initialize(id, pw, name, phoneNumber, birthDate, gender);

	if (isSuccess)
	{
		m_memberList.push_back(member);
		cout << "ȸ�����Կ� �����Ͽ����ϴ�. \n";

		member.Print();
	}
	
}

void Application::Login()
{
	cout << "---------- �α��� -----------\n";

	while (true)
	{
		string id;
		string pw;

		cout << "ID : ";
		cin >> id;
		if (id == "q")
		{
			cout << "�α����� �����մϴ�. \n";
			return;
		}
		cout << "PW : ";
		cin >> pw;

		for (auto& member : m_memberList)
		{
			if (id == member.GetID() && pw == member.GetPW())
			{
				m_member = &member;
				m_isLogin = true;
				cout << "�α��� ����! \n";
				if (id == "admin")
				{
					m_isAdmin = true;
				}
				return;
			}
		}

		cout << "�ٽ� �α������ּ���. \n";
		cout << "�α����� �����Ͻ÷��� q�� �Է����ּ���. \n\n";

	}

}

void Application::Logout()
{
	m_member = nullptr;
	m_isLogin = false;
	m_isAdmin = false;
	cout << "�α׾ƿ�... \n";
	cout << "���� ȭ������ ���ư��ϴ�. \n";
}

void Application::Reserve()
{
	cout << "----------- ��ȭ���� -----------\n";

	m_timeTable.Print();

	Movie* movie = nullptr;
	string roomName;
	string reservedTime;
	Room* room = nullptr;

	while (true)
	{
		int title_index;

		cout << "\n";
		cout << "�� Please select movie \n";
		cout << "   (RoomName / TitleIndex) : ";
		cin >> roomName >> title_index;

		std::transform(roomName.begin(), roomName.end(), roomName.begin(), ::toupper);

		if (m_timeTable.SelectTable(roomName, title_index, movie, reservedTime, room))
		{
			//cout << "������ ��ȭ : " << movie->GetTitle() << "," << movie->GetPrice() << endl;
			break;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���. \n";
		}
		
	}

	/*Room* room = nullptr;

	for (Room& roomRef : m_roomList)
	{
		if (roomRef.GetName() == roomName)
		{
			room = &roomRef;
			break;
		}
	}*/

	cout << room->GetName() << "���� �����ϼ̽��ϴ�. \n";
	room->Print();

	int row, col;

	while (true)
	{
		cout << "\n";
		cout << "���ϴ� �¼��� �������ּ���. (row / col) : ";
		cin >> row >> col;

		if (room->Reserve(row, col))
		{
			cout << "�¼��� �����մϴ�. \n";
			break;
		}
		else
		{
			cout << "�ٽ� �������ּ���. \n";
		}
	}

	room->Print();

	// ------------------------------------------

	//string seatName = to_string(row) + to_string(col);
	//�ƽ�Ű�ڵ� ����
	string seatName = Room::GetAlphabetName(row) + Room::GetColumeNum(col);

	Ticket ticket;
	ticket.Generate(roomName, seatName, movie->GetTitle(), reservedTime, 
		movie->GetRunningTime(), movie->GetPrice());

	m_member->GetTickets().push_back(ticket);

	m_member->GetTickets().back().Print();

}

void Application::Check()
{
	cout << "----------- ����Ȯ�� -----------\n";

	//for (int i=0; i < m_member->GetTickets().size(); i++)
	/*for (auto ticket : m_member->GetTickets())
	{
		cout << "\n";
		ticket.Print();
	}*/

	/*for (int i = m_member->GetTickets().size() - 1; i >=0; i--)
	{
		cout << "\n";
		m_member->GetTickets()[i].Print();
	}*/

	auto& tickets = m_member->GetTickets();
	for (auto iter = tickets.begin(); iter != tickets.end(); iter++)
	{
		cout << "\n";
		(*iter).ShowTicket();
	}

	while (true)
	{
		if (tickets.size() <= 0)
		{
			cout << "���ų����� �����ϴ�. \n";
			cout << "�޴� ȭ������ ���ư��ϴ�. \n";
			return;
		}

		cout << "\n";
		cout << "��� �����Ϸ��� 1�� \n";
		cout << "���Ÿ� ����Ͻ÷��� 2�� \n";
		cout << "Ticket�� ����Ͻ÷��� 3���� �Է����ּ���. \n";

		int menuNum;
		cout << "�� Enter the menu number : ";
		cin >> menuNum;

		if (menuNum == 1)
			break;
		else if (menuNum == 2)
		{
			cout << "\n";
			cout << "������� �޴��� �����ϼ̽��ϴ�. \n";
			cout << "����� Ƽ���� ��ȣ�� �Է����ּ���. \n";

			while (true)
			{
				int reserveID;
				cout << "reserved ticket num : ";
				cin >> reserveID;
				
				if (reserveID >= 0 && reserveID < tickets.size())
				{
					auto iter = tickets.begin();

					for (int i = 0; i < reserveID; i++)
					{
						iter++;
					}

					// ������� ����
					tickets.erase(iter);

					system("cls");

					cout << "\n";
					cout << "������� ����! \n";
					cout << "���� ������ Ƽ���� " << tickets.size() << "�� �Դϴ�. \n";

					for (auto iter = tickets.begin(); iter != tickets.end(); iter++)
					{
						cout << "\n";
						(*iter).ShowTicket();
					}

					break;
				}

				cout << "\n";
				cout << "�����ȣ�� �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���. \n";
			}
			
		}

		else if (menuNum == 3)
		{
			int ticketNum;

			cout << "\n";
			cout << "Ticket��� �޴��� �����ϼ̽��ϴ�. \n";
			cout << "����� Ticket�� �������ּ��� : ";
			cin >> ticketNum;

			if (ticketNum >= 0 && ticketNum < tickets.size())
			{
				auto iter = tickets.begin();
				for (int i = 0; i < ticketNum; i++)
				{
					iter++;
				}

				cout << "\n";
				cout << "Ticket�� ����մϴ�... \n";

				(*iter).PrintTicket();

				cout << "\n";
				cout << "Ticket ��¿Ϸ� ! \n";
			}
			else
			{
				cout << "\n";
				cout << "Ticket ��ȣ�� �߸��Է��ϼ̽��ϴ�. \n";
				cout << "�޴��� ���ư��ϴ�. \n";
			}
			
		}


	}


}

void Application::ShowAllRoom()
{
	cout << "\n";
	cout << "���� �󿵰� ����Ʈ \n";
	for (auto room : m_roomList)
	{
		//cout << room.GetName() << "�� ";
		room.Print();
	}

}

void Application::ShowAllMovies()
{
	cout << "\n";
	cout << "���� ��ȭ ����Ʈ (" << m_movieList.size() << "��)" << "\n";
	for (auto movie : m_movieList)
	{
		cout << movie.GetTitle() << "   " << movie.GetPrice() << "\n";
	}
}

void Application::InsertRoom()
{
	int row;
	int col;
	string roomName;

	cout << "\n";
	cout << "--------- Insert Room ----------\n";

	ShowAllRoom();

	cout << "\n";
	cout << "room size (row / col) : ";
	cin >> row >> col;
	cout << "room name : ";
	cin >> roomName;

	Room room;
	room.Initialize(row, col, roomName);
	m_roomList.push_back(room);

	ShowAllRoom();

}

void Application::RemoveRoom()
{
	cout << "\n";
	cout << "--------- Remove Room ----------\n";

	ShowAllRoom();

	string roomName;
	cout << "\n";
	cout << "remove room name : ";
	cin >> roomName;

	for (auto iter = m_roomList.begin(); iter != m_roomList.end(); iter++)
	{
		if ((*iter).GetName() == roomName)
		{
			m_roomList.erase(iter);
			break;
		}

	}

	ShowAllRoom();

}

void Application::InsertMovie()
{
	string title;
	string releasedDate;
	int runningTime;
	int price;

	cout << "\n";
	cout << "--------- Insert Movie ----------\n";

	ShowAllMovies();

	cout << "title : ";
	cin >> title;
	cout << "releasedDate : ";
	cin >> releasedDate;
	cout << "runningTime : ";
	cin >> runningTime;
	cout << "price : ";
	cin >> price;

	Movie movie;
	if (movie.Initialize(title, releasedDate, runningTime, price))
	{
		cout << "\n";
		cout << "����Ʈ�� ��ȭ�� �߰��մϴ�. \n";

		m_movieList.push_back(movie);
	}

	ShowAllMovies();

}

void Application::ModifyMovie()
{
	cout << "\n";
	cout << "--------- Modify Movie ----------\n";

	ShowAllMovies();

	int movieNum;
	cout << "select movie num : ";
	cin >> movieNum;

	if (movieNum < 0 || movieNum >= m_movieList.size())
	{
		cout << "fail... \n";
		return;
	}

	int index = 0;
	for (auto iter = m_movieList.begin(); iter != m_movieList.end(); iter++)
	{
		if (movieNum == index)
		{
			int price = 0;
			cout << "enter the price : ";
			cin >> price;
			(*iter).SetPrice(price);
			break;
		}

		index++;
	}

	ShowAllMovies();

}

void Application::RemoveMovie()
{
	cout << "\n";
	cout << "--------- Remove Movie ----------\n";

	ShowAllMovies();

	int movieNum;
	cout << "select movie num : ";
	cin >> movieNum;

	if (movieNum < 0 || movieNum >= m_movieList.size())
	{
		cout << "fail... \n";
		return;
	}

	int index = 0;
	for (auto iter = m_movieList.begin(); iter != m_movieList.end(); iter++)
	{
		if (movieNum == index)
		{
			m_movieList.erase(iter);
			break;
		}

		index++;
	}

	ShowAllMovies();

}

