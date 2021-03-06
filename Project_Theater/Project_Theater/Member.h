#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;

#include "Ticket.h"

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

	list<Ticket>& GetTickets() { return m_tickets; }

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

	list<Ticket> m_tickets;



};

