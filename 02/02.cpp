#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
void resultPrint(int winner);
int play();
int main()
{
	int winner = 0;
	string choice = "";

	do
	{
		cout << endl << "if you want to exit type \"exit\". otherwise, type \" C \"." << endl;
		getline(cin, choice);
		choice = strupr(&choice[0]);//convert to upper
		if (choice[0]=='E')
		{
			cout << "\n Thanks!" << endl;
			return  0;
		}
		else if (choice[0]=='C')
		{
			resultPrint(play());
		}
	} while (true);
}
int play()
{
	string choice = "";
	int cChoice = 0;//0=rock,1=paper, 2=scissor
	cout << endl << "choose either Rock, Paper, or Scissor: ";
	getline(cin, choice);
	choice = strupr(&choice[0]);//convert to upper
	srand(time(NULL));
	cChoice = rand() % 3;
	switch (cChoice)
	{
	case 0:
		cout << endl << "comp chose rock.\n";
		break;
	case 1:
		cout << endl << "comp chose paper. \n";
		break;
	case 2:
		cout << endl << "comp chose scissor. \n";
		break;
	}
	switch (choice[0])
	{
	case 'R':
		if (cChoice==0)
		{
			return 0;
		}
		if (cChoice==1)
		{
			return -1;
		}
		if (cChoice==2)
		{
			return 1;
		}
		break;
	case 'P':
		if (cChoice==0)
		{
			return 1;
		}
		if (cChoice==1)
		{
			return 0;
		}
		if (cChoice==2)
		{
			return -1;
		}
		break;
	case 'S':
		if (cChoice == 0)
		{
			return -1;
		}
		if (cChoice == 1)
		{
			return 1;
		}
		if (cChoice == 2)
		{
			return 0;
		}
		break;
	}
}


void resultPrint(int winner)
{
	static int comp = 0;
	static int user = 0;
	switch (winner)
	{
	case 0:
		cout << "nobody wins!";
		break;
	case 1:
		//user win
		user++;
		cout << "user wins";
		break;
	case -1:
		//comp win
		comp++;
		cout << "comp wins";
		break;
	default:
		break;
	}
	cout << endl << "result" << endl << "========" 
		<< endl << " comp        user" 
		<< endl << "-----        -----" 
		<< endl << "  " << comp << "            " << user << endl;
}