#include "Application.h"

void Application::Initialize()
{
	m_roomList.resize(2);
	m_roomList[0].Initialize(5, 9, "M");
	m_roomList[1].Initialize(6, 4, "1");

	m_moveList.reserve(100);

	Movie m1 ("Dune", "2021-10-20", 155, 12000);
	Movie m2 ("Avatar2", "2022-12-16", 230, 15000);
	Movie m3 ("Star Wars", "2021-11-13", 141, 9000);

	m_moveList.push_back(m1);
	m_moveList.push_back(m2);
	m_moveList.push_back(m3);
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
	cout << "----------M E N U---------- \n";
	cout << "1. ȸ������ \n"
		<< "2. �α��� \n"
		<< "3. �����ϱ� \n"
		<< "4. ���� Ȯ���ϱ� \n"
		<< "5. ���� ����ϱ� \n"
		<< "0. ���α׷� ���� \n";
	cout << "--------------------------- \n";

	int menuNum;
	cout << "enter the menu => ";
	cin >> menuNum;

	if (menuNum < 0 || menuNum > 5)
	{
		return MENU::NONE;
	}

	MENU menu;
	switch (menuNum)
	{
	case 1:
		menu = MENU::SIGNUP;
		break;
	case 2:
		menu = MENU::LOGIN;
		break;
	case 3:
		menu = MENU::RESERVE;
		break;
	case 4:
		menu = MENU::CHECK;
		break;
	case 5:
		menu = MENU::CANCLE;
		break;
	case 0:
		menu = MENU::EXIT;
		break;
	default:
		menu = MENU::NONE;
	}

	return menu;
}

void Application::SignUp()
{
	cout << "----------ȸ������----------\n";

	bool isSuccess = false;

	Member member;

	string name;
	string phoneNumber;
	string birthDate;
	string gender;

	cout << setw(10) << "�̸�" << " : ";
	cin >> name;
	cout << setw(10) << "�ڵ�����ȣ" << " : ";
	cin >> phoneNumber;
	cout << setw(10) << "�������" << " : ";
	cin >> birthDate;
	cout << setw(10) << "����" << " : ";
	cin >> gender;

	isSuccess =  member.Initialize(name, phoneNumber, birthDate, gender);


	if (isSuccess)
	{
		m_memberList.push_back(member);
		cout << "ȸ�����Կ� �����Ͽ����ϴ�. \n";

		member.Print();
	}
	
}

void Application::Login()
{
}
