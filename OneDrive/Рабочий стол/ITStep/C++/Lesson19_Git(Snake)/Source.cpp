#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <windows.graphics.h>

#include "Cursor.h"
#include "GameWindow.h"
#include "Food.h"
using namespace std;


  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

void MainSnake(COORD snake[], int size,char symbol, int width, int height, COORD start );

void TypeSymb(COORD symb, char symbol)
{
	SetCursor(symb);
	cout << symbol;
}


bool SnakeGetWind(COORD head, int width, int height, COORD start);
bool SnakeGetSnake(COORD snake[],int count);
bool SnakeGetFood(COORD head, COORD food);
int main()
{

	
	CursorInvisible();

	COORD start = { 40,5 };/////координати початку грального вікна

	int width = 40, height = 20;/////////параметри грального вікна
	ShowWindow(width, height,start);


	COORD head = { start.X + width / 2, start.Y + height / 2 };
	COORD tail = { head.X - 1, head.Y };
	const int size = 10;///////максимальний розмір змійки
	COORD snake[size] = { tail,head };/////спочатку масив змійки містить тільки голову та хвіст

	//char symbol = 219;
	char symbol = '@';

	


	MainSnake(snake,size,  symbol, width, height, start);


	return 0;
}







void MainSnake(COORD snake[], int size, char symbol,int width, int height, COORD start )
{
	

	

	bool ate = false;

	int count = 2;

	int x = 1, y = 0;
	COORD food=SetFood(  width, height, start);
	TypeFood(food,  '*');
	while (true)
	{
	
			if (GetAsyncKeyState(VK_LEFT) & 0x01)
			{


				y = 0;
				if(x!=1)
				x = -1;

			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
			{



				y = 0;
				if (x != -1)
				x = 1;

			}
			else if (GetAsyncKeyState(VK_UP) & 0x01)
			{

				if (y != 1)
				y = -1;
				x = 0;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x01)
			{

				if (y != -1)
				y = 1;
				x = 0;

			}

			if (SnakeGetFood(snake[count-1],food))
			{
				count++;
				snake[count - 1] = snake[count - 2];
				
			 food = SetFood( width, height, start);
				TypeFood(food, '*');
		    }
			else
			{
				TypeSymb(snake[0],  ' ');///////хвіст перемальовуємо пробілом
				for (int i = 0; i < count - 1; i++)
					snake[i] = snake[i + 1];
			}
			
			snake[count-1].X += x;////////зміна координати голови згідно напрямку руху
			snake[count-1].Y += y;
		
			TypeSymb(snake[count - 1], symbol);//////////////домальовуєм нову голову 


			
		
			if (count == size)
			{
				
				cout << "You've got max size!";
				break;
			}
			else if (SnakeGetWind(snake[count - 1], width, height, start) || SnakeGetSnake(snake,count))
			{
				cout << "Game over!";
				break;
			}
			Sleep(300);
	}

}

bool SnakeGetWind(COORD head, int width, int height, COORD start)
{
	if (head.X == start.X || head.X == start.X + width)
		return true;
	else if (head.Y == start.Y || head.Y == start.Y + height)
		return true;
	return false;
}

bool SnakeGetSnake(COORD snake[], int count)
{
	for (int i = 0; i < count - 1; i++)
		if (snake[count - 1].X == snake[i].X && snake[count - 1].Y == snake[i].Y)
			return true;
	return false;
}

bool SnakeGetFood(COORD head, COORD food)
{
	if (head.X == food.X && head.Y == food.Y)
		return true;
	return false;
}



