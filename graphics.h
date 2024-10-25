#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void myLine2(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 20, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_SPACE);
	if (key == 1)
	{
		whichKey = 5;//5 IF SPACE KEY IS PRESSESd
		return true;
	}




	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, float r, float g, float b)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(r, g, b)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH);  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void cursor(int x, int y, int r, int g, int b)
{


	myLine(x, y, x, y + 40, r, g, b);

	myLine(x, y, x + 40, y, r, g, b);

	myLine(x + 40, y, x + 40, y + 40, r, g, b);

	myLine(x + 40, y + 40, x, y + 40, r, g, b);

}
void triangle(int x, int y, int R, int G, int B)
{
	int x1 = (y + 2.5) * 70;


	int y1 = (x + 2.5) * 70;
	myLine(x1 + 20, y1, x1 + 25, y1 + 20, R, G, B);

	myLine(x1 + 20, y1, x1, y1 + 20, R, G, B);
	myLine(x1, y1 + 20, x1 + 25, y1 + 20, R, G, B);
}
void diamond(int x, int y, int R, int G, int B)
{
	int x1 = (y + 2.5) * 70;


	int y1 = (x + 2.5) * 70;
	myLine(x1 + 5, y1, x1 + 15, y1, R, G, B);
	myLine(x1, y1 + 5, x1 + 5, y1, R, G, B);
	myLine(x1 + 15, y1, x1 + 20, y1 + 5, R, G, B);
	myLine(x1 + 20, y1 + 5, x1 + 10, y1 + 20, R, G, B);
	myLine(x1, y1 + 5, x1 + 10, y1 + 20, R, G, B);
}
void crystal(int x, int y, int R, int G, int B)
{
	int x1 = (y + 2.5) * 70;


	int y1 = (x + 2.5) * 70;

	myLine(x1 + 10, y1, x1 + 20, y1 + 10, R, G, B);
	myLine(x1 + 20, y1 + 10, x1 + 10, y1 + 20, R, G, B);
	myLine(x1 + 10, y1, x1, y1 + 10, R, G, B);
	myLine(x1, y1 + 10, x1 + 10, y1 + 20, R, G, B);

}

void rectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 67, 16)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void oval(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void ellipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 255, 255));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void font(int x, int y)
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = x;
	fontex.dwFontSize.Y = y;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

}
void mainpage()
{


	int x2 = 0;
	myRectangle(x2, 0, x2 + 5000, 5000, 0, 0, 0, 255.0, 128.0, 128.0);
	//myEllipse(500,140,900,390,192,192,192,128,128,0);
	Sleep(300);
	myLine2(100, 300, 100, 400, 128, 0, 0);//C
	myLine2(100, 300, 200, 300, 128, 0, 0);
	myLine2(100, 400, 200, 400, 128, 0, 0);
	Sleep(300);

	myLine2(300, 300, 300, 400, 128, 0, 0);//A
	myLine2(300, 300, 400, 300, 128, 0, 0);
	myLine2(400, 300, 400, 400, 128, 0, 0);
	myLine2(300, 350, 400, 350, 128, 0, 0);
	myLine2(500, 300, 500, 400, 128, 0, 0);
	myLine2(600, 300, 600, 400, 128, 0, 0);
	myLine2(500, 300, 600, 400, 128, 0, 0);
	Sleep(300);

	myLine2(700, 290, 700, 410, 128, 0, 0);//D
	myLine2(800, 300, 800, 400, 128, 0, 0);
	myLine2(700, 300, 800, 300, 128, 0, 0);
	myLine2(700, 400, 800, 400, 128, 0, 0);
	Sleep(300);

	myLine2(1000, 300, 1000, 400, 128, 0, 0);//Y
	myLine2(900, 300, 900, 350, 128, 0, 0);
	myLine2(900, 350, 1000, 350, 128, 0, 0);
	myLine2(900, 400, 1000, 400, 128, 0, 0);
	Sleep(400);

	myLine2(700, 500, 700, 600, 128, 0, 0);//C
	myLine2(700, 500, 800, 500, 128, 0, 0);
	myLine2(700, 600, 800, 600, 128, 0, 0);
	Sleep(300);

	myLine2(900, 500, 900, 600, 128, 0, 0);//R
	myLine2(900, 500, 1000, 500, 128, 0, 0);
	myLine2(400, 300, 400, 400, 128, 0, 0);
	myLine2(900, 550, 1000, 550, 128, 0, 0);
	myLine2(1000, 500, 1000, 550, 128, 0, 0);
	myLine2(900, 550, 1000, 600, 128, 0, 0);
	Sleep(300);


	myLine2(1100, 500, 1100, 600, 128, 0, 0);//U
	myLine2(1200, 500, 1200, 600, 128, 0, 0);
	myLine2(1100, 600, 1200, 600, 128, 0, 0);
	Sleep(300);

	myLine2(1300, 500, 1300, 550, 128, 0, 0);//S
	myLine2(1300, 500, 1400, 500, 128, 0, 0);
	myLine2(1300, 550, 1400, 550, 128, 0, 0);
	myLine2(1400, 550, 1400, 600, 128, 0, 0);
	myLine2(1300, 600, 1400, 600, 128, 0, 0);
	Sleep(300);

	myLine2(1500, 500, 1500, 600, 128, 0, 0);//H
	myLine2(1600, 500, 1600, 600, 128, 0, 0);
	myLine2(1500, 550, 1600, 550, 128, 0, 0);

}
