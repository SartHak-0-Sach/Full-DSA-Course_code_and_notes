#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    k = k % nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

// Can also be done by declaring a temp array

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = nums[i]; // less TC more SC approach

    for (int i = 0; i < n; i++)
        nums[i] = temp[i];
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int carry = 0;
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--];
        if (j >= 0)
            sum += b[j--];
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check(vector<int> &nums)
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (nums[nums.size() - 1] > nums[0])
        count++;

    return count <= 1;
}