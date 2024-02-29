#include <iostream>
#include <vector>
using namespace std;

/*

    Time Complexity : O(N*M)
    Space Complexity : O(N*M)

    Where N denotes the total number of rows and M denote the total number of columns.


*/

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    // Loop to iterate through the columns given to us.
    for (int j = 0; j < mCols; j++)
    {
        // If the current column is even then we will print the elements from top to bottom.
        if (j % 2 == 0)
        {
            for (int i = 0; i < nRows; i++) // provided solution on codestudio works on even and odd principle based on value of i
            {
                // store the element in the vector.
                ans.push_back(arr[i][j]);
            }
        }
        // Else the elements will be printed from bottom to top.
        else
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                // store the element in the vector.
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}

// My answer
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    bool goingUp = false;
    vector<int> ans;
    for (int i = 0; i < mCols; i++)
    {
        if (goingUp)
        {
            for (int j = nRows - 1; j >= 0; j--)
                ans.push_back(arr[j][i]);

            goingUp = !goingUp;
        }

        else
        {
            for (int j = 0; j < nRows; j++)
                ans.push_back(arr[j][i]);

            goingUp = !goingUp;
        }
    }
    return ans;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty() || matrix[0].empty())
    {
        return result;
    }

    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int mid_val = matrix[mid / n][mid % n];

        if (mid_val == target)
            return true;
        else if (mid_val < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

/*
    Time Complexity: O(N*M)
    Space Complexity: O(M)
 
    Where N is the given integer and M is the size of the result array.
*/

void helper(vector<int> &result, int x)
{
    // Inititalise carryOver as 0.
    int carryOver = 0;

    for (int i = 0; i < result.size(); i++)
    {
        int value = result[i] * x + carryOver;

        // Store last digit of value in the result.
        result[i] = value % 10;

        // Remove the last digit from value and carry the remaining value.
        carryOver = value / 10;
    }

    // Run the loop until carryOver doesn't become zero.
    while (carryOver != 0)
    {
        // Push the last digit of carryOver in result array.
        result.push_back(carryOver % 10);

        // Update the carryOver.
        carryOver = carryOver / 10;
    }
}

string calculateFactorial(int n)
{
    vector<int> result;

    // Enter 1 as the first element in the factorial array/list.
    result.push_back(1);

    // Run loop for calculating factorial for rest of the elements.
    for (int x = 2; x <= n; x++)
    {
        // Call the helper function for each x and update the result array/list.
        helper(result, x);
    }

    // We are representing answer in a string format.
    string ans = "";

    for (int i = result.size() - 1; i >= 0; i--)
    {
        ans.push_back((char)(result[i] + '0'));
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    int nRows = 4, mCols = 4;
    vector<int> ans = wavePrint(arr, nRows, mCols);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}