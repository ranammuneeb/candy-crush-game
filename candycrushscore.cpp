
#include <stdlib.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include<stdlib.h>
#include <random>
#include <windows.h>
#include <stdio.h>


#include"graphics.h"
using namespace std;
void instruction()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 3);
	cout << setw(70);
	cout << setfill('*');
	cout << "WELCOME *******************";
	cout << setfill('*');
	cout << endl;
	//SetConsoleTextAttribute(color, 3);
	cout << setw(70);
	//cout << setfill('*');
	cout << "EACH SWAP SCORE 50************" << endl;
	cout << setw(70);
	/*cout << setfill('*');*/
	cout << "YOU HAVE 10 MOVE AFTER 10 MOVE GAME WILL BE OVER**********" << endl;
	cout << setw(60);
	cout << "USE SPACE FOR SWAP*********" << endl;




}
int getRandomValue()
{
	int val;
	val = rand() % 7;
	if (val == 0)
	{
		getRandomValue();
	}
	else	return val;
}
void grid1(int grid[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = getRandomValue();
		}
	}
}

void gridshape(int grid[8][8], int x1, int y1)
{
	system("cls");
	x1 = 180;
	y1 = 180;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (grid[i][j] == 1)

			{

				crystal(i, j, 255, 208, 0);
			}
			if (grid[i][j] == 2)

			{

				rectangle(x1 + (j * 70), y1 + (i * 70), x1 + 20 + (j * 70), y1 + 20 + (i * 70), 255, 0, 0);
			}

			if (grid[i][j] == 3)

			{


				ellipse(x1 + (j * 70), y1 + (i * 70), x1 + 20 + (j * 70), y1 + 20 + (i * 70), 255, 255, 255);
			}
			if (grid[i][j] == 4)

			{

				diamond(i, j, 0, 255, 255);
			}

			if (grid[i][j] == 5)
			{
				triangle(i, j, 216, 0, 255);
			}

			if (grid[i][j] == 6)
			{
				oval(x1 + (j * 70), y1 + (i * 70), x1 + 20 + (j * 70), y1 + 30 + (i * 70), 0, 80, 1);
			}
			if (grid[i][j] == 7)
			{
				triangle(i, j, 168, 50, 137);
			}


		}
	}
}

void gridgen(int x1, int y1)
{
	x1 = 160;
	y1 = 160;
	for (int i = 0; i < 8; i++)

	{

		myLine(x1, 160, x1, 720, 230, 230, 250);

		x1 = x1 + 70;

		myLine(160, y1, 720, y1, 230, 230, 250);

		y1 = y1 + 70;

	}
	myLine(160, x1, 720, x1, 230, 230, 250);

	x1 = x1 + 70;
	myLine(y1, 160, y1, 720, 230, 230, 250);

	y1 = y1 + 70;
}

void swapgems(int grid[8][8], int i, int j, int i1, int j1)
{
	swap(grid[i][j], grid[i1][j1]);

}

void check3(int grid[8][8])
{
	for (int i = 0; i < 8; i++)

	{
		for (int j = 0; j < 8; j++)

		{

			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j])//column1
			{
				grid[i][j] = getRandomValue();

				grid[i][j + 1] = getRandomValue();

				grid[i][j + 2] = getRandomValue();

			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j])//colsame3
			{

				grid[i][j] = getRandomValue();

				grid[i][j - 1] = getRandomValue();

				grid[i][j + 1] = getRandomValue();
			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j])//leftcol
			{


				grid[i][j - 1] = getRandomValue();

				grid[i][j - 2] = getRandomValue();

				grid[i][j] = getRandomValue();
			}
			else if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i][j])//rightrow

			{


				grid[i][j] = getRandomValue();

				grid[i + 1][j] = getRandomValue();

				grid[i + 2][j] = getRandomValue();
			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i][j])//row
			{


				grid[i - 1][j] = getRandomValue();

				grid[i][j] = getRandomValue();

				grid[i + 1][j] = getRandomValue();
			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i - 2][j] && grid[i - 2][j] == grid[i][j])//leftrow

			{


				grid[i - 1][j] = getRandomValue();

				grid[i - 2][j] = getRandomValue();

				grid[i][j] = getRandomValue();
			}
		}
	}
}

void sameswap3(int grid[8][8])
{
	int r;

	int col;

	for (int i = 0; i < 8; i++)

	{
		for (int j = 0; j < 8; j++)

		{


			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3])

			{
				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col + 1] = grid[r - 1][col + 1];//checkingthecolumn
					grid[r][col + 2] = grid[r - 1][col + 2];
					grid[r][col + 3] = grid[r - 1][col + 3];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();

				grid[0][j + 3] = getRandomValue();




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();

				grid[0][j + 1] = getRandomValue();




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j - 3])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					grid[r][col - 3] = grid[r - 1][col - 3];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();

				grid[0][j - 3] = getRandomValue();




			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j + 1])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					grid[r][col + 1] = grid[r - 1][col + 1];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();

				grid[0][j + 1] = getRandomValue();




			}
			
			else if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])

			{
				r = i;

				col = j;



				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					r--;


				}

				grid[0][j] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();


				check3(grid);



			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1])
			{

				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col - 1] = grid[r - 1][col - 1];
					r--;
				}

				grid[0][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				check3(grid);


			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j])
			{

				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];
					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					r--;
				}

				grid[0][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();

				check3(grid);

			}

			else if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i + 3][j])

			{

				r = i;


				col = j;


				for (int k = i - 1; k >= 3; k--)
				{
					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r + 2][col] = grid[r + 2][col - 1];
					grid[r + 3][col] = grid[r + 3][col - 1];
					col--;
				}


				grid[i][j] = 5;

				grid[1][j + 1] = getRandomValue();

				grid[2][j + 2] = getRandomValue();

				grid[3][j + 3] = getRandomValue();


				check3(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j])

			{

				r = i;
				col = j;
				for (int k = i - 1; k >= 0; k--)
				{

					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r - 1][col] = grid[r - 1][col - 1];
					grid[r + 2][col] = grid[r + 2][col - 1];
					col--;
				}

				grid[i][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j + 1] = getRandomValue();

				grid[3][j + 2] = getRandomValue();


				check3(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i - 2][j] && grid[i - 2][j] == grid[i - 3][j])

			{
				r = i;
				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r - 1][col] = grid[r - 1][col - 1];
					grid[r - 2][col] = grid[r - 2][col - 1];
					grid[r - 3][col] = grid[r - 3][col - 1];
					col--;
				}

				grid[i][j] = 5;

				grid[1][j - 1] = getRandomValue();

				grid[2][j - 2] = getRandomValue();

				grid[3][j - 3] = getRandomValue();

				check3(grid);

			}


			else if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j])

			{

				r = i;


				col = j;


				for (int k = i - 1; k >= 3; k--)
				{
					grid[r][col] = grid[r][col - 1];
					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r + 2][col] = grid[r + 2][col - 1];
					col--;
				}

				grid[0][j] = getRandomValue();

				grid[1][j + 1] = getRandomValue();

				grid[2][j + 2] = getRandomValue();


				check3(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i + 1][j])

			{

				r = i;
				col = j;
				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[col][col - 1];
					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r - 1][col] = grid[r - 1][col - 1];
					col--;
				}

				grid[0][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j + 1] = getRandomValue();


				check3(grid);


			}
			//checking the row
			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i - 2][j])

			{
				r = i;
				col = j;


				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r][col - 1];
					grid[r - 1][col] = grid[r - 1][col - 1];
					grid[r - 2][col] = grid[r - 2][col - 1];
					col--;
				}

				grid[0][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j - 2] = getRandomValue();


				check3(grid);

			}






		}

	}			check3(grid);

}
void swap4(int grid[8][8])
{
	int r;

	int col;

	for (int i = 0; i < 8; i++)

	{
		for (int j = 0; j < 8; j++)

		{


			if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3] && grid[i][j + 3] == grid[i][j + 4])

			{
				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					grid[r][col + 3] = grid[r - 1][col + 3];
					grid[r][col + 4] = grid[r - 1][col + 4];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();

				grid[0][j + 3] = getRandomValue();

				grid[0][j + 4] = 7;


			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					grid[r][col + 3] = grid[r - 1][col + 3];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][col + 3] = 7;


			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j - 3] && grid[i][j - 3] == grid[i][j - 4])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					grid[r][col - 3] = grid[r - 1][col - 3];
					grid[r][col - 4] = grid[r - 1][col - 4];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();

				grid[0][j - 3] = getRandomValue();

				grid[0][j - 4] = 7;


			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])

			{
				r = i;

				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					r--;


				}

				grid[i][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][j + 2] = 7;


			}
			
			else if (grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2] && grid[i][j + 2] == grid[i][j + 3])

			{
				r = i;

				col = j;



				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];
					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					grid[r][col + 3] = grid[r - 1][col + 3];
					r--;


				}

				grid[0][j] = getRandomValue();

				grid[0][j + 1] = getRandomValue();

				grid[0][j + 2] = getRandomValue();

				grid[0][j + 3] = 7;
				check3(grid);



			}

			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2])
			{

				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];

					grid[r][col + 1] = grid[r - 1][col + 1];
					grid[r][col + 2] = grid[r - 1][col + 2];
					grid[r][col - 1] = grid[r - 1][col - 1];
					r--;
				}

				grid[0][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j + 1] = getRandomValue();
				grid[0][j + 2] = 7;
				check3(grid);


			}
			else if (grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == grid[i][j - 2] && grid[i][j - 2] == grid[i][j] && grid[i][j] == grid[i][j + 1])
			{

				r = i;

				col = j;

				for (int k = i - 1; k >= 0; k--)
				{
					grid[r][col] = grid[r - 1][col];
					grid[r][col] = grid[r - 1][col + 1];
					grid[r][col - 1] = grid[r - 1][col - 1];
					grid[r][col - 2] = grid[r - 1][col - 2];
					r--;
				}

				grid[0][j] = getRandomValue();

				grid[0][j - 1] = getRandomValue();

				grid[0][j - 2] = getRandomValue();
				grid[0][j + 1] = 7;

				check3(grid);

			}

			else if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i + 3][j] && grid[i + 3][j] == grid[i + 4][j])

			{

				r = i;


				col = j;


				for (int k = i - 1; k >= 3; k--)
				{
					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r + 2][col] = grid[r + 2][col - 1];
					grid[r + 3][col] = grid[r + 3][col - 1];
					grid[r + 4][col] = grid[r + 4][col - 1];
					col--;
				}


				grid[i][j] = 5;

				grid[1][j + 1] = getRandomValue();

				grid[2][j + 2] = getRandomValue();

				grid[3][j + 3] = getRandomValue();
				grid[3][j + 4] = 7;

				check3(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j] && grid[i + 2][j] == grid[i + 3][j])

			{

				r = i;
				col = j;
				for (int k = i - 1; k >= 0; k--)
				{

					grid[r + 1][col] = grid[r + 1][col - 1];
					grid[r - 1][col] = grid[r - 1][col - 1];
					grid[r + 2][col] = grid[r + 2][col - 1];
					grid[r + 3][col] = grid[r + 3][col - 1];
					col--;
				}

				grid[i][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j + 1] = getRandomValue();

				grid[3][j + 2] = 7;


				check3(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i - 2][j] && grid[i - 2][j] == grid[i - 3][j] && grid[i - 3][j] == grid[i - 4][j])

			{
				r = i;
				col = j;


				for (int k = i - 1; k >= 0; k--)
				{

					grid[r - 1][col] = grid[r - 1][col - 1];
					grid[r - 2][col] = grid[r - 2][col - 1];

					grid[r - 3][col] = grid[r - 3][col - 1];
					grid[r - 4][col] = grid[r - 4][col - 1];
					col--;
				}

				grid[i][j] = 5;

				grid[1][j - 1] = getRandomValue();

				grid[2][j - 2] = getRandomValue();

				grid[3][j - 3] = getRandomValue();
				grid[4][j - 4] = 7;

				check3(grid);

			}


			/*else if (grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j])

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

				grid[0][j] = getRandomValue();

				grid[1][j + 1] = getRandomValue();

				grid[2][j + 2] = getRandomValue();


				checkboard(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i + 1][j])

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

				grid[0][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j + 1] = getRandomValue();


				checkboard(grid);


			}

			else if (grid[i][j] == grid[i - 1][j] && grid[i - 1][j] == grid[i - 2][j])

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

				grid[0][j] = getRandomValue();

				grid[1][j - 1] = getRandomValue();

				grid[2][j - 2] = getRandomValue();


				checkboard(grid);

			}*/






		}

	}			check3(grid);

}
//5
int main()
{

	int i = 0;//for x cordinate count

	int j = 0;//for y cordinate count
	int num = 1;
	int score = 0;
	int swap = 10;
	int a = 0;
	int grid[8][8];

	int key = 0;

	int x1 = 180;

	int y1 = 180;
	cout << "enter 1 " << endl;
	cin >> a;
	if (a == 1)
	{
		mainpage();
	}

	Sleep(2000);
	cout << "enter 2 " << endl;
	cin >> a;
	if (a == 2)
	{
		system("cls");
		
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		int grid[8][8];

		int key = 0;

		int x1 = 180;

		int y1 = 180;

		grid1(grid);

		check3(grid);

		gridshape(grid, x1, y1);

		x1 = 160, y1 = 160;

		gridgen(x1, y1);

		x1 = 170;
		y1 = 170;

		int r = 0, g = 255, b = 255;

		while (num)
		{


			cursor(x1, y1, r, g, b);

			instruction();
			cout << endl;
			SetConsoleTextAttribute(color, 6);
			cout << setw(90);
			cout << "LEFT SWAP ARE  " << swap << endl;
			cout << setw(90);
			cout << "SCORE IS  " << score << endl;

			while (num)

			{


				if (isCursorKeyPressed(key) == 1)

				{

					r = 0, g = 0, b = 0;

					cursor(x1, y1, r, g, b);


					



				    if (key == 1 && x1 > 230)
					{
						j = j - 1;

						x1 = x1 - 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);



					}


					else if (key == 2 && y1 > 230)

					{

						i = i - 1;

						y1 = y1 - 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);



					}
					else if (key == 3 && x1 < 600)
					{



						j = j + 1;

						x1 = x1 + 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);



					}
				


					else if (key == 4 && y1 < 600)

					{

						i = i + 1;

						y1 = y1 + 70;

						r = 0, g = 255, b = 255;

						cursor(x1, y1, r, g, b);




					}
					//setfill
					else if (key == 5)
					{

						score = score + 50;
						//cout << setw(100);
						//cout << "score is=" << score;
						swap -= 1;
						if (swap == 0)
						{
							cursor(x1, y1, 0, 0, 0);
							cursor(x1, y1, 0, 0, 0);
							cursor(x1, y1, 0, 0, 0);

							system("cls");

							font(100, 100);
							for (int i = 0; i < 3; i++)
							{
								cout << endl;
							}
							cout << setw(20);
							cout << "GAME OVER**********" << endl;

						}
						else

						{
							while (num)

							{
								if (isCursorKeyPressed(key) == 1)
								{
									if (key == 1)
									{



										swapgems(grid, i, j, i, j - 1);

										sameswap3(grid);
										swap4(grid);

										gridshape(grid, x1, y1);

										gridgen(x1, y1);
										SetConsoleTextAttribute(color, 6);
										//font(28, 28);
										/*for (int i = 0; i < 6; i++)
										{
											cout << endl;
										}*/
										instruction();
										cout << endl;
										SetConsoleTextAttribute(color, 6);
										cout << setw(90);
										cout << "LEFT SWAP ARE  " << swap << endl;
										cout << setw(90);
										cout << "SCORE IS  " << score;
										break;



									}
									if (key == 2)
									{

										swapgems(grid, i, j, i - 1, j);

										sameswap3(grid);
										swap4(grid);
										gridshape(grid, x1, y1);
										gridgen(x1, y1);
										SetConsoleTextAttribute(color, 6);
										//font(28, 28);
										/*for (int i = 0; i < 6; i++)
										{
											cout << endl;
										}*/

										//cout << endl;
										//cout << endl; cout << endl; cout << endl; cout << endl;
										//cout << endl; cout << endl;
										//cout << setfill('*');
										instruction();
										cout << endl;
										SetConsoleTextAttribute(color, 6);
										cout << setw(90);
										cout << "LEFT SWAP ARE  " << swap << endl;
										cout << setw(90);
										cout << "SCORE IS  " << score;

										break;

									}
									if (key == 3)
									{
										swapgems(grid, i, j, i, j + 1);

										sameswap3(grid);
										swap4(grid);
										gridshape(grid, x1, y1);

										gridgen(x1, y1);
										SetConsoleTextAttribute(color, 6);
										//font(28, 28);
										/*for (int i = 0; i < 6; i++)
										{
											cout << endl;
										}*/
										instruction();
										cout << endl;
										cout << setw(90);
										SetConsoleTextAttribute(color, 6);
										cout << "LEFT SWAP ARE  " << swap << endl;
										cout << setw(90);
										cout << "SCORE IS  " << score;
										break;

									}


									if (key == 4)
									{

										swapgems(grid, i, j, i + 1, j);

										sameswap3(grid);
										swap4(grid);
										gridshape(grid, x1, y1);

										gridgen(x1, y1);
										SetConsoleTextAttribute(color, 6);
										//font(28, 28);
										/*for (int i = 0; i < 6; i++)
										{
											cout << endl;
										}*/
										instruction();
										cout << endl;
										SetConsoleTextAttribute(color, 6);
										cout << setw(90);
										cout << "LEFT SWAP ARE   " << swap << endl;
										cout << setw(90);
										cout << "SCORE IS  " << score;
										//printtable(x1, y1);
										//5printboard(grid, x1, y1);
										break;

									}



								}

							}



						}
					}



				}

			}












		}








	}







	system("pause");


}
