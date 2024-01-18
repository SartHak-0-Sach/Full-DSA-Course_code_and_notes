#include <iostream>
#include <vector>
using namespace std;

int LightUptheStreet(int n, int m, int k, vector<int> check)
{
    int last = 0;
    int next = 0;
    int count = 1;
    int i = 0;
    bool c = 1;
    if ((check[0] - k <= 1) && (check[m - 1] + k >= n))
    {
        while (i < m)
        {
            if ((check[i] - k <= 1) && (check[i] + k >= n))
            {
                c = 0;
                break;
            }
            if (i <= m - 2)
            {
                if (check[i + 1] - check[i] - 1 > 2 * k)
                {
                    return -1;
                    break;
                }
            }
            if (i == m - 1)
            {
                if (last > next + 1)
                {
                    count++;
                    c = 0;
                }
            }
            if (check[i] + k >= n)
            {
                count++;
                c = 0;
                break;
            }
            if (check[i] - k <= 1)
            {
                last = check[i + 1] - k;
                next = check[i] + k;
                i++;
            }
            else if (last <= next + 1)
            {
                i++;
                last = check[i] - k;
            }
            else if (last > next + 1)
            {
                i--;
                last = check[i + 1] - k;
                next = check[i] + k;
                count++;
                c = 0;
            }
        }
        if (c)
        {
            return -1;
        }
        else
        {
            return count;
        }
    }
    else
    {
        return -1;
    }
}