#include <iostream>
using namespace std;

int main() {
    double a,b;
    char op;
    cout <<"--Simple Calculator--\n";
    cout <<"Enter first number: ";
    cin >> a;
    cout <<"choose an operator (+, -, *, /): ";
    cin >> op;
    cout <<"Enter second number: ";
    cin >>b;

    switch (op) {
        case '+':
            cout << "Result: " << a+b << endl;
            break;
        case '-':
            cout << "Result: " << a-b << endl;
            break;
        case '*':
            cout << "Result: " << a*b << endl;
            break;
        case '/':
            if (b!= 0)
                cout << "Result: " << a/b << endl;
            else
                cout << "Error: division not defined" << endl;
            break;
        default:
            cout << "enter valid operator" << endl;
    }
    return 0;
}