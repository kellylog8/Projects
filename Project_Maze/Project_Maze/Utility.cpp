#include "Utility.h"


void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int GetCommand()
{
	if (_kbhit())
	{
		return _getch();
	}

	return -1;
}

void SetColor(COLOR color)
{
	if (color == COLOR::RED)
	{
		SetColor(4, 0);
	}
	else if (color == COLOR::GREEN)
	{
		SetColor(2, 0);
	}
	else if (color == COLOR::BLUE)
	{
		SetColor(1, 0);
	}
	else if (color == COLOR::BLACK)
	{
		SetColor(0, 0);
	}
	else if (color == COLOR::WHITE)
	{
		SetColor(15, 0);
	}
}
