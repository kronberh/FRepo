
#include "Cursor.h"
extern HANDLE output ;
void SetCursor(COORD cd)
{
	COORD pos{ cd.X,cd.Y };
	SetConsoleCursorPosition(output, pos);
}


void CursorInvisible()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(output, &info);
}
