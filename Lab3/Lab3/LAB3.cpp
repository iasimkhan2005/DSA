#include<iostream>
#include<stack>
#include<algorithm>
#include<map>

using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}
bool isOperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
    {
        return true;
    }
    return false;
}
bool isValidExpression(string Exp) {
    stack<char> brackets;
    int operands = 0;
      int   operators = 0;

    for (int i = 0; i < Exp.length(); i++) {
        char current = Exp[i];

        // Check for valid characters (operators, brackets, and operands)
        if (!isalnum(current) && current != '(' && current != ')' && !isOperator(current)) {
            cout << "Invalid character in expression: " << current << endl;
            return false;
        }

        // Check for balanced brackets
        if (current == '(') {
            brackets.push(current);
        }
        else if (current == ')') {
            if (brackets.empty()) {
                cout << "Unbalanced brackets!" << endl;
                return false;
            }
            brackets.pop();
        }

        // Count operands and operators
        if (isalnum(current)) {
            operands++;
        }
        else if (isOperator(current)) {
            operators++;
            if (i == 0 || i == Exp.length() - 1) {
                cout << "Expression cannot start or end with an operator??" << endl;
                return false;
            }
            // Check for consecutive operators
            if (i > 0 && isOperator(Exp[i - 1])) {
                cout << "Consecutive operators are not allowed!" << endl;
                return false;
            }
        }
    }

    // Check if all brackets were closed
    if (!brackets.empty()) {
        cout << "Unbalanced brackets!" << endl;
        return false;
    }

    // Ensure that the number of operators is valid relative to operands
    if (operators >= operands) {
        cout << "Invalid operator-to-operand ratio!" << endl;
        return false;
    }

    return true;
}
void EvaluatePostfix(string Postfix,map<char,int> Values) {
    stack<double> s;

    for (char ch : Postfix) {
        if (isalpha(ch)) {  // Operand is a variable
            s.push(Values[ch]);
        }
        else if (isdigit(ch)) {  // Operand is a direct digit
            s.push(ch - '0');
        }
        else {  // Operator
            double operand2 = s.top(); s.pop();
            double operand1 = s.top(); s.pop();
            switch (ch) {
            case '+': s.push(operand1 + operand2); break;
            case '-': s.push(operand1 - operand2); break;
            case '*': s.push(operand1 * operand2); break;
            case '/': s.push(operand1 / operand2); break;
            case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    cout<<"Result of Postfix Evaluation: "<< s.top() <<endl;  // Final result
}
void infixTOpostfix(string Exp1) {
    string Exp = Exp1;
    string postfixEXP = "";
    char EvaluatePostfixOption;
    map<char, int> OperandValue;
    Exp.erase(remove(Exp.begin(), Exp.end(), ' '), Exp.end());

    stack<char> process;

    for (int i = 0; i < Exp.length(); i++) {

        char current = Exp[i];

        if (isalnum(current)) {
            postfixEXP += current;
        }

        else if (current == '(') {
            process.push(current);
        }

        else if (current == ')') {
            while (!process.empty() && process.top() != '(') {
                postfixEXP += process.top();
                process.pop();
            }
            process.pop();
        }

        else if (isOperator(current)) {
            while (!process.empty() && precedence(process.top()) >= precedence(current)) {
                postfixEXP += process.top();
                process.pop();
            }
            process.push(current);
        }
        else
            cout << "Invalid Expression!!!, Please coorect Expression" << endl;
    }


    while (!process.empty()) {
        postfixEXP += process.top();
        process.pop();
    }

    cout << "Postfix Expression: " << postfixEXP << endl;

    cout << "If you want to Evaluate this Postfix then Enter \"Y\":";
    cin >> EvaluatePostfixOption;
    if (EvaluatePostfixOption == 'Y' || EvaluatePostfixOption == 'y') {
        for (char ch : postfixEXP)
        {
            if (!isdigit(ch))
            {
                if (isalnum(ch) && OperandValue.find(ch) == OperandValue.end()) {
                    cout << "Enter the Value of " << ch << ": ";
                    cin >> OperandValue[ch];
                }
            }
        }
        EvaluatePostfix(postfixEXP,OperandValue);
    }

}
void infixTOprefix(string Exp1)
{
    string Exp = Exp1;
    Exp.erase(remove(Exp.begin(), Exp.end(), ' '), Exp.end());
    int ExpLength = Exp.length();
    string Reversed_Exp;
    for (int i = ExpLength - 1; i >= 0; i--)
    {
        if (Exp[i] == '(') {
            Reversed_Exp += ')';
        }
        else if (Exp[i] == ')') {
            Reversed_Exp += '(';
        }
        else
            Reversed_Exp += Exp[i];
    }
         
        string postfixEXP = "";
        stack<char> process;
          for (int i = 0; i < Reversed_Exp.length(); i++)
        {

            char current = Reversed_Exp[i];

            if (isalnum(current)) {
                postfixEXP += current;
            }

            else if (current == '(') {
                process.push(current);
            }

            else if (current == ')') {
                while (!process.empty() && process.top() != '(') {
                    postfixEXP += process.top();
                    process.pop();
                }
                process.pop();
            }

            else if (isOperator(current)) {
                while (!process.empty() && precedence(process.top()) >= precedence(current)) {
                    postfixEXP += process.top();
                    process.pop();
                }
                process.push(current);
            }
            else
                cout << "Invalid Expression!!!, Please coorect Expression" << endl;
        }
        while (!process.empty()) {
            postfixEXP += process.top();
            process.pop();
        }
       // cout << "postfix Exp: " << postfixEXP;

        int postfixLength = postfixEXP.length();
        string prefix;
        for (int i = postfixLength - 1; i >= 0; i--)
        {
            if (postfixEXP[i] == '(') {
                prefix += ')';
            }
            else if (postfixEXP[i] == ')') {
                prefix += '(';
            }
            else
                prefix += postfixEXP[i];
        }
        cout << "\nPrefix Exp: " << prefix <<endl;
    
}
int Power(int base , int exponent)
{
    if (exponent == 0) {
        return 1;
    }

    stack<int> s;
    int result = 1;

    
    for (int i = 0; i < exponent; i++) {
        s.push(base);
    }

    while (!s.empty()) {
        result *= s.top();
        s.pop();
    }

    return result;
  
}
int Multiply(int Num ,int times ) {
    stack<int> s;
    int result = 0;
    if (Num == 0)
    {
        return 0;
    }
    
    

    for (int i = 0; i < times; i++)
    {
        s.push(Num);
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
       
    }
    
    return result;

}
string input() {
    string Exp; char choice;
    int Num;
    do
    {
        system("cls");
        int option = NULL;
        cout << "------- MENU -----------" << endl;
        cout << "1.Infix to Postfix" << endl;
        cout << "2.Postfix Validation" << endl;
        cout << "3.Infix to Prefix" << endl;
        cout << "4.Power Implementation" << endl;
        cout << "5.Multiplication" << endl;
        cout << "0.EXIT" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
        {
            system("cls");
            cout << "---- Infix to Postfix ---- \n" << "Enter the expression: ";
            cin >> Exp;
            //checking for expression Validation
            if (isValidExpression(Exp)) {
                infixTOpostfix(Exp);
            }
            else {
                cout << "Invalid expression. Please correct the expression and try again." << endl;
            }
            break;
        }
        case 2:
        {
            map<char, int> OperandValue;
            system("cls");
            cout << "---- Postfix Evaluation ---- \n" << "Enter the expression: ";
            cin >> Exp;
            for (char ch : Exp )
            {
                if (!isdigit(ch))
                 {
                  if (isalnum(ch) && OperandValue.find(ch) == OperandValue.end()) {
                    cout << "Enter the Value of " << ch << ": ";
                    cin >> OperandValue[ch];
                  }
                }
            }
            EvaluatePostfix(Exp,OperandValue);
            break;
        }
        case 3:
        {

            system("cls");
            cout << "---- Infix to Prefix ---- \n" << "Enter the expression: ";
            cin >> Exp;
            //checking for expression Validation
            if (isValidExpression(Exp)) {
                infixTOprefix(Exp);
            }
            else {
                cout << "Invalid expression. Please correct the expression and try again." << endl;
            }
            break;
        }
        case 4:
        {
            system("cls");
            cout << "---- Power Implementation ----" << endl;
            int times;
            cout << "Enter the Number/Base: ";
            cin >> Num;
            cout << "Enter Exponent: ";
            cin >> times;
            int result = Power(Num, times);
            cout << "Answer: " << result << endl;
            break;
        }
        case 5:
        {
            system("cls");
            int times;
            cout << "Enter the Number: ";
            cin >> Num;
            cout << "Enter the times: ";
            cin >> times; 
           int result = Multiply(Num,times);
           cout << "Answer: " << result << endl;
            break;
        }
        case 0:
        {
            exit(1);
        }
        default:
            break;
        }
        cout << "Want to go Back to Menu(Y/N):";
        cin >> choice;
    } while (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N');
}
int main() {
    input();

    return 0;
}
