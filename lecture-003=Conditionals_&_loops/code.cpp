#include <iostream>
using namespace std;
// Homework questions- solution
// Question-1
void FirstQuestion()
{
    int a = 9;
    if (a == 9)
        cout << "NINEY"
             << "\n";

    if (a > 0)
        cout << "POSITIVE"
             << "\n";

    else
        cout << "NEGATIVE"
             << "\n"; // output= NINEY POSITIVE
}

// Question-2
void SecondQuestion()
{
    int a = 2;
    int b = a + 1;

    if ((a = 3) == b)
        cout << a
             << "\n";

    else
        cout << a + 3
             << "\n"; // output= 3
}

// Question-3
void ThirdQuestion()
{
    int a = 24;

    if (a > 20)
        cout << "Love"
             << "\n";

    else if (a == 24)
        cout << "Lovely"
             << "\n";

    else
        cout << "Not lovely"
             << "\n";

    cout << a
         << "\n"; // output= Love
}

// Question-4
void FourthQuestion(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        cout << "Lowecase\n";

    else if (ch >= 'A' && ch <= 'Z')
        cout << "Uppercase\n";

    else if (ch >= 49 && ch <= 57)
        cout << "Number\n";

    else
        cout << "Enter valid input\n";
}

int main(int argc, char const *argv[])
{
    FirstQuestion();
    SecondQuestion();
    ThirdQuestion();
    FourthQuestion(';');
    return 0;
}