#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

// int findUnique(int *arr, int size)
// {
//     int unique = 0;
//     for (int i = 0; i < size; i++)
//         unique ^= arr[i];
//     return unique;
// }

void swapAlternate(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
        swap(arr[i], arr[i - 1]);
}

void printArray(int *arr[])
{
    int size = sizeof(arr) / sizeof(int);
    cout << "The array is: ";
    for (int i = 0; i < size; i++)
        cout << (*arr)[i] << " ";
}

int findDuplicate(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

// Approach of above mentioned code mentioned below:-
// Your provided code is already quite efficient(the code i provided chatgpt where i solved this problem using unordered_maps), with a time complexity of O(n) where n is the size of the input array arr. However, we can optimize it slightly by eliminating the need for the unordered_map and using a different approach to find the duplicate.
// Here's an optimized version using Floyd's Tortoise and Hare algorithm (also known as cycle detection algorithm) which has the same time complexity but uses constant space, thus making it more memory-efficient.
// This algorithm works by considering the array elements as nodes in a linked list. Since each number between 1 and N-1 is present at least once, and there is one duplicate, there's at least one cycle in this linked list. The algorithm then uses two pointers, one moving one step at a time (slow) and the other moving two steps at a time (fast). When they meet, it indicates that there's a cycle. After that, we reset one pointer to the start and move both pointers at the same speed; they will meet at the beginning of the cycle, which is the duplicate number.
// The time complexity of both the original and the optimized versions is O(n), where n is the size of the input array. However, the optimized version uses constant space, while the original version uses extra space to store the count of each element, resulting in a space complexity of O(n). Therefore, the optimized version is more memory-efficient.

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            continue;

        else
        {
            int e = nums[i] - 1;
            if (nums[e] > 0)
            {
                swap(nums[e], nums[i--]);
                nums[e] = -1;
            }
            else
            {
                nums[e]--;
                nums[i] = 0;
            }
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == -2)
            nums[j++] = (i + 1);
    nums.resize(j);
    return nums;
}

int findDuplicate(vector<int> &arr)
{
    // unordered_map<int, int> count;
    // for(int i: arr)
    // count[i]++;

    // for(auto pair: count)
    // {
    //     if(pair.second==2)
    //     return pair.first;
    // }

    // return -1;
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            ans ^= arr[i];
            continue;
        }

        ans ^= (i + 1);
        ans ^= arr[i];
    }
    return ans;
}

bool uniqueOccurrences(vector<int> &arr)
{
    std::unordered_map<int, int> countMap;
    for (int num : arr)
    {
        countMap[num]++;
    }

    std::unordered_set<int> uniqueCounts;
    for (const auto &entry : countMap)
    {
        if (!uniqueCounts.insert(entry.second).second)
            return false;
    }
    return true;
}

void sort012(int *arr, int n)
{
    int j = 0;
    int i = n - 1;
    int start = 0;
    while (start <= i)
    {
        if (arr[start] == 2)
        {
            swap(arr[i], arr[start]); // Dutch national flag algorithm
            i--;
        }
        else if (arr[start] == 0)
        {
            swap(arr[j], arr[start]);
            j++;
            start++;
        }
        else
        {
            start++;
        }
    }
}

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
	int i = 0;
	int j = 0;
	while(i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}

		else if(arr1[i]>arr2[j])
		j++;

		else if(arr1[i]<arr2[j])
		i++;
	}
	return ans;
}

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   for(int i = 0; i<arr.size(); i++)
   {
      int compliment = s-arr[i];
      for(int j = i+1; j<arr.size(); j++)
      if(arr[j]==compliment) ans.push_back({min(compliment, arr[i]), max(compliment, arr[i])});
   }
   sort(ans.begin(), ans.end());
   return ans;
}


vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) {
            int left = i + 1, right = n - 1, target = K - arr[i];
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum == target) {
                    result.push_back({arr[i], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int sort0and1() // solve using counting sort, sort stl, two pointer approach, dutch national flag algorithm
{

}

// find the subarray of any size that sums upto required target sum 

int main(int argc, char const *argv[])
{

    return 0;
}