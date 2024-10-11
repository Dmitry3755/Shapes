#include <iostream>
#include <windows.h>
#include "Point3D.h"

class console {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void consolInit() {
		setlocale(LC_ALL, "Russian");
		system("cls");
	}
	CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBuferInfo() {
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
		if (!GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo)) {
			std::cerr << "Не удалось получить информацию о консоли.\n";
		}
		return screenBufferInfo;
	}
	void setCursorVisible(bool visible) {
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(hConsole, &cursorInfo);
		cursorInfo.bVisible = visible;
		SetConsoleCursorInfo(hConsole, &cursorInfo);
	}
	void setCursorPosition(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position = { x, y };
		SetConsoleCursorPosition(hConsole, position);
	}
};