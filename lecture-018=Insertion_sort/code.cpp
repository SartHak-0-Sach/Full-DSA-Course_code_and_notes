#include <iostream>
#include <vector>
using namespace std;
/*
    Time complexity: O(N^2)
    Space complexity: O(1)
    
    Where 'N' is the size of the array.
*/

void insertionSort(int n, vector<int> &arr){
    
    // To traverse all the elements.
    for(int i = 1; i < n; ++i) {
        
        // To store the current element.
        int curr = arr[i];
        
        // To traverse previous elements.    
        int idx = i - 1;
        
        while(idx >= 0 && arr[idx] > curr) {
            
            // Change elements position.
            arr[idx + 1] = arr[idx];
            
            --idx;
        }
        
        // Change current element.
        arr[idx + 1] = curr;
    }
}