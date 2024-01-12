#include <iostream>
using namespace std;

int main()
{
    cout << "Namaste Duniya :-)" << endl;

    int a = 12;               // 4 bytes
    bool b = false;           // 1 byte
    char c = 'a';             // 1 byte
    double d = 3.1415926535;  // 8 bytes
    float f = 323.34;         // 4 bytes
    string s = "Love Babbar"; // sizeof works differently for strings as it depends on various other stuff in this case
    // there can be other types of datatypes used too like long double, long long, unsigned int, __int128 and so on

    cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " " << sizeof(d) << " " << sizeof(f) << " " << sizeof(s) << endl;

    int e = 23;

    cout << a / e << " " << (float)a / e << endl; // advantage of typecasting
    cout << 2/a << " " << 2.0/a <<endl; // another way of doing typecasting

    return 0;
}