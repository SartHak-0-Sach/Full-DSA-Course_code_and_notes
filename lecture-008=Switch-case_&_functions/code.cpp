#include <iostream>
using namespace std;
// class Calculator{
//     public:
//     Calculator(string str)
//     {
//         cout << "Constructor called with : " + str << endl;  // Calling the constructor
//     }

// };

// int main(int argc, char const *argv[])
// {
//     string expression = "3+4*5";
//     // Create an object of the class and pass the expression as a parameter to it.
//     Calculator calcObj("3+4*5");

//     return 0;
// }

// Question-1 make calculator class in c++ that takes string expression and returns solution and works infinitely until break


int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    char op;
    int result = 0;
    while (true)
    {
        cin >> op;
        cout << "Press q to quit" << endl; // Question-2 make a menu driven program for calculator
        switch (op)
        {
        case '+':
            result += a + b;
            break;

        case '-':
            result += a - b;
            break;

        case '*':
            result += a * b;
            break;

        case '/':
            result += a / b;
            break;

        case '%':
            result += a % b;
            break;

        case 'q':
            cout << result << endl;
            exit(0);

        default:
            cout << "ERROR: Invalid operator. Please try again" << endl;
        }
    }
    return 0;
}

// Question-3 coin problem using switch-case