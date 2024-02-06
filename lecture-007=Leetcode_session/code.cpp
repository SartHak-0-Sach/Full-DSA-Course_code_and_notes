#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        bool negativeNum = false;

        if (x < 0)
        {
            negativeNum = true;
            x = abs(x);
        }

        while (x > 0)
        {
            int lastDigit = x % 10;

            // Check for overflow and underflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && lastDigit > 7))
            {
                return 0;
            }
            if (-1 * ans < INT_MIN / 10 || (-1 * ans == INT_MIN / 10 && lastDigit < -8))
            {
                return 0;
            }

            ans = ans * 10 + lastDigit;
            x /= 10;
        }

        if (negativeNum)
        {
            return -1 * ans;
        }

        return ans;
    }

    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;

        int mask = 0;
        int m = n;
        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        return (~n & mask);
    }

    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        if (n == 1)
        {
            return true;
        }

        if (n % 2 != 0)
        {
            return false;
        }

        return isPowerOfTwo(n / 2);
    }
};