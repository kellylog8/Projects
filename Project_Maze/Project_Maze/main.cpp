#include <iostream>
using namespace std;

#include "Utility.h"

enum class DIRECTION { NONE, LEFT, RIGHT, UP, DOWN };
struct Position
{
	int x;
	int y;
};

enum class MENU { EMPTY, PLAY, AUTO };

int main()
{
	int map[11][21] = {
				0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,
				0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,
				0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,
				0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,
				0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,
				0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,
				0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,
				0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,
				0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
	};

	string wall = "﹥";
	string road = "﹤";
	string rock = "≒";
	string player = "∪";

	Position start_pos;
	start_pos.x = 0;
	start_pos.y = 1;

	Position end_pos;
	end_pos.x = 10;
	end_pos.y = 19;

	Position player_pos;
	player_pos.x = start_pos.x;
	player_pos.y = start_pos.y;
	DIRECTION player_dir = DIRECTION::DOWN;

	bool isPlay = false;
	bool isAutoMode = false;


	bool isRun = true;
	while (isRun == true)
	{

		MENU menu = MENU::EMPTY;
		if (player_dir == DIRECTION::DOWN)
		{
			player = "∪";
		}
		else if (player_dir == DIRECTION::UP)
		{
			player = "∼";
		}
		else if (player_dir == DIRECTION::LEFT)
		{
			player = "９";
		}
		else if (player_dir == DIRECTION::RIGHT)
		{
			player = "Ⅱ";
		}

		cout << endl;

		//式式式式式式式式式式式式式式式式式式式式式式
		for (int i = 0; i < 11; i++)		// row ч
		{
			for (int j = 0; j < 21; j++)	// col 翮
			{
				if (i == player_pos.x && j == player_pos.y && isPlay)
				{
					SetColor(COLOR::RED);
					cout << player;
					continue;
				}

				if (map[i][j] == 0)
				{
					SetColor(COLOR::GREEN);
					cout << wall;
				}
				else if (map[i][j] == 1)
				{
					SetColor(COLOR::BLUE);
					cout << road;
				}
				else if (map[i][j] == 2)
				{
					cout << rock;
				}
			}
			cout << endl;
		}

		if (player_pos.x == end_pos.x && player_pos.y == end_pos.y)
		{
			isAutoMode = false;
			SetColor(COLOR::WHITE);
			cout << "\n"
				<< "\n式式式式式式式式式式式式式式式式式式式式式式式\n"
				<< "    F I N I S H !!! "
				<< "\n式式式式式式式式式式式式式式式式式式式式式式式\n";
			system("pause");
		}

		//式式式式式式式式式式式式式式式式式式式式式式
		char key = ' ';
		SetColor(COLOR::WHITE);
		cout << endl
			<< "殮溘п輿撮蹂 : ";
		//cin >> key;

		if (!isAutoMode)
		{
			key = _getch();
		}
		//式式式式式式式式式式式式式式式式式式式式式式

		DIRECTION direction = DIRECTION::NONE;
		switch (key)
		{
		case 'a':
			direction = DIRECTION::LEFT;
			player_dir = DIRECTION::LEFT;
			break;
		case 'd':
			direction = DIRECTION::RIGHT;
			player_dir = DIRECTION::RIGHT;
			break;
		case 'w':
			direction = DIRECTION::UP;
			player_dir = DIRECTION::UP;
			break;
		case's':
			direction = DIRECTION::DOWN;
			player_dir = DIRECTION::DOWN;
			break;
		case 'Q':
		case 'q':
			cout << "Щ煎斜極擊 謙猿м棲棻\n";
			isRun = false;
			break;
		case '1':
			menu = MENU::PLAY;
			isPlay = true;
			break;
		case '2':
			isPlay = true;
			isAutoMode = true;
			menu = MENU::AUTO;
			break;
		case '0':
			menu = MENU::EMPTY;
			break;
		}


		if (menu == MENU::PLAY)
		{
			if (isPlay)
			{
				player_pos.x = start_pos.x;
				player_pos.y = start_pos.y;
			}
		}

		if (isAutoMode)
		{
			Sleep(150);
			//direction = DIRECTION::DOWN;

			player_pos.x;
			player_pos.y;
			player_dir;

			map[player_pos.x][player_pos.y];

			if (player_dir == DIRECTION::DOWN) // 謝,ж,辦,鼻
			{
				if (map[player_pos.x][player_pos.y - 1] == 1)
				{
					direction = DIRECTION::LEFT;
				}
				else if (map[player_pos.x + 1][player_pos.y] == 1)
				{
					direction = DIRECTION::DOWN;
				}
				else if (map[player_pos.x][player_pos.y + 1] == 1)
				{
					direction = DIRECTION::RIGHT;
				}
				else if (map[player_pos.x - 1][player_pos.y] == 1)
				{
					direction = DIRECTION::UP;
				}
			}

			else if (player_dir == DIRECTION::RIGHT) // ж,辦,鼻,謝
			{
				if (map[player_pos.x + 1][player_pos.y] == 1)
				{
					direction = DIRECTION::DOWN;
				}
				else if (map[player_pos.x][player_pos.y + 1] == 1)
				{
					direction = DIRECTION::RIGHT;
				}
				else if (map[player_pos.x - 1][player_pos.y] == 1)
				{
					direction = DIRECTION::UP;
				}
				else if (map[player_pos.x][player_pos.y - 1] == 1)
				{
					direction = DIRECTION::LEFT;
				}
			}

			else if (player_dir == DIRECTION::LEFT) // 鼻,謝,ж,辦
			{
				if (map[player_pos.x - 1][player_pos.y] == 1)
				{
					direction = DIRECTION::UP;
				}
				else if (map[player_pos.x][player_pos.y - 1] == 1)
				{
					direction = DIRECTION::LEFT;
				}
				else if (map[player_pos.x + 1][player_pos.y] == 1)
				{
					direction = DIRECTION::DOWN;
				}
				else if (map[player_pos.x][player_pos.y + 1] == 1)
				{
					direction = DIRECTION::RIGHT;
				}
			}

			else if (player_dir == DIRECTION::UP) // 辦,鼻,謝,ж
			{
				if (map[player_pos.x][player_pos.y + 1] == 1)
				{
					direction = DIRECTION::RIGHT;
				}
				else if (map[player_pos.x - 1][player_pos.y] == 1)
				{
					direction = DIRECTION::UP;
				}
				else if (map[player_pos.x][player_pos.y - 1] == 1)
				{
					direction = DIRECTION::LEFT;
				}
				else if (map[player_pos.x + 1][player_pos.y] == 1)
				{
					direction = DIRECTION::DOWN;
				}
			}

			player_dir = direction;

		}



		switch (direction)
		{
		case DIRECTION::LEFT:
			if (map[player_pos.x][player_pos.y - 1] == 1)
			{
				player_pos.y--;
			}
			break;

		case DIRECTION::RIGHT:
			if (map[player_pos.x][player_pos.y + 1] == 1)
			{
				player_pos.y++;
			}
			break;

		case DIRECTION::UP:
			if (player_pos.x - 1 >= 0)
			{
				if (map[player_pos.x - 1][player_pos.y] == 1)
				{
					player_pos.x--;
				}
			}
			break;

		case DIRECTION::DOWN:
			player_pos.x++;
			if (map[player_pos.x][player_pos.y] == 0 || map[player_pos.x][player_pos.y] == 2)
			{
				player_pos.x--;
			}
			break;
		}



		//式式式式式式式式式式式式式式式式式式式式式式
		//system("pause");
		system("cls");
	}




	return 0;
}