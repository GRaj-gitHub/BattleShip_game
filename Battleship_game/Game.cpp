#include <iostream>
#include <iomanip>
#include "Game.h"
using namespace std;

char battle_ground[10][10];
char display_ground[10][10];
int ship_size = 5;
int destroyer_size = 2;
bool game_over = false;

void test()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			cout << battle_ground[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	
	char option;
	int row_input, col_input;
	int count, winvalue;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			battle_ground[i][j] = 'X';
			display_ground[i][j] = 'X';
		}
	}
	cout << setw(65) << "Battle-Ship Game" << endl;
	
	srand((unsigned)time(0));
	for (int i = 0; i < 2; i++)
	{
		ship_generator();
	}
	for (int i = 0; i < 4; i++)
	{
		des_gen();
	}
	
	while (game_over == false)
	{
		cout << "enter row: ";
		cin >> row_input;
		cout << endl << "enter col: ";
		cin >> col_input;
		cout << endl;
		display_field(&row_input, &col_input, &count);
		if (count == 18)
		{
			cout << endl << "YOU WIN !!";
			game_over = true;
			break;
		}
		cout << endl << "press y to conitnue and q to quit ";
		cin >> option;
		switch (option)
		{
		case 'q':	cout << endl << "original battle ground: " << endl;
					test();
					game_over = true;
					break;
		case 'y':	break;
		}
	} 
	
	
	return 0;
}

void ship_generator()
{
	bool flag = false;
	int s_row = rand() % 6;
	int s_col = rand() % 6 ;
	int choice = rand() % 2;// randomly choose to place row wise or coloumn wise;
	if (choice == 0)
	{
		int temp = s_row;
		for (int i = 0; i < ship_size; i++)
		{
			if (battle_ground[temp][s_col] != 'X')
			{
				flag = true;
				break;
			}
			temp++;
		}
		if (!flag)
		{
			for (int i = 0; i < ship_size; i++)
			{
				battle_ground[s_row][s_col] = 'S';
				s_row++;

			}
		}
		else
		{
			ship_generator();
		}
		
		
	}

	else
	{
		int temp = s_col;
		for (int i = 0; i < ship_size; i++)
		{
			if (battle_ground[s_row][temp] != 'X')
			{
				flag = true;
				break;
			}
			temp++;
		}
		if (!flag)
		{
			for (int i = 0; i < ship_size; i++)
			{
				battle_ground[s_row][s_col] = 'S';
				s_col++;
			}
		}
		else
		{
			ship_generator();
		}
		
	}
	
	
	
}

void des_gen()
{
	
	bool flag = false;
	int s_row = rand() % 8;
	int s_col = rand() % 8;
	int choice = rand() % 2;// randomly choose to place row wise or coloumn wise;
	
	
	if (choice == 0)
	{
		int temp = s_row;
		for (int i = 0; i < destroyer_size; i++)
		{
			if (battle_ground[temp][s_col] != 'X')
			{
				flag = true;
				break;
			}
			temp++;
		}
		
		if (!flag)
		{
			for (int i = 0; i < destroyer_size; i++)
			{
				battle_ground[s_row][s_col] = 'D';
				s_row++;

			}
			
		}
		else 
		{
			des_gen();
		}

	}
	else
	{
		int temp = s_col;
		for (int i = 0; i < destroyer_size; i++)
		{
			if (battle_ground[s_row][temp] != 'X')
			{
				flag = true;
				break;
			}
			temp++;
		}
		
		if (!flag)
		{
			for (int i = 0; i < destroyer_size; i++)
			{
				battle_ground[s_row][s_col] = 'D';
				s_col++;

			}
			
		}
		else
		{
			des_gen();
		}
	}

}

int display_field(int* row_input, int* col_input, int* count)
{

	if (battle_ground[*row_input][*col_input] == 'X')
	{
		display_ground[*row_input][*col_input] = 'O';
		
	}
	if (battle_ground[*row_input][*col_input] == 'S')
	{
		display_ground[*row_input][*col_input] = 'S';
		*count++;
	}
	else if (battle_ground[*row_input][*col_input] == 'D')
	{
		display_ground[*row_input][*col_input] = 'D';
		*count++;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			cout << display_ground[i][j] <<"  ";
		}
		cout << endl;
	}
	return *count;
	

}
