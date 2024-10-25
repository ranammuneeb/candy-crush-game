

#include < iostream >

#include <random>

#include <windows.h>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define UP 2
#define DOWN 4
#define LEFT 1
#define RIGHT 3
#define ENTER 5

using namespace std;

void
gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void
myLine(int x1, int y1, int x2, int y2, int r, int g, int b)	//use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(r, g, b));	//2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool
isCursorKeyPressed(int& whichKey)	//whichKey passed as reference.... 
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

		whichKey = 3;		// 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;		// 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{

		whichKey = 5;		// 5 if enter key is pressed
		return true;
	}
	return false;
}

void
myRect(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 255, 255));	//Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void
myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(250, 255, 47));	//Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}


void
diamond(int i, int j)
{
	int r = 74;

	int b = 0;

	int g = 100;

	float x = (j + 0.5) * 70;

	float y = (i + 0.5) * 70;

	myLine(x, y + 20, x + 20, y, r, g, b);

	myLine(x + 20, y, x + 41, y + 21, r, g, b);

	myLine(x, y + 20, x + 20, y + 40, r, g, b);

	myLine(x + 20, y + 40, x + 40, y + 20, r, g, b);





}

void
triangle(int i, int j)
{
	float x = (j + 0.5) * 70;

	float y = (i + 0.5) * 70;

	int r =170;

	int b = 79;

	int g = 95;

	myLine(x + 20, y, x + 40, y + 40, r, g, b);

	myLine(x, y + 40, x + 20, y, r, g, b);

	myLine(x, y + 40, x + 40, y + 40, r, g, b);




}

void
cross(int i, int j)
{
	float x = (j + 0.6) * 70;

	float y = (i + 0.6) * 70;

	int r = 242;

	int b = 50;

	int g = 50;;

	myLine(x, y, x + 30, y + 30, r, g, b);


	myLine(x + 30, y, x, y + 30, r, g, b);

}


void
paralellograms(int i, int j)
{

	float x = (j + 0.6) * 70;

	float y = (i + 0.6) * 70;

	int r = 255;

	int b = 215;

	int g = 0;

	myLine(x, y + 5, x + 30, y + 5, r, g, b);

	myLine(x - 10, y + 25, x + 20, y + 25, r, g, b);

	myLine(x + 30, y + 5, x + 20, y + 25, r, g, b);

	myLine(x - 10, y + 25, x, y + 5, r, g, b);



}



void
cursor(int x, int y, int r, int g, int b)
{


	myLine(x, y, x, y + 50, r, g, b);

	myLine(x, y, x + 50, y, r, g, b);

	myLine(x + 50, y, x + 50, y + 50, r, g, b);

	myLine(x + 50, y + 50, x, y + 50, r, g, b);

}


void
grid1(int grid[10][10])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = rand() % 5;
		}
	}
}

void
printboard(int grid[10][10], int x1, int y1)
{
	system("cls ");
	x1 = 40;

	y1 = 40;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (grid[i][j] == 0 )

			{

				cross(i,j );
			}
			if (grid[i][j] == 1)

			{

				myRect(x1 + (j * 70), y1 + (i * 70), x1 + 30 + (j * 70),
					y1 + 30 + (i * 70),0, 83, 93);
			}

			if (grid[i][j] == 2)

			{

				myEllipse(x1 + (j * 70), y1 + (i * 70), x1 + 30 + (j * 70),
					y1 + 30 + (i * 70), 232, 70, 79);
			}
			if (grid[i][j] == 3)

			{

				diamond(i, j);
			}

			if (grid[i][j] == 4)
			{
				triangle(i, j);
			}

			if (grid[i][j] == 5)
			{
				paralellograms(i, j);
			}


		}
	}
}

void
printtable(int x1, int y1)
{
	x1 = 20;
	y1 = 20;
	for (int i = 0; i < 8; i++)

	{

		myLine(x1, 20, x1, 580, 230, 230, 250);

		x1 = x1 + 70;

		myLine(20, y1, 580, y1, 230, 230, 250);

		y1 = y1 + 70;

	}
	myLine(20, x1, 580, x1, 230, 230, 250);

	x1 = x1 + 70;
	myLine(y1, 20, y1, 580, 230, 230, 250);

	y1 = y1 + 70;
}

void
swapgems(int grid[10][10], int i, int j, int i1, int j1)
{
	swap(grid[i][j], grid[i1][j1]);
}

void
checkboard(int grid[10][10])
{
	for (int i = 0; i < 8; i++)

	{
		for (int j = 0; j < 8; j++)

		{
			
			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2]
				&& grid[i][j + 2] == grid[i][j])
			{
				grid[i][j] = rand() % 5;

				grid[i][j + 1] = rand() % 5;

				grid[i][j + 2] = rand() % 5;

			}

			else if (grid[i][j] == grid[i][j - 1]
				&& grid[i][j - 1] == grid[i][j + 1]
				&& grid[i][j + 1] == grid[i][j])
			{

				grid[i][j] = rand() % 5;

				grid[i][j - 1] = rand() % 5;

				grid[i][j + 1] = rand() % 5;
			}

			else if (grid[i][j] == grid[i][j - 1]
				&& grid[i][j - 1] == grid[i][j - 2]
				&& grid[i][j - 2] == grid[i][j])
			{
				

				grid[i][j - 1] = rand() % 5;

				grid[i][j - 2] = rand() % 5;

				grid[i][j] = rand() % 5;
			}
			else if (grid[i][j] == grid[i + 1][j]
				&& grid[i + 1][j] == grid[i + 2][j]
				&& grid[i + 2][j] == grid[i][j])

			{
				

				grid[i][j] = rand() % 5;

				grid[i + 1][j] = rand() % 5;

				grid[i + 2][j] = rand() % 5;
			}

			else if (grid[i][j] == grid[i - 1][j]
				&& grid[i - 1][j] == grid[i + 1][j]
				&& grid[i + 1][j] == grid[i][j])
			{
		

				grid[i - 1][j] = rand() % 5;

				grid[i][j] = rand() % 5;

				grid[i + 1][j] = rand() % 5;
			}

			else if (grid[i][j] == grid[i - 1][j]
				&& grid[i - 1][j] == grid[i - 2][j]
				&& grid[i - 2][j] == grid[i][j])

			{
				

				grid[i - 1][j] = rand() % 5;

				grid[i - 2][j] = rand() % 5;

				grid[i][j] = rand() % 5;
			}
		}
	}
}

void
match3(int grid[10][10])
{
	int p;

	int q;

	for (int i = 0; i < 8; i++)

	{
		for (int j = 0; j < 8; j++)

		{
		

			 if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3])

			{
				p = i;

				q = j;

				for (int k = i - 1; k >= 0; k--)
				{

					grid[p][q + 1] = grid[p - 1][q + 1];
					grid[p][q + 2] = grid[p - 1][q + 2];
					grid[p][q + 3] = grid[p - 1][q + 3];
					p--;


				}

				grid[i][j] = 5;

				grid[0][j + 1] = rand() % 5;

				grid[0][j + 2] = rand() % 5;

				grid[0][j + 3] = rand() % 5;




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])

			{
				p = i;

				q = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[p][q - 1] = grid[p - 1][q - 1];
					grid[p][q + 1] = grid[p - 1][q + 1];
					grid[p][q + 2] = grid[p - 1][q + 2];
					p--;


				}

				grid[i][j] = 5;

				grid[0][j - 1] = rand() % 5;

				grid[0][j + 2] = rand() % 5;

				grid[0][j + 1] = rand() % 5;




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j - 3])

			{
				p = i;

				q = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[p][q - 1] = grid[p - 1][q - 1];
					grid[p][q - 2] = grid[p - 1][q - 2];
					grid[p][q - 3] = grid[p - 1][q - 3];
					p--;


				}

				grid[i][j] = 5;

				grid[0][j - 1] = rand() % 5;

				grid[0][j - 2] = rand() % 5;

				grid[0][j - 3] = rand() % 5;




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j + 1])

			{
				p = i;

				q = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[p][q - 1] = grid[p - 1][q - 1];
					grid[p][q - 2] = grid[p - 1][q - 2];
					grid[p][q + 1] = grid[p - 1][q + 1];
					p--;


				}

				grid[i][j] = 5;

				grid[0][j - 1] = rand() % 5;

				grid[0][j - 2] = rand() % 5;

				grid[0][j + 1] = rand() % 5;




			}
			//-------------------------------------------------------------------------------------------//
			else if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])

			{
				p = i;

				q = j;



				for (int k = i - 1; k >= 0; k--)
				{
					grid[p][q] = grid[p - 1][q];
					grid[p][q + 1] = grid[p - 1][q + 1];
					grid[p][q + 2] = grid[p - 1][q + 2];
					p--;


				}

				grid[0][j] = rand() % 5;

				grid[0][j + 1] = rand() % 5;

				grid[0][j + 2] = rand() % 5;


				checkboard(grid);



			}

			else if (grid[i][j] == grid[i][j - 1]
				&& grid[i][j - 1] == grid[i][j + 1])
			{

				p = i;

				q = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[p][q] = grid[p - 1][q];
					grid[p][q + 1] = grid[p - 1][q + 1];
					grid[p][q - 1] = grid[p - 1][q - 1];
					p--;
				}

				grid[0][j] = rand() % 5;

				grid[0][j - 1] = rand() % 5;

				grid[0][j + 1] = rand() % 5;

				checkboard(grid);

			}

			else if (grid[i][j] == grid[i][j - 1]
				&& grid[i][j - 1] == grid[i][j - 2]
				&& grid[i][j - 2] == grid[i][j])
			{

				p = i;

				q = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[p][q] = grid[p - 1][q];
					grid[p][q - 1] = grid[p - 1][q - 1];
					grid[p][q - 2] = grid[p - 1][q - 2];
					p--;
				}

				grid[0][j] = rand() % 5;

				grid[0][j - 1] = rand() % 5;

				grid[0][j - 2] = rand() % 5;

				checkboard(grid);

			}
			//-----------------------------------------------------------------------------------------//
			else if (grid[i][j] == grid[i + 1][j]
			&& grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i + 3][j])

			{

			p = i;


			q = j;


			for (int k = i - 1; k >= 3; k--)
			{
				grid[p + 1][q] = grid[p + 1][q - 1];
				grid[p + 2][q] = grid[p + 2][q - 1];
				grid[p + 3][q] = grid[p + 3][q - 1];
				q--;
			}


			grid[i][j] = 5;

			grid[1][j + 1] = rand() % 5;

			grid[2][j + 2] = rand() % 5;

			grid[3][j + 3] = rand() % 5;


			checkboard(grid);



			}
			
			else if (grid[i][j] == grid[i - 1][j]
			&& grid[i - 1][j] == grid[i + 1][j] && grid[i+1][j] == grid[i + 2][j])

			{

			p = i;
			q = j;
			for (int k = i - 1; k >= 0; k--)
			{
				
				grid[p + 1][q] = grid[p + 1][q - 1];
				grid[p - 1][q] = grid[p - 1][q - 1];
				grid[p + 2][q] = grid[p + 2][q - 1];
				q--;
			}

			grid[i][j] = rand() % 5;

			grid[1][j - 1] = rand() % 5;

			grid[2][j + 1] = rand() % 5;

			grid[3][j + 2] = rand() % 5;


			checkboard(grid);


			}
			
			else if (grid[i][j] == grid[i - 1][j]
			&& grid[i - 1][j] == grid[i - 2][j] && grid[i-2][j]==grid[i-3][j])

			{
			p = i;
			q = j;


			for (int k = i - 1; k >= 0; k--)
			{
				
				grid[p - 1][q] = grid[p - 1][q - 1];
				grid[p - 2][q] = grid[p - 2][q - 1];
				grid[p - 3][q] = grid[p - 3][q - 1];
				q--;
			}

			grid[i][j] = 5;

			grid[1][j - 1] = rand() % 5;

			grid[2][j - 2] = rand() % 5;

			grid[3][j - 3] = rand() % 5;

			checkboard(grid);

			}

			//-------------------------------------------------------------------------------------------------//
			else if (grid[i][j] == grid[i + 1][j]
				&& grid[i + 1][j] == grid[i + 2][j]) 

			{

				p = i;


				q = j;


				for (int k = i - 1; k >= 3; k--)
				{
					grid[p][q] = grid[p][q - 1];
					grid[p + 1][q] = grid[p + 1][q - 1];
					grid[p + 2][q] = grid[p + 2][q - 1];
					q--;
				}

				grid[0][j] = rand() % 5;

				grid[1][j+1] = rand() % 5;

				grid[2][j+2] = rand() % 5;


				checkboard(grid);



			}

			else if (grid[i][j] == grid[i - 1][j]
				&& grid[i - 1][j] == grid[i + 1][j])

			{

				p = i;
				q = j;
				for (int k = i - 1; k >= 0; k--)
				{
					grid[p][q] = grid[q][q - 1];
					grid[p + 1][q] = grid[p + 1][q - 1];
					grid[p - 1][q] = grid[p - 1][q - 1];
					q--;
				}

				grid[0][j] = rand() % 5;

				grid[1][j-1] = rand() % 5;

				grid[2][j+1] = rand() % 5;


				checkboard(grid);


			}

			else if (grid[i][j] == grid[i - 1][j]
				&& grid[i - 1][j] == grid[i - 2][j])

			{
				p = i;
				q = j;


				for (int k = i - 1; k >= 0; k--)
				{
					grid[p][q] = grid[p][q - 1];
					grid[p - 1][q] = grid[p - 1][q - 1];
					grid[p - 2][q] = grid[p - 2][q - 1];
					q--;
				}

				grid[0][j] = rand() % 5;

				grid[1][j-1] = rand() % 5;

				grid[2][j-2] = rand() % 5;


				checkboard(grid);

			}
			//-----------------------------------------------------------------------------------------------//



		}
 
}			checkboard(grid);
		
}



int
main()

{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	while (1)

	{

		int grid[10][10];

		int key = 0;
		
		int x1 = 40;

		int y1 = 40;

		grid1(grid);

		checkboard(grid);

		printboard(grid, x1, y1);

		x1 = 20, y1 = 20;

		printtable(x1, y1);

		x1 = 30;
		y1 = 30;

		int r = 0, g = 255, b = 255;

		int i = 0;

		int j = 0;

		cursor(x1, y1, r, g, b);

		while (1)

		{
			

			if (isCursorKeyPressed(key) == 1)

			{

				r = 0, g = 0, b = 0;

				cursor(x1, y1, r, g, b);


				if (key == RIGHT)

				{
					

					
						j = j + 1;

						x1 = x1 + 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);
					
						
					
				}



				else if (key == LEFT)

				{
						j = j - 1;

						x1 = x1 - 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);
					
					

				}


				else if (key == UP)

				{
					
						i = i - 1;

						y1 = y1 - 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);
					
					

				}

				else if (key == DOWN)

				{
					
						i = i + 1;

						y1 = y1 + 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);
					
					


				}
				else if (key == 5)
				{


					while (1)

					{
						if (isCursorKeyPressed(key) == 1)

						{
							if (key == 1)

							{
								
								
							
									swapgems(grid, i, j, i, j - 1);

									match3(grid);

									printboard(grid, x1, y1);

									printtable(x1, y1);


									break;
								
							

							}
							if (key == 3)

							{
								swapgems(grid, i, j, i, j + 1);
								
								match3(grid);
								
								printboard(grid, x1, y1);
								
								printtable(x1, y1);
								
								break;
							
							}
							if (key == 2)

							{
								swapgems(grid, i, j, i - 1, j);
								
								match3(grid);
								
								printboard(grid, x1, y1);
								
								printtable(x1, y1);
								
								break;
							
							}


							if (key == 4)

							{

								swapgems(grid, i, j, i + 1, j);
								
								match3(grid);
								
								printboard(grid, x1, y1);
								
								printtable(x1, y1);


								break;

							}

						}

					}



				}



			}

		}









	}

	system("pause");


}
