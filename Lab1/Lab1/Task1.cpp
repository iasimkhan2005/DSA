#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
class House
{
private:
	char Owner[20];
	char Address[20];
	char city[20];
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
		
		cout << "Enter the City: ";
		cin.getline(city, 20);

		cout << "Enter the House BedRooms no.: ";
		cin >> bedrooms;
		
		cout << "Enter the House Price: ";
		cin >> Price;

		cin.ignore();
	}

	void OutputData() {
		cout << Owner << "\t" << Address << "\t" << bedrooms << "\t    " << Price << endl;
	}
	string getcity() {
		return city;
	}
	int getbedrooms(){
		return bedrooms;
	}
	float getPrice() {
		return Price;
	}
	
};


//Global Variables
	House available[100];
	int houseNo = 0;
	int choice;
	bool check = false;

	void Add() {

		available[houseNo].InputFromUser(); //Taking Input From user through InputFromUser().
		houseNo++; //Whenever the house Added, the houseNo var will be incremented by +1
		check = true; //"check" var will be become true when house added otherwise it will be false. 

	}
	void Output() {
		if (check)
		{
			cout << "-----------------------------------" << endl;
			cout << "Owner\tAddress\tBedRooms\tPrice\n";
			for (int i = 0; i < houseNo; i++)
			{
				available[i].OutputData(); //printing output through OutputData().

			}
		}
		else
		{
			cout << "No House data Stored yet??" << endl; //if no house is addded then this message will be  shown.
		}
	}
	void query() {

		do
		{
			int optionMENU;
			cout << "1. Find houses within your budget" << endl;
			cout << "2. Find Houses with number of bedrooms query" << endl;
			cout << "3. Find most affordable (Lowest) house" << endl;
			cout << "4. Find the largest home with the most bedrooms" << endl;
			cout << "5. Search for properties in a specific city" << endl;
			cout << "6. Get the best value for price per size" << endl;
			cout << "0. Exit" << endl;

			cout << "Enter your choice: ";
			cin >> optionMENU;
			float priceinput;
			int bedrooms;

			if (optionMENU == 1) {
				cout << "Enter your budget: ";
				cin >> priceinput;
				cout << "-----------------------------------" << endl;
				cout << "Owner\tAddress\tBedRooms\tPrice\n";
				for (int i = 0; available[i].getPrice() <= priceinput; i++)
				{
					available[i].OutputData();

				}


			}
			else if (optionMENU == 2) {
				cout << "Enter number of bedrooms: ";
				cin >> bedrooms;

				cout << "-----------------------------------" << endl;
				cout << "Owner\tAddress\tBedRooms\tPrice\n";
				for (int i = 0; available[i].getbedrooms() >= bedrooms; i++)
				{
					available[i].OutputData();

				}
			}
			else if (optionMENU == 3) {
				cout << "The most affordable (Lowest) house is: " << endl;
				House lowest = available[0];
				for (int i = 1; i < houseNo; i=i+1)
				{
					if (available[i].getPrice() < lowest.getPrice())
					{
						lowest = available[i];
					}
				}
				cout << "-----------------------------------" << endl;
				cout << "Owner\tAddress\tBedRooms\tPrice\n";
				lowest.OutputData();
			}
			else if (optionMENU == 4) {
				cout << "The largest house with the most bedrooms is: " << endl;
				House largestHouse = available[0];
				for (int i = 1; i < houseNo; i = i + 1)
				{
					if (available[i].getbedrooms() > largestHouse.getbedrooms())
					{
						largestHouse = available[i];
					}
				}
				cout << "-----------------------------------" << endl;
				cout << "Owner\tAddress\tBedRooms\tPrice\n";
				largestHouse.OutputData();
				
			}
			else if (optionMENU == 5) {
				char SearchCity[20];
				cin.ignore();
				cout << "Enter city: ";
				cin.getline(SearchCity, 20);
				cout << "-----------------------------------" << endl;
				cout << "Owner\tAddress\tBedRooms\tPrice\n";
				for (int i = 0; i < houseNo; i++)
				{
					if (SearchCity == available[i].getcity()) {
						available[i].OutputData();
					}
				}
			}
			else if (optionMENU == 6) {
				cout << "You chose to get the best value for price per size." << endl;
				// Add your code to get the best value for price per size
			}
			else if (optionMENU == 0) {
				break;
			}
			else {
				cout << "Invalid choice. Please enter a number between 1 and 6.And for EXIT enter 0" << endl;
			}

		} while (true);
	}

void main() {
	do
	{
		//Main Menu
	    cout << " ------ Welcome to Society Management System -------- " << endl;

		cout << "---------------------------------------------------------" << endl;
		cout << "1. Add a House details." << endl;
		cout << "2. Display All Houses details." << endl;
		cout << "3.Check Houses details Through queries." << endl;
		cout << "0.Exit!!" << endl;
		cout << "______________________________________\n Your Answer: ";


		cin >> choice;

		//Conditions On the bases of choices....
		if (choice == 1)
		{
		    //Addition of house.
			Add();
			system("cls");
		}
		else if (choice == 2)
		{
			//For output the details of Houses.
			Output();
		
		}
		else if (choice == 3)
		{
			//For different Queries or Filters
			system("cls");
			query();
		}

		else if (choice == 0)
		{
			//For Exting Program
			break;
		}
		else
		{
			//For Handling Invalid Entered choices!!
			cout << "Invalid Choice!!" << endl;
		}
	} while (true);
}