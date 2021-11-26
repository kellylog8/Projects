#include "Application.h"

Application::Application()
{
	m_member = nullptr;
	m_isLogin = false;
}

Application::~Application()
{
	delete m_member;
	m_member = nullptr;
}

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



	// 테스트용 멤버
	Member member;
	member.Initialize("qwe", "qwe", "ming jeong king", "010-1234-1234", "2000-12-24", "female");
	m_memberList.push_back(member);
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
		}

		if (menu == MENU::EXIT)
		{
			cout << "프로그램을 종료합니다." << endl;
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

	if (!m_isLogin)
	{
		cout << "1. 회원가입 \n";
		cout << "2. 로그인 \n";
	}
	else
	{
		cout << "1. 예매하기 \n";
		cout << "2. 예매 확인하기 \n";
		cout << "3. 예매 취소하기 \n";

		cout << "\n User : " << m_member->GetID() << "\n";
		cout << "9. 로그아웃 \n";
	}
	cout << "0. 프로그램 종료 \n";
	cout << "--------------------------- \n";

	int menuNum;
	cout << "enter the menu => ";
	cin >> menuNum;

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
		switch (menuNum)
		{
		case 1:
			menu = MENU::RESERVE;
			break;
		case 2:
			menu = MENU::CHECK;
			break;
		case 3:
			menu = MENU::CANCLE;
			break;
		case 9:
			menu = MENU::LOGOUT;
		case 0:
			menu = MENU::EXIT;
			break;
		default:
			menu = MENU::NONE;
		}
	}
	
	return menu;
}

void Application::SignUp()
{
	cout << "----------회원가입----------\n";

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
		cout << setw(10) << "ID" << " : ";
		cin >> id;
		if (id == "q")
		{
			return;
		}

		for (int i = 0; i < m_memberList.size(); i++)
		{
			if (id == m_memberList[i].GetID())
			{
				cout << "이미 존재하는 아이디입니다. 다시 입력해주세요. \n";
				cout << "만약 회원가입 메뉴를 빠져나가시려면 q을 입력해주세요. \n";
				isTrue = true;
				break;
			}
		}
	}
	

	cout << setw(10) << "PW" << " : ";
	cin >> pw;
	cout << setw(10) << "이름" << " : ";
	cin >> name;
	cout << setw(10) << "핸드폰번호" << " : ";
	cin >> phoneNumber;

	while (true)
	{
		cout << setw(10) << "생년월일" << " : ";
		cin >> birthDate;

		if (Member::IsBirthdateForm(birthDate))
		{
			break;
		}
	}

	while (true)
	{
		cout << setw(10) << "성별" << " : ";
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
		cout << "회원가입에 성공하였습니다. \n";

		member.Print();
	}
	
}

void Application::Login()
{
	cout << "----------- 로그인 -----------\n";

	while (true)
	{
		string id;
		string pw;

		cout << "ID : ";
		cin >> id;
		if (id == "q")
		{
			cout << "로그인을 종료합니다. \n";
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
				cout << "로그인 성공! \n";
				return;
			}
		}

		cout << "다시 로그인해주세요. 로그인을 종료하시려면 q를 입력해주세요. \n";
	}
	

}

void Application::Logout()
{
	m_member = nullptr;
	m_isLogin = false;
	cout << "로그아웃... \n";
}
