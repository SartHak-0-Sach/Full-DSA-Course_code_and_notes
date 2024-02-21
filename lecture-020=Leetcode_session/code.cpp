#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int start = m + 1;
    int end = arr.size() - 1;
    while (start < end)
        swap(arr[start++], arr[end--]);
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
            ans.push_back(nums1[i++]);
        else
            ans.push_back(nums2[j++]);
    }

    while (i < m)
        ans.push_back(nums1[i++]);

    while (j < n)
        ans.push_back(nums2[j++]);

    for (int l = 0; l < m + n; l++)
        nums1[l] = ans[l];
}

void moveZeroes(vector<int> &nums)
{
    int nonZeroIndex = 0; // Index to place the next non-zero element

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++)
    {
        // If the current element is non-zero, move it to the next available position
        if (nums[i] != 0)
        {
            if (i != nonZeroIndex)
            { // Avoid unnecessary swaps
                swap(nums[nonZeroIndex], nums[i]);
            }
            nonZeroIndex++; // Move the non-zero index forward
        }
    }
}