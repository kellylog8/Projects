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

bool Member::Initialize(string id, string pw, string name, string phoneNumber, string birthDate, string gender)
{
	m_id = id;
	m_pw = pw;

	m_name = name;
	m_phoneNumber = phoneNumber;

	if (birthDate.empty() || birthDate.size() > 10)
	{
		cout << "\n";
		cout << "*생년월일을 잘못입력하셨습니다. \n";
		cout << " 다시입력해주세요. (YYYY-MM-DD) \n";
		cout << "\n";
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
	timer = time(NULL);			// 현재 시각을 초 단위로 얻기
	localtime_s(&t, &timer);	// 초 단위의 시간을 분리하여 구조체에 넣기

	m_age = (t.tm_year + 1900) - year + 1;

	if (gender == "male" || gender == "man" || gender == "1")
	{
		m_gender = 1;
	}
	else if (gender == "female" || gender == "woman" || gender == "2")
	{
		m_gender = 2;
	}
	else
	{
		cout << "\n";
		cout << "*성별을 잘못입력하셨습니다. \n";
		cout << " 다시입력해주세요. (male/man/1 or female/woman/2) \n";
		cout << "\n";
		return false;
	}

	return true;
}

void Member::Print()
{
	cout << "\n";
	cout << "< 회원정보 >\n";
	cout << left << setw(10) << " 이름" << " : " << m_name << endl;
	cout << left << setw(10) << " 핸드폰번호" << ": " << m_phoneNumber << endl;
	cout << left << setw(10) << " 나이" << " : " << m_age << endl;
	cout << left << setw(10) << " 생년월일" << " : " << m_year << "-" << m_month << "-" << m_day << endl;

	string gender = " ";
	if (m_gender == 1)
		gender = "male";
	else if (m_gender == 2)
		gender = "female;";

	cout << left << setw(10) << " 성별" << " : " << gender << endl;
}

bool Member::IsBirthdateForm(string birthday)
{
	// YYYY-MM-DD
	if (birthday.size() == 10 && birthday.at(4) == '-' && birthday.at(7) == '-')
	{
		string year = birthday.substr(0, 4);
		string month = birthday.substr(5, 2);
		string day = birthday.substr(8, 2);

		if (IsNumber(year)		// yaer
			&& IsNumber(month)	// month
			&& IsNumber(day))	// day
		{
			int iMonth = stoi(month);
			if (iMonth < 1 || iMonth > 12)
			{
				cout << "\n";
				cout << "*생년월일을 잘못입력하셨습니다. \n";
				cout << " 다시입력해주세요. (1~12월 사이) \n";
				cout << "\n";
				return false;
			}
			return true;
		}
	}

	cout << "\n";
	cout << "*생년월일을 잘못입력하셨습니다. \n";
	cout << " 다시입력해주세요. (YYYY-MM-DD) \n";
	cout << "\n";
	return false;
}

bool Member::IsGenderForm(string gender)
{
	if (gender == "male" || gender == "female"
		|| gender == "man" || gender == "woman"
		|| gender == "1" || gender == "2")
	{
		return true;
	}

	cout << "\n";
	cout << "*성별을 잘못입력하셨습니다. \n";
	cout << " 다시입력해주세요. (male/man/1 or female/woman/2) \n";
	cout << "\n";
	return false;
}
