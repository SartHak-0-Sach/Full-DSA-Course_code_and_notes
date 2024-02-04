#include <iostream>
using namespace std;
// Homework questions
// Question-1

void FirstQuestion()
{
    int count = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

// Question-2
void SecondQuestion()
{
    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << col + row - 1 << " ";
            col++;
        }
        cout << "\n";
        row++;
    }
}

// Question-3
void ThirdQuestion()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << "\n";
    }
}

// Question-4
void FourthQuestion()
{
    int n;
    cin >> n;
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

// Question-5
void FifthQuestion()
{
    int n;
    cin >> n;
    char ch = 'A' + n;
    int row = 0;
    while (++row <= n)
    {
        char temp = ch - row;
        int col = 0;
        while (++col <= row)
        {
            cout << temp << " ";
            temp++;
        }
        cout << "\n";
    }
}

// Question-6
void SixthQuestion()
{
    int n;
    cin >> n;
    int row = 0;
    while (++row <= n)
    {
        int col = n + 1;

        while (--col >= row)
            cout << "* ";

        cout << "\n";
    }
}

// Question-7
void SeventhQuestion()
{
    int n;
    cin >> n;
    int row = 0;
    while (++row <= n)
    {
        int col = n + 1;

        int temp = 0;

        while (++temp != row)
            cout << "  ";

        while (--col >= row)
            cout << "* ";

        cout << "\n";
    }
}

// Question-8
void EighthQuestion()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp = 1;
        while (temp++ < i)
            cout << "  ";

        int temp2 = i;
        for (int j = i; j <= n; j++)
        {
            cout << temp2 << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = n;
        while (temp-- > i)
            cout << "  ";

        int temp2 = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp2 << " ";
        }
        cout << "\n";
    }
}

// Question-9
void NinthQuestion()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << " ";
        }

        for (int k = 0; k < 2 * i; k++)
        {
            cout << "*"
                 << " ";
        }

        for (int l = 0; l < n - i; l++)
        {
            cout << n - l - i << " ";
        }
        cout << "\n";
    }
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
    return 0;
}