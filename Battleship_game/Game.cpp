#include <iostream>
#include "Game.h"
using namespace std;

int battle_ground[10][10];
char display_ground[10][10];
int ship_size = 5;
int destroyer_size = 2;


void test()
{
	cout << endl << "testing" << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << battle_ground[i][j] << " ";
		}
		cout << endl;
	}

}
int main()
{
	bool game_over = false;
	int row_input;
	int col_input;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			battle_ground[i][j] = 0;
			display_ground[i][j] = 'X';
		}
	}
	srand((unsigned)time(0));
	ship_generator();
	while (game_over == false)
	{
		cout << "enter row" << endl;
		cin >> row_input;
		cout << endl << "enter col" << endl;
		cin >> col_input;
		cout << endl;
		display_field(&row_input, &col_input);
	}
	
	
	return 0;
}

void ship_generator()
{
	
	int s_row = rand() % 6;
	int s_col = rand() % 6 ;
	int choice = rand() % 2;// randomly choose to place row wise or coloumn wise;
	if (choice == 0)
	{
		for (int i = 0; i < ship_size; i++)
		{
			battle_ground[s_row][s_col] = 1;
			s_col++;

		}
		
	}

	else
	{
		for (int i = 0; i < ship_size; i++)
		{
			battle_ground[s_row][s_col] = 1;
			s_row++;
		}
	}
	for (int count = 0; count < 4; count++)
	{
		des_gen();
	}
	test();
	
}

void des_gen()
{
	
	int flag = 0;
	int s_row = rand() % 8;
	int s_col = rand() % 8;
	int choice = rand() % 2;// randomly choose to place row wise or coloumn wise;
	
	
	if (choice == 0)
	{
		for (int i = 0; i < destroyer_size; i++)
		{
			for (int j = 0; j < destroyer_size; j++)
			{
				if (battle_ground[s_row][s_col] != 0)
				{
					flag = 1;
				}
				s_col++;
			}
			s_row++;
		}
		
		if (flag == 0)
		{
			for (int i = 0; i < destroyer_size; i++)
			{
				battle_ground[s_row][s_col] = 2;
				s_col++;

			}
			
		}
		else 
		{
			des_gen();
		}

	}
	else
	{
		for (int i = 0; i < destroyer_size; i++)
		{
			for (int j = 0; j < destroyer_size; j++)
			{
				if (battle_ground[s_row][s_col] != 0)
				{
					flag = 1;
				}
				s_row++;
			}
			s_col++;
		}
		
		if (flag == 0)
		{
			for (int i = 0; i < destroyer_size; i++)
			{
				battle_ground[s_row][s_col] = 2;
				s_row++;

			}
			
		}
		else
		{
			des_gen();
		}
	}

}

void display_field(int* row_input, int* col_input)
{
	if (battle_ground[*row_input][*col_input] == 1)
	{
		display_ground[*row_input][*col_input] = 'S';
	}
	else if (battle_ground[*row_input][*col_input] == 2)
	{
		display_ground[*row_input][*col_input] = 'D';
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			cout << display_ground[i][j] <<" ";
		}
		cout << endl;
	}

}
