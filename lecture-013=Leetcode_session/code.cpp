// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(nullptr);
//         int totalSum = 0;
//         int n = nums.size();
//         for (int num : nums) {
//             totalSum += num;
//         }
//         int leftSum = 0;
//         for (int i = 0; i < n; i++) {
//             if (leftSum == totalSum - leftSum - nums[i]) {
//                 return i;
//             }
//             leftSum += nums[i];
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(nullptr);
//         int left = 0;
//         int right = arr.size() - 1;
//         int mid;
//         while (left < right) {
//             mid = left + (right - left) / 2;
//             if (arr[mid] > arr[mid + 1]) {
//                 right = mid;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return left;
//     }
// };


// int secondOccurence(vector<int>& arr, int n, int k)
// {
//     int start = 0;
//     int end = n-1;
//     int ans = -1;
//     while(start<=end)
//     {
//         int mid = start + (end-start)/2;
//         if(arr[mid]<k)
//         start = mid+1;

//         if(arr[mid]>k)
//         end = mid-1;

//         if(arr[mid]==k)
//         {
//             ans = mid;
//             start++;
//         }
//     }
//     return ans;
// }

// int firstOccurence(vector<int>& arr, int n, int k)
// {
//     int start = 0;
//     int end = n-1;
//     int ans = -1;
//     while(start<=end)
//     {
//         int mid = start + (end-start)/2;
//         if(arr[mid]<k)
//         start = mid+1;

//         if(arr[mid]>k)
//         end = mid-1;

//         if(arr[mid]==k)
//         {
//             ans = mid;
//             end--;
//         }
//     }
//     return ans;
// }

// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     pair<int, int> ans;
//     ans.first = firstOccurence(arr, n, k);
//     ans.second = secondOccurence(arr, n, k);
//     return ans;
// }