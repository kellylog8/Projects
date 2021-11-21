#pragma once

#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Member
{
public:
	Member();

	bool Initialize(string name, string phoneNumber, string birthDate, string gender);
	void Print();

private:
	string m_name;
	string m_phoneNumber;
	int m_age;
	int m_year;
	int m_month;
	int m_day;
	int m_gender;

};

