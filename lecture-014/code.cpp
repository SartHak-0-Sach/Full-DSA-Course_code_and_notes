#include <iostream>
#include <vector>
using namespace std;

int pivotElement(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        // int mid = start + (end - start) / 2;

        // if (arr[mid] <= arr[start] && arr[mid] <= arr[end]) // changing this we can write code of pivot element being largest one
        //     return arr[mid];

        // else if (arr[mid] > arr[start])
        //     start = mid + 1;

        // else if (arr[mid] < arr[end])
        //     end = mid - 1;

        int mid = start + (end - start) / 2;
        if(arr[mid]>=arr[0])
        start = mid+1;

        else
        end = mid;
    }
    return start;
}

int searchRotatedArray(vector<int> &arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;

        if (arr[start] <= arr[mid])
        {
            // If the key lies within the range of the left half
            if (key >= arr[start] && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        else
        {
            // If the key lies within the range of the right half
            if (key > arr[mid] && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int findPivot(vector<int> &arr, int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[end])
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int binarySearch(vector<int>& arr, int start, int end, int k) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k) {
    int pivot = findPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
        return binarySearch(arr, pivot, n - 1, k);
    else
        return binarySearch(arr, 0, pivot - 1, k);
}

int floorSqrt(int n)
{
    long long int start = 0;
    long long int end = n;
    while(start <= end)
    {
        long long int mid = start + (end-start)/2;

        if(mid*mid == n)
            return mid;

        if(mid*mid > n)
            end = mid-1;

        else
            start = mid+1;
    }
    return start-1;
}

int main(int argc, char const *argv[])
{
    // vector<int> elements = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 2, 3, 4, 5};
    vector<int> elements = {3, 7, 8, 17, 19, 21, 0, 1, 2};
    // int temp;
    // while(cin>>temp)
    // elements.push_back(temp);

    int pivot = pivotElement(elements);
    cout << pivot << "\n";

    // while (true)
    // {
    //     char sample;
    //     cout << "write q to exit" << endl;
    //     cin >> sample;
    //     if (sample == 'q')
    //         break;

    //     int key;
    //     cin >> key;

    //     int index = searchRotatedArray(elements, key);
    //     cout << index << endl;
    // }
    return 0;
}