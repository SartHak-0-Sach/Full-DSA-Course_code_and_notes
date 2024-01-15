#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long appleAndCoupon(int n, int m, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    sum -= arr[arr.size() - m];
    return sum;
}