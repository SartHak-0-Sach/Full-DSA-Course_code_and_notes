#include <iostream>
using namespace std;

void reverseAnArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
        swap(arr[start++], arr[end--]);
}

int main(int argc, char const *argv[])
{
    int evenArr[10] = {1, 3, 5, 6, 32, 4, 45, 56, 54, 423};
    int oddArr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    reverseAnArray(evenArr, 10);
    reverseAnArray(oddArr, 11);
    for (int i = 0; i < 10; i++)
        cout << evenArr[i] << " " << oddArr[i] << endl;
    return 0;
}