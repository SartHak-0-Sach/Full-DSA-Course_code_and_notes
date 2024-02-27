#include <iostream>
#include <vector>
using namespace std;

void countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            count++;
        }
    }
    cout << count << endl;
}

void countPrimes2(int n)
{
    int count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            count++;

        for (int j = 2 * i; j < count; j = j + i)
            prime[j] = 0;
    }
    cout << count << endl;
}

