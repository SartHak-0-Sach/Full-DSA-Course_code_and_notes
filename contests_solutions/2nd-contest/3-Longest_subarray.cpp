#include <iostream>
#include <vector>
using namespace std;

vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    vector<int> sol;
    int i = 0;
    while (i < q)
    {
        int temp = queries[i];
        int st = arr[0];
        int j = 1;
        int store = 0;
        if (st >= temp)
        {
            store = 1;
        }
        while (j < n)
        {
            if ((st & arr[j]) >= temp)
            {
                store = j + 1;
                st = st & arr[j];
                if (j == n - 1)
                {
                    sol.push_back(store);
                }
                j++;
            }
            else
            {
                sol.push_back(store);
                break;
            }
        }
        i++;
    }
    return sol;
}