#include<iostream>

using namespace std;

//Stack Implementation
class stack{
private:
			char* arr;
			int top;
			int size;
public:
	        stack(int n){
				top = -1;
				size = n;
				arr = new char[size];
			}
			
			void push(char x){
				if(top == size - 1){
					cout<<"Stack is full"<<endl;
				}
				else{
					arr[++top] = x;
				}
			}
			char pop(){
				if(top == -1){
					cout<<"Stack is empty"<<endl;
				}
				else{
					char ch;
					ch = arr[top];
					top--;
					return ch;
				}
			}
			int Top(){
				return arr[top];
			}
			bool Isempty() {
				if (top == -1) {
					return true;
				}
				else {
					return false;
				}
			}
			bool Isfull()
			{
				if (top == size-1) {
					return true;
				}
				else {
					return false;
				}
		
			}

			void display() {
				for (int i = 0; i <= top; i++) {
					cout << arr[i] << endl;
				}
			}
};     

//Input Function
string input() {
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	
	return str;
}

//Compare Function
void compare(string Str,string Str1){

	if (Str == Str1) {
		cout << "The string is palindrome" << endl;
	}
	else {
		cout << "The string is not palindrome" << endl;
	}
}


int main()
{
	string letter = input(); 
	int strlen = letter.length(); 
	stack Str (strlen), Str1(strlen);
	string Reverse; 

	letter.erase(remove_if(letter.begin(), letter.end(), isspace), letter.end());  //Removing the spaces from the string	

	//Pushing the Given string into the 1st stack
	for (int i = 0; i < strlen; i++) {

		Str.push(letter[i]);
	}

	//Popping the Characters of string from 1st stack and pushing it into 2nd stack
	for (int i = 0; i < strlen; i++)
	{
		char ch;
		ch = Str.pop();
		Str1.push(ch);
		if (ch != '\0') {
			Reverse += ch;
		}
	}
	
	compare(letter,Reverse);

}