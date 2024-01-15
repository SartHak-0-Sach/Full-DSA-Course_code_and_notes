#include <iostream>
#include <vector>
using namespace std;

long long threeWaySplit(int n, vector<int> arr)
{
    long long ans = 0;
    long long start = 0;
    long long end = n - 1;
    long long s1 = arr[start];
    long long s2 = arr[end];

    while (start < end)
    {

        if (s1 == s2)
        {
            ans = s1;

            start++;
            end--;

            s1 += arr[start];
            s2 += arr[end];
        }

        else if (s1 < s2)
        {

            start++;

            s1 += arr[start];
        }

        else
        {

            end--;

            s2 += arr[end];
        }
    }

    return ans;
}