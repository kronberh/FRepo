#include  "Food.h" 
extern HANDLE output ;

COORD SetFood(int width, int height, COORD start)
{
	int xmin = 2 + start.X;
	int xmax = start.X + width - 2;
	int ymin = 2 + start.Y;
	int ymax = start.Y + height - 2;
	srand(time(0));
	int x_food = xmin + rand() % (xmax - xmin + 1);
	int y_food = ymin + rand() % (ymax - ymin + 1);
	COORD food_coord = { x_food,y_food };

	return food_coord;
}

void TypeFood(COORD food_coord, char symbol_food)
{
	SetConsoleTextAttribute(output, (WORD)((0 << 4) | 4));
	SetCursor(food_coord);
	cout << symbol_food;
	
	SetConsoleTextAttribute(output, (WORD)((0 << 4) | 15));
}
