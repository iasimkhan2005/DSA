#include<iostream>
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


	void readFromUser() {
	
		
			cout << "Enter the House Owner NAME: ";

			cout << "Enter the House Address: ";
			cout << "Enter the House BedRooms no.: ";
			cout << "Enter the House Price: ";

	}
};





void main() {
	House available[100];
	int houseNo = 0;
	cout << " ------ Welcome to Society Management System -------- ";
	
	char choice;
	do
	{
		if (houseNo <= 100)
		{
			available[houseNo].readFromUser();
			houseNo++;
			cout << "Want to enter more data(y/n)";
			cin >> choice;

		}
		else
		{
			choice == false;
			cout << "100 house data COMPLETED!!";
		}
		
	} while (choice == 'y');


	
}