#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool totalSum(int mid, vector<int> &trees)
{
    int total = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (mid > trees[i])
            continue;

        total += trees[i] - mid;
    }
    return total;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i];

    int start = 0;
    int end = 0;
    accumulate(trees.begin(), trees.end(), end);
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        int total = totalSum(mid, trees);
        if (total == m)
            break;

        if (total > m)
            start = mid + 1;

        else
            end = mid - 1;
    }
    cout << start << endl;
    return 0;
}

// bool ispossible(vector<int> rank, int m, int mid)
// {
//     int totalorder = 0;
//     for (int i = 0; i < rank.size(); i++)
//     {
//         int numoforder = 1;
//         int mins = rank[i] * numoforder;
//         while (mins <= mid)
//         {
//             totalorder++;
//             numoforder++;
//             mins += rank[i] * numoforder;
//         }
//     }
//     if (totalorder >= m)
//         return true;
//     else
//         return false;
// }

// int minCookTime(vector<int> &rank, int m)
// {
//     sort(rank.begin(), rank.end());
//     int sum = 0;
//     int maxi = rank[rank.size() - 1];
//     for (int i = 1; i <= m; i++)
//     {
//         sum += i * maxi;
//     }
//     int s = 0, e = sum;
//     int mid = s + (e - s) / 2;
//     int ans = -1;
//     while (s <= e)
//     {
//         if (ispossible(rank, m, mid))
//         {
//             ans = mid;
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return ans;
// }

// bool distance(vector<int> &stalls, int mid, int k)
// {
//     int cowcount = 1;
//     int position = stalls[0];
//     for (int i = 0; i < stalls.size(); i++)
//     {
//         if (stalls[i] - position >= mid)
//         {
//             cowcount++;
//             position = stalls[i];
//             if (cowcount >= k)
//                 return true;
//         }
//     }
//     return false;
// }

// int aggressiveCows(vector<int> &stalls, int k)
// {
//     sort(stalls.begin(), stalls.end());
//     int s = 0;
//     int ans = -1;
//     int max = *max_element(stalls.begin(), stalls.end());
//     int min = *min_element(stalls.begin(), stalls.end());
//     int e = max - min;
//     while (s <= e)
//     {
//         int mid = s + (e - s) / 2;
//         if (distance(stalls, mid, k) == true)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//             e = mid - 1;
//     }
//     return ans;
// }

// bool isPossible(vector<int> time, int n, int m, long long mid)
// {
//     long long timecount = 0;
//     long long days = 1;
//     for (long long i = 0; i < m; i++)
//     {
//         if (timecount + time[i] <= mid)
//             timecount += time[i];
//         else
//         {
//             days++;
//             if (days > n || time[i] > mid)
//                 return false;
//             timecount = time[i];
//         }
//     }
//     return true;
// }

// long long ayushGivesNinjatest(int n, int m, vector<int> time)
// {
//     long long sum = 0;
//     long long ans = -1;
//     for (long long i = 0; i < m; i++)
//     {
//         sum += time[i];
//     }
//     long long start = 0;
//     long long end = sum;
//     while (start <= end)
//     {
//         long long mid = start + (end - start) / 2;
//         if (isPossible(time, n, m, mid))
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else
//             start = mid + 1;
//     }
//     return ans;
// }

// bool isPossible(vector<int> &boards, int k, int mid)
// {
//     int pcount = 1;
//     int boardsum = 0;
//     int n = boards.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (boardsum + boards[i] <= mid)
//         {
//             boardsum += boards[i];
//         }
//         else
//         {
//             pcount++;
//             if (pcount > k || boards[i] > mid)
//             {
//                 return false;
//             }
//             boardsum = boards[i];
//         }
//     }
//     return true;
// }

// int findLargestMinDistance(vector<int> &boards, int k)
// {
//     int start = 0;
//     int sum = 0;
//     int n = boards.size();
//     for (int i = 0; i < n; i++)
//     {
//         sum += boards[i];
//     }
//     int end = sum;
//     int mid = start + (end - start) / 2;
//     int ans = -1;

//     while (start <= end)
//     {
//         if (isPossible(boards, k, mid))
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return ans;
// }