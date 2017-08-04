#include <iostream>
#include <string>
using namespace std;
void EC(bool seat[10]);
void FC(bool seat[10]);
void SEE(bool seat[10]);
int main()
{
	bool seat[10];
	int choice = 0;

	for (int i = 0; i < 10; i++)
	{
		seat[i] = false;
	}
	cout << endl
		<< "      Airline reservation system" << endl
		<< "      ==========================" << endl
		<< "  welcome to s airlines. press 1 to get FC seat, pres 2 to get an EC seat, press 3 to see the statues of reservations!" << endl;
	do
	{
		cout << endl
			<< "<1> FC" << endl
			<< "<2> EC" << endl
			<< "<3> SEE" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			FC(seat);
			break;
		case 2:
			EC(seat);
			break;
		case 3:
			SEE(seat);
			break;
		default:
			cout << "invalid input!" << endl;
			break;
		}

	} while (!(seat[4]&&seat[9]));
}
void FC(bool seat[10])
{
	char choice = 'y';
	static int target = 0;
	if (target < 5)
	{
		seat[target++] = true;
		cout<<"your seat number is "<<target<<" in FC"<<endl;
		return;
	}
	else if (seat[9])
	{
		cout << endl << "the plane is full, next flight leaves in 3 hours!";
		return;
	}
	else
	{
		cout << "FC is full, can we change it to EC? <y/n>" << endl;
		cin >> choice;
		
		if (choice=='y')
		{
			EC(seat);
			return;
		}
		else
		{
			return;
		}
	}
}
void EC(bool seat[10])
{


	char choice = 'y';
	static int target = 5;
	if (target < 10)
	{
		seat[target++] = true;
		cout << "your seat number is " << target << " in EC" << endl;
		return;
	}
	else if (seat[4])
	{
		cout << endl << "the plane is full, next flight leaves in 3 hours!";
		return;
	}
	else
	{
		cout << "EC is full, can we change it to FC? <yes,no>" << endl;
		cin >> choice;

		if (choice == 'y')
		{
			FC(seat);
			return;
		}
		else
		{
			return;
		}
	}

}

void SEE(bool seat[10])
{
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "seat " << i + 1 << " FC: ";
		if (seat[i])
		{
			cout << "RESERVED \n";
		}
		else
		{
			cout << "unRESERVED \n";
		}
	}
	for (unsigned int i = 5; i < 10; i++)
	{
		cout << "seat " << i + 1 << " EC: ";
		if (seat[i])
		{
			cout << "RESERVED \n";
		}
		else
		{
			cout << "unRESERVED \n";
		}
	}
}