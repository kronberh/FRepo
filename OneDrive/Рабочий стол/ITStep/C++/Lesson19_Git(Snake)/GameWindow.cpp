#include "GameWindow.h"
void ShowWindow(int width, int height, COORD start)
{
	SetCursor(start);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width + start.X; i++)
			if ((j == 0 && i < width) || (j == height - 1 && i >= start.X))
				cout << '-';
			else if ((i == start.X || i == width + start.X - 1) && j != 0)
				cout << '|';
			else cout << ' ';
		cout << endl;

	}




}
