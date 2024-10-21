#include<iostream>
#include<queue>
#include<string>

using namespace std;

//Queues
queue<string> Admin;
queue<string> Faculty;
queue<string> Student;
queue<string> Meraged_queue;

void display() {
	while (!Meraged_queue.empty())
	{
		cout << Meraged_queue.front() << endl;
		Meraged_queue.pop();
	}
}
void meraging()
{
	while (!Admin.empty())
	{
		Meraged_queue.push(Admin.front());
		Admin.pop();
	}
	while (!Faculty.empty())
	{
		Meraged_queue.push(Faculty.front());
		Faculty.pop();
	}
	while (!Student.empty())
	{
		Meraged_queue.push(Student.front());
		Student.pop();
	}
}

void Insert(char role, string name) {
	if (role == 'A')
	{
		Admin.push(name);
	}
	else if (role == 'F')
	{
		Faculty.push(name);
	}
	else
	{
		Student.push(name);
	}
}

char getRole()
{
	do
	{
	char role;
	cout << " Admin(A) \n Faculty(F) \n Student(S) " << endl;
	cout << "Enter Role:";
	cin >> role;
	if (role == 'A' || role == 'F' || role == 'S')
	{
		
		return role;
		break;
	}
	else {
		system("cls");
		cout << "Invalid Role , Please Enter role according to Mentioned above." << endl;
	}
	
	} while (true);
}
string inputUserName() {
	string Username;
	cout << "Enter Username: ";
	cin >> Username;
	return Username;
}
int main()
{
	
	//variables
	string Name;
	char Role;
	//-------------------------------------------------
	do
	{
		system("cls");
	cout << " ------- Menu -------- " << endl; 
		char option;
		cout << "1.Insert." << endl;
		cout << "2.Display all." << endl;
		cout << "0.Exit." << endl;
		cout << "Your Answer: ";
		cin >> option;
		if (option == '1')
		{
		system("cls");
	     Name = inputUserName();
		 Role = getRole();
		 Insert(Role ,Name);
		 cout << "Inserted!" << endl;
		 system("pause");
		}
		else if (option == '2')
		{
			system("cls");
			meraging();
			display();
			system("pause");
		}
		else if (option == '0') {
			exit(1);
		}
	} while (true);

}
