#include <iostream>
#include <vector>
using namespace std;

// int findUnique(int *arr, int size)
// {
//     int unique = 0;
//     for (int i = 0; i < size; i++)
//         unique ^= arr[i];
//     return unique;
// }

void printArray(int *arr[])
{
    int size = sizeof(arr) / sizeof(int);
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

int main(int argc, char const *argv[])
{

    return 0;
}