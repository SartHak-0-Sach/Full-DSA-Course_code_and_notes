#include <iostream>
using namespace std;

// Homework questions
// Question-1

void FirstQuestion()
{
    int a, b = 1;
    a = 10;
    if (++a)
        cout << b << "\n";

    else
        cout << ++b << "\n"; // Output= 1
}

void SecondQuestion()
{
    int a = 1;
    int b = 2;

    if (a-- > 0 && ++b > 2)
        cout << "Stage1 - Inside If "
             << "\n";

    else
        cout << "Stage2 - Inside else " // If the if condition was not satisfied, will a and b still change?
             << "\n";                   // The answer to above question is- Yes they will due to higher operator precendence of increment and decrement operators

    cout << a << " " << b << endl; // Output= Stage1 - Inside If 0 3
}

void ThirdQuestion()
{
    int a = 1;
    int b = 2;

    if (a-- > 0 || ++b > 2)
        cout << "Stage1 - Inside If " // Understand more such exceptions, like here ++b command didn't even get executed as a-- condition was true
             << "\n";

    else
        cout << "Stage2 - Inside else "
             << "\n";

    cout << a << " " << b << endl; // Output= Stage1 - Inside If 0 2
}

void FourthQuestion()
{
    int number = 3;
    cout << (25 * (++number)) << "\n"; // output= 100
}

void FifthQuestion()
{
    int a = 1;
    int b = a++;
    int c = ++a;
    cout << b << "\n";
    cout << c << "\n"; // Output= 1 3
}

int main(int argc, char const *argv[])
{
    FirstQuestion();
    SecondQuestion();
    ThirdQuestion();
    FourthQuestion();
    FifthQuestion();
    return 0;
}