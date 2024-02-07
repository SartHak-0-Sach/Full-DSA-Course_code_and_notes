#include <iostream>
using namespace std;

// string ITOS(int n)
// {
//     if (n == 0)
//         return "0";

//     std::string result = "";

//     while (n > 0)
//     {
//         char digit = '0' + n % 10;
//         result = digit + result;
//         n /= 10;
//     }

//     return result;
// }

// int STOI(string str)
// {
//     int result = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         char c = str[i];
//         if ('0' <= c && '9' >= c)
//             result = result * 10 + (c - '0');
//     }
//     return result;
// }

string decimalToBinary(int n)
{
    string result = "";
    while (n > 0)
    {
        if (n & 1)
            result += "1";

        n >> 1;
    }
    return result;
}

int binaryToDecimal(string str)
{
    int result = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '1')
            result |= 1 << (str.length() - 1 - i);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string bin = decimalToBinary(n);
    cout << bin << endl;
    if (n == binaryToDecimal(bin))
        cout << binaryToDecimal(bin) << endl;
    return 0;
}