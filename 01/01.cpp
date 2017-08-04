#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
char winOrNot(char location[3][3]);
void print(char location[3][3]);
bool gameEnd(char location[][3]);
int main()
{
	char location[3][3];
	char charWinOrNot;
	int target;
	bool uBegin = 0;

	//init location
	for (unsigned int i = 0; i < 3; i++)
	{
		
		for (unsigned j = 0; j < 3; j++)
		{
			location[i][j] = i * 3 + j + 1 + 48;//according to ascII
		}
	}

	srand(time(NULL));
	uBegin = rand() % 2;



	do
	{
		print(location);
		if (uBegin)
		{
			//user pick

			while (true)
			{
				cout << endl << "plz pick!";
				cin >> target;
				target--;
				if (location[target / 3][target % 3] != 'o'&&location[target / 3][target % 3] != 'x')
				{
					break;
				}
				else
				{
					cout << endl << "wrong one!";
				}
			}

			
			location[target / 3][target % 3] = 'x';	//that is the trick :p
			uBegin = !uBegin;	//thats another trick :pp

		}
		if (!uBegin)
		{
			//comp pick
			while (true)
			{
				target = rand() % 9;
				if (location[target / 3][target % 3] != 'o'&&location[target / 3][target % 3] != 'x')
				{
					break;
				}
			}
			
			location[target / 3][target % 3] = 'o';	//that is the trick :p
			uBegin = !uBegin;	//thats another trick :pp
		}
		charWinOrNot = winOrNot(location);
		if (charWinOrNot == 'o')
		{
			cout << endl << "comp win!";
			print(location);
			return 0;
		}
		else if (charWinOrNot=='x')
		{
			cout << endl << "user win!";
			print(location);
			return 0;
		}
		

	} while (!gameEnd(location));
	
	cout << "nobody wins!" << endl;
	return 0;

}

void print(char location[3][3])
{
	cout << endl << endl;
	for (unsigned int i = 0; i < 3; i++)
	{

		for (unsigned j = 0; j < 3; j++)
		{
			cout << " " << location[i][j];
			if (j != 2)
			{
				cout << " |";
			}
		}
		cout << endl;
		if (i!=2)
		{
			for (unsigned int temp = 0; temp < 11; temp++)
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}
char winOrNot(char location[3][3])
{
	//NULL means nobody wins, x means user win, o means com win.
	
	//row check
	for (unsigned int i = 0; i < 3; i++)
	{
		if (location[i][0] == location[i][1] && location[i][0] == location[i][2])
		{
			return location[i][0];
		}
	}
	//column check
	for (unsigned int i = 0; i < 3; i++)
	{
		if (location[0][i] == location[1][i] && location[0][i] == location[2][i])
		{
			return location[0][i];
		}
	}
	//cross check
	if ((location[0][0]==location[1][1]&&location[1][1]==location[2][2])||(location[1][1]==location[0][2]&&location[1][1]==location[2][0]))
	{
		return location[1][1];
	}
	
	return NULL;

}

bool gameEnd(char location[][3])
{
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (location[i][j] != 'o'&&location[i][j] != 'x')
			{
				return false;
			}
		}
	}
	return true;
}