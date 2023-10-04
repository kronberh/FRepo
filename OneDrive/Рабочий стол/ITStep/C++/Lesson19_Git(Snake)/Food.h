#pragma once
#include <iostream>
#include <Windows.h>
#include "Cursor.h"

using namespace std;



COORD SetFood(int width, int height, COORD start);
void TypeFood(COORD food_coord, char symbol_food);