#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
class House
{
private:
	char Owner[20];
	char Address[20];
	int bedrooms;
	float Price;

public:
	House() {};


	void InputFromUser() {
		cout << "Enter the House Owner NAME: ";
		cin.ignore();
		cin.getline(Owner, 20);
		

		cout << "Enter the House Address: ";
		cin.getline(Address, 20);

		cout << "Enter the House BedRooms no.: ";
		cin >> bedrooms;
		
		cout << "Enter the House Price: ";
		cin >> Price;

		cin.ignore();
	}

	void OutputData() {
		cout << Owner << "\t" << Address << "\t" << bedrooms << "\t" << Price << endl;
	}

	int PriceCheck() {

	}
};





void main() {
	//Variables
	House available[100];
	int houseNo = 0;
	int choice;
	bool check = false;
	//Menu


	do
	{
	cout << " ------ Welcome to Society Management System -------- " << endl;

		cout << "---------------------------------------------------------" << endl;
		cout << "1. Add a House details." << endl;
		cout << "2. Display All Houses details." << endl;
		cout << "3.Check Houses details Through queries.";
		cout << "0.Exit!!" << endl;
		cout << "______________________________________\n Your Answer: ";
		cin >> choice;
		if (choice == 1)
		{
			available[houseNo].InputFromUser();
			houseNo++;
			check = true;
			system("cls");
		}
		else if (choice == 2)
		{
			if (check)
			{
			cout << "-----------------------------------" << endl;
			cout << "Owner\tAddress\tBedRooms\tPrice\n";
			  for (int i = 0; i < houseNo; i++)
			  {
				available[i].OutputData();

			  }
			}
			else
			{
				cout << "No House data Stored yet??" << endl;
			}
		
		}
		else if (choice == 3)
		{

			do
			{
				cout << "1. Find houses within your budget" << endl;
				cout << "2. Discover homes with your preferred number of bedrooms" << endl;
				cout << "3. Locate the most affordable (Lowest) house" << endl;
				cout << "4. Find the largest home with the most bedrooms" << endl;
				cout << "5. Search for properties in a specific city" << endl;
				cout << "6. Get the best value for price per size" << endl;
				cout << "7. Exit" << endl;


			} while (true);
		}

		else if (choice == 0)
		{
			break;
		}
		else
		{
			cout << "Invalid Choice!!" << endl;
		}

	

	} while (true);
}