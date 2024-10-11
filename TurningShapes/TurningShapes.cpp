// TurningShapes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include "Windows.h"
#include "Point3D.h"
#include "console.h"
#include "buffer.h"
#include "square.h"
#include "rectangle.h"
#include <vector>

using namespace std;

int main()
{
	bool running = true;
	int radius = 5;

	buffer buf;
	console console;
	Point3D point;
	//square square(radius);
	rectangle rectangle(radius);
	MSG msg = { 0 };

	console.consolInit();
	console.setCursorVisible(false);

	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo = console.getConsoleScreenBuferInfo();

	float height = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top;
	float width = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left;

	point.calculateCenter(screenBufferInfo);
	rectangle.setCenter(point);

	vector<string> buffer(height, string(width, ' '));

	RegisterHotKey(NULL, 1, MOD_CONTROL, 0x51);

	while (running) {
		buf.clearBuffer(buffer, height, width);
		console.setCursorPosition(0, 0);
		rectangle.draw3D(point, buffer);
		buf.drawBuffer(buffer);

		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_HOTKEY && msg.wParam == 1) {  // Горячая клавиша 'CTRL + Q'
				running = false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			point.y -= 2;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			point.y += 2;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			point.x -= 4;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			point.x += 4;
		}
		Sleep(10);
	}

	UnregisterHotKey(NULL, 1);
	std::cin.get();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
