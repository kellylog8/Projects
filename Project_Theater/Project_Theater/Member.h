#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;

class Member
{
public:
	Member();

	bool Initialize(string id, string pw, string name, string phoneNumber, string birthDate, string gender);
	void Print();

	static bool IsBirthdateForm(string birthday);
	static bool IsGenderForm(string gender);

	static bool IsNumber(const string& str)
	{
		for (char const& c : str) {
			if (std::isdigit(c) == 0) return false;
		}
		return true;
	}

public:
	const string& GetID() { return m_id; }
	const string& GetPW() { return m_pw; }

private:
	string m_id;	// key
	string m_pw;

	string m_name;
	string m_phoneNumber;
	int m_age;
	int m_year;
	int m_month;
	int m_day;
	int m_gender;

};

