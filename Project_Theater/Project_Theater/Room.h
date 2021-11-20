#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Room
{
public:
	Room();
	~Room();

	void Initialize(int row, int col, string name);
	int GetSeatValue();
	bool Reserve(int row, int col);
	void Print();

private:
	string m_name;
	vector<vector<int>> m_seats;


};

