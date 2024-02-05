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

void SixthQuestion()
{
    for (int i = 0; i <= 5; i++)
    {
        cout << i << " ";
        i++;
    }
    // Output= 0 2 4
}

void SeventhQuestion()
{
    for (int i = 0; i <= 5; i--)
    {
        cout << i << " ";
        i++;
    }
    // Output= {infinite loop}
}

void EighthQuestion()
{
    for (int i = 0; i <= 15; i += 2)
    {
        cout << i << " ";
        if (i & 1)
            continue;

        i++;
    }
    // Output= 0 3 5 7 9 11 13 15
}

void NinthQuestion()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            cout << i << " " << j << endl;
        }
    }
    // Output= 0 0 0 1 0 2 0 3 0 4 0 5 1 1 1 2 1 3 1 4 1 5 2 2 2 3 2 4 2 5 3 3 3 4 3 5 4 4 4 5
}

void TenthQuestion()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if (i + j == 10)
                break;

            cout << i << " " << j << endl;
        }
    }
    // Output= 0 0 0 1 0 2 0 3 0 4 0 5 1 1 1 2 1 3 1 4 1 5 2 2 2 3 2 4 2 5 3 3 3 4 3 5 4 4 4 5
}

int subtractProductAndSum(int n)
{
    int product = 1;
    int sum = 0;
    while(n>0)
    {
        int digit = n % 10;
        product *= digit;
        sum += digit;
        n /= 10;
    }
    return product-sum;
}

int hammingWeight(uint32_t n)
{
    int setBits = 0;
    while(n>0)
    {
        if(n&1)
        setBits++;

        n>>1;
    }
    return setBits;
}

int main(int argc, char const *argv[])
{
    FirstQuestion();
    SecondQuestion();
    ThirdQuestion();
    FourthQuestion();
    FifthQuestion();
    SixthQuestion();
    SeventhQuestion();
    EighthQuestion();
    NinthQuestion();
    TenthQuestion();
    return 0;
}