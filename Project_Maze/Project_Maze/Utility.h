#pragma once

#include <conio.h>
#include <Windows.h>

void SetColor(unsigned short text, unsigned short back);

int GetCommand();

enum class COLOR { WHITE, RED, GREEN, BLUE, BLACK };

void SetColor(COLOR color);