#include "Member.h"

#include <ctime>
#include <Windows.h>

Member::Member()
	: m_name("nonamed")
	, m_phoneNumber("000-0000-0000")
	, m_year(1900)
	, m_month(1)
	, m_day(1)
	, m_age(0)
	, m_gender(0)
{
}

bool Member::Initialize(string name, string phoneNumber, string birthDate, string gender)
{
	m_name = name;
	m_phoneNumber = phoneNumber;

	if (birthDate.empty() || birthDate.size() > 10)
	{
		cout << "생년월일을 잘못입력하셨습니다. YYYY-MM-DD 방식으로 입력해 주세요. \n";
		return false;
	}

	// YYYY-MM-DD

	int year = stoi(birthDate.substr(0, 4));

	birthDate.find('-');

	int month = stoi(birthDate.substr(5, 2));
	int day = stoi(birthDate.substr(8, 2));

	//int offset1 = birthDate.find('-') + 1;
	//int month = stoi(birthDate.substr(offset1, 2));
	//
	//int offset2 = birthDate.rfind('-') + 1;
	//int day = stoi(birthDate.substr(offset2, 2));

	m_year = year;
	m_month = month;
	m_day = day;

	time_t timer;
	struct tm t;
	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	localtime_s(&t, &timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	m_age = (t.tm_year + 1900) - year + 1;

	if (gender == "male" || gender == "man")
	{
		m_gender = 1;
	}
	else if (gender == "female" || gender == "woman")
	{
		m_gender = 2;
	}
	else
	{
		cout << "성별을 잘못 입력하였습니다. \n";
		return false;
	}

	return true;
}

void Member::Print()
{
	cout << "----- 회원정보 \n";
	cout << "이름 : " << m_name << endl;
	cout << "핸드폰번호 : " << m_phoneNumber << endl;
	cout << "나이 : " << m_age << endl;
	cout << "생년월일 : " << m_year << "-" << m_month << "-" << m_day << endl;

	string gender = " ";
	if (m_gender == 1)
		gender = "male";
	else if (m_gender == 2)
		gender = "female;";

	cout << "성별 : " << gender << endl;
}
