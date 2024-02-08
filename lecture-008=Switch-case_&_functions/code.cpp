#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int countBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
            count++;

        n >> 1;
    }
    return count;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0;
    int b = 1;
    int count = 2;
    int ans;
    while (count != n)
    {
        int c = a + b;
        a = b;
        b = c;
        count++;
        ans = c;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // int n, r;
    // cin >> n >> r;
    // cout << nCr(n, r) << "\n";
    // int m;
    // cin >> m;
    // cout << fibonacci(m) << endl;
    int a, b;
    cin >> a >> b;
    char op;
    int result = 0;
    while (true)
    {
        cin >> op;
        cout << "Press q to quit" << endl;
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