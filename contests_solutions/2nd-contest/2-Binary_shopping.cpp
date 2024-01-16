#include <iostream>
using namespace std;
void printTheDiamond(int r, int c, int s)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < c; k++)
            {
                for (int l = 0; l < (s - j - 1); l++)
                {
                    cout << "e";
                }
                cout << "/";
                for (int m = 0; m < j; m++)
                {
                    cout << "oo";
                }
                cout << "\\";
                for (int l = 0; l < (s - j - 1); l++)
                {
                    cout << "e";
                }
            }
            cout << endl;
        }
        for (int j = 0; j < s; j++)
        {

            for (int k = 0; k < c; k++)
            {
                for (int m = j; m > 0; m--)
                {
                    cout << "e";
                }
                cout << "\\";
                for (int l = j + 1; l < s; l++)
                {
                    cout << "oo";
                }
                cout << "/";
                for (int m = j; m > 0; m--)
                {
                    cout << "e";
                }
            }
            cout << endl;
        }
    }
}