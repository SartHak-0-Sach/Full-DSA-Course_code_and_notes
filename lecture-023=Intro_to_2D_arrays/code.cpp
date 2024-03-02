#include <iostream>
#include <vector>
#include <algorithm>
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

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]); // transpose then reverse each array approach
        }
    }
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

void rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++) // most space and time optimized code version of above code
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));

    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            result[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result[i][right] = num++;
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result[bottom][i] = num++;
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result[i][left] = num++;
            }
            left++;
        }
    }

    return result;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
            break;
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[0][i] == 1)
            break;
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 0);

    int minPrice = prices[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1], prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    return dp[n - 1];
}

int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}

int maxProfit3(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for (int i = 1; i < n; i++)
    {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }

    return sell2;
}

int maxProfit4(int k, vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    if (k >= n / 2)
    {
        int maxProfit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; i++)
    {
        int maxDiff = -prices[0];
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[k][n - 1];
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
    while (r < m && c >= 0)
    {
        if (matrix[r][c] == target)
        {
            return true;
        }
        matrix[r][c] > target ? c-- : r++;
    }
    return false;
}

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

bool searchMatrix2(vector<vector<int>> &arr, int target)
{
    int maxRow = arr.size(), maxCol = arr[0].size(); // space and time optimized version of above code but approach is still the same
    int currRow = 0, currCol = maxCol - 1;

    while (currCol >= 0 && currRow < maxRow)
    {
        if (arr[currRow][currCol] == target)
        {
            arr.clear();

            return true;
        }

        if (arr[currRow][currCol] > target)
        {
            currCol--;
        }
        else
        {
            currRow++;
        }
    }

    arr.clear();

    return false;
}

// Exercises
// Write the following functions:

// double average( const double x[ ], int nValues, int & errorCode );
// Calculates the average of the values in x.
// nValues is how many elements to calculate
// errorCode should be set to 0 if no errors or -1 if errors are encountered.
// double dot( const double x[ ], const double y[ ], int nValues, int & errorCode );
// Calculates the dot product of x and y.
// nValues is how many elements to calculate
// errorCode should be set to 0 if no errors or -1 if errors are encountered.
// int calcSins( const double x[ ], double sinX[ ], int nValues );
// Calculates the sin of each element of x, and stores the results in sinX.
// nValues is how many elements to calculate
// The return value is the actual number of values calculated. It should be equal to nValues if all goes well, or some other value ( e.g. zero ) if there is a problem.
// Character Strings as Arrays of Characters
// The "string" class type is a new addition to C++, which did not exist in traditional C.
// The traditional method for handling character strings is to use an array of characters.
// A null byte ( character constant zero, '\0' ) is used as a terminator signal to mark the end of the string.
// Ordinary quoted strings ( "Please enter a number > " ) are stored as null-terminated arrays of characters.
// The cstring library contains a number of functions for dealing with traditional arrays of characters.
// C++ string objects can be initialized using C-style traditional arrays of characters:
// string prompt = "Please enter your choice > ";

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