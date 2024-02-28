#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>
#include <unordered_map>
using namespace std;

int getLength(string &s) { return s.length(); }

void reverseString(vector<char> &s)
{
    int i = 0;
    int l = s.size() - 1;
    while (i < l)
    {
        swap(s[i], s[l]);
        i++;
        l--;
    }
}

bool check(string temp)
{
    int i = 0, j = temp.size() - 1;
    while (i < j)
    {
        if (temp[i++] != temp[j--])
        {
            return false;
        }
    }
    return true;
}
// bool checkRecursive(string s,int left,int right){
//     if(left>=right){
//         return true;
//     }
//     return s[left]==s[right] && checkRecursive(s,left+1,right-1);
// }
bool isPalindrome(string s)
{
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            temp += tolower(s[i]);
        }
    }
    return check(temp);
    // return checkRecursive(temp,0,temp.size()-1);
}

string reverseWords(string s)
{
    // Create a stringstream object 'ss' using the input string 's'
    stringstream ss(s);

    // Initialize an empty string 'o' to store individual reversed words
    string o = "";

    // Initialize a string 'ans' to store the final reversed string
    string ans;

    // Read the first word from 'ss' and store it in 'ans'
    ss >> ans;

    // Reverse the characters in 'ans'
    reverse(ans.begin(), ans.end());

    // Loop until the end of the stringstream is reached
    while (!ss.eof())
    {
        // Read the next word from 'ss' and store it in 'o'
        ss >> o;

        // Reverse the characters in 'o'
        reverse(o.begin(), o.end());

        // Add a space to 'ans' to separate words, then concatenate 'o' to 'ans'
        ans.push_back(' ');
        ans += o;
    }

    // Return the final reversed string 'ans'
    return ans;
}

int myAtoi(string s)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    while (i < s.size() && isdigit(s[i]))
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }
    return result * sign;
}

string intToRoman(int num)
{
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40,
                          10, 9, 5, 4, 1};
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                              "X", "IX", "V", "IV", "I"};
    string ans = "";
    for (int i = 0; i < values.size(); i++)
    {
        while (num >= values[i])
        {
            num -= values[i];
            ans += symbols[i];
        }
    }
    return ans;
}

int romanToInt(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                ans -= 1;
            }
            else
            {
                ans += 1;
            }
        }
        else if (s[i] == 'V')
        {
            ans += 5;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
            {
                ans -= 10;
            }
            else
            {
                ans += 10;
            }
        }
        else if (s[i] == 'L')
        {
            ans += 50;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
            {
                ans -= 100;
            }
            else
            {
                ans += 100;
            }
        }
        else if (s[i] == 'D')
        {
            ans += 500;
        }
        else if (s[i] == 'M')
        {
            ans += 1000;
        }
    }
    return ans;
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int temp = x;
    int reverse = 0;
    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return reverse == x;
}

int firstUniqChar(string s)
{
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (count[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

string addBinary(string a, string b)
{
    string result = "";
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }
        result += to_string(sum % 2);
        carry = sum / 2;
    }
    if (carry)
    {
        result += to_string(carry);
    }
    reverse(result.begin(), result.end());
    return result;
}

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    string s = countAndSay(n - 1);
    string result = "";
    int count = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            result += to_string(count) + s[i];
            count = 1;
        }
    }
    return result;
}

bool isIsomorphic(string s, string t)
{
    vector<int> sMap(256, -1);
    vector<int> tMap(256, -1);
    for (int i = 0; i < s.size(); i++)
    {
        if (sMap[s[i]] != tMap[t[i]])
        {
            return false;
        }
        sMap[s[i]] = i;
        tMap[t[i]] = i;
    }
    return true;
}

int findString(const string &s, const string &part)
{
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == part[index])
        {
            while (index < part.length())
            {
                if (s[i + index] != part[index])
                {
                    index = 0;
                    break;
                }
                if (index == part.length() - 1)
                    return i;
                else
                    index++;
            }
        }
        index = 0;
    }
    return -1;
}

string remove(string s, const string &part)
{
    int index = findString(s, part);
    if (index == -1)
        return s;
    s.erase(index, part.length());
    return s;
}

string removeOccurrences(string s, const string &part)
{
    string ans = s;
    string temp;
    do
    {
        temp = ans;
        ans = remove(temp, part);
    } while (temp != ans);
    return ans;
} // my code for remove occurences problem

// below mentioned is the optimized answer

string removeOccurrences2(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
        s.erase(s.find(part), part.length());
    return s;
}

// premium question of leetcode
/*
186. Reverse Words in a String II
Given an input string , reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note:

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

// solution mentioned below
void reverseWords(vector<char> &s)
{
    reverse(s.begin(), s.end());
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.end());
}

void addString(string &ans, string str, int start, int end)
{
    for (int i = start; i < end; i++)
        ans = ans + str[i];

    ans += "@40";
}
string replaceSpaces(string &str)
{
    int start = 0;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            int end = i;
            addString(ans, str, start, end);
            start = i + 1;
        }
    }

    int end = str.length();
    addString(ans, str, start, end);

    ans.erase(ans.length() - 3, ans.length());

    return ans;
} // slower approach for doing replace space problem

// Faster approach is mentioned below

string replaceSpaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            str[i] = '@';
            str.insert(i + 1, "40");
            i += 2;
        }
    }
    return str;
}

int compress(vector<char> &s)
{
    vector<char> r;
    int ctr = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && s[i] == s[i + 1])
        {
            // If the current character is the same as the next character, increment the counter
            ctr++;
        }
        else
        {
            // If the current character is different from the next character or we reach the end of the string
            r.push_back(s[i]); // Add the character to the result vector

            // Append the count of consecutive characters if greater than 1
            if (ctr > 1)
            {
                if (ctr <= 9)
                {
                    r.push_back('0' + ctr);
                }
                else
                {
                    string count_str = to_string(ctr);
                    for (char c : count_str)
                    {
                        r.push_back(c);
                    }
                }
            }

            // Reset the counter for the next character
            ctr = 1;
        }
    }
    std::copy(r.begin(), r.end(), s.begin());
    return r.size();
}

int compress2(vector<char> &s)
{
    int n = s.size();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        int count = 0;
        char c = s[i];
        while (i < n && s[i] == c)
        {
            i++;
            count++;
        }
        s[j++] = c;
        if (count > 1)
        {
            for (char ch : to_string(count))
            {
                s[j++] = ch;
            }
        }
    }
    return j;
}

bool checkInclusion(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2)
        return false;

    // Frequency maps for characters in s1 and the current window of s2
    unordered_map<char, int> s1Freq, s2Freq;

    // Initialize frequency map for s1
    for (char c : s1)
        s1Freq[c]++;

    // Initialize frequency map for the first window of s2
    for (int i = 0; i < len1; ++i)
        s2Freq[s2[i]]++;

    // Check if the first window of s2 contains a permutation of s1
    if (s1Freq == s2Freq)
        return true;

    // Sliding window approach to check for permutations in the rest of s2
    for (int i = len1; i < len2; ++i)
    {
        // Remove the leftmost character from the current window
        char leftChar = s2[i - len1];
        if (s2Freq[leftChar] == 1)
            s2Freq.erase(leftChar);
        else
            s2Freq[leftChar]--;

        // Add the rightmost character to the current window
        s2Freq[s2[i]]++;

        // Check if the current window contains a permutation of s1
        if (s1Freq == s2Freq)
            return true;
    }

    return false;
}

bool isSubsequence(string s, string t)
{
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    return i == s.size();
}

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int ans = 0;
    vector<int> index(128, -1);
    for (int i = 0, j = 0; j < n; j++)
    {
        i = max(index[s[j]] + 1, i);
        ans = max(ans, j - i + 1);
        index[s[j]] = j;
    }
    return ans;
}

int lengthOfLongestSubstring2(string s)
{
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> index;
    for (int i = 0, j = 0; j < n; j++)
    {
        if (index.find(s[j]) != index.end())
        {
            i = max(index[s[j]] + 1, i);
        }
        ans = max(ans, j - i + 1);
        index[s[j]] = j;
    }
    return ans;
}

string removeAdjacent(string s)
{
    bool removed = false;
    for (int i = 1; i < s.length();)
    {
        if (s[i] == s[i - 1])
        {
            s.erase(i - 1, 2);
            removed = true; // MLE solution (memory limit exceeded)
        }
        else
        {
            ++i;
        }
    }
    // If any adjacent duplicates were removed, recursively call removeAdjacent again
    // to check for further adjacent duplicates
    if (removed)
    {
        return removeAdjacent(s);
    }
    else
    {
        // No adjacent duplicates left, return the modified string
        return s;
    }
}

string removeDuplicates(string s)
{
    return removeAdjacent(s);
}

void removeAdjacent2(string &s)
{
    for (int i = 1; i < s.length();)
    {
        if (s[i] == s[i - 1])
            s.erase(i - 1, 2); // TLE solution (Time limit exceeded)
        else
            ++i;
    }
}

string removeDuplicates2(string s)
{
    string ans = s; // to make ans and temp unequal
    string temp = "";
    while (ans != temp)
    {
        temp = ans;
        removeAdjacent(s);
        ans = s;
    }
    return ans;
}

string removeDuplicates3(string s)
{
    cin.tie(0);
    cout.sync_with_stdio(0);

    char *stack = new char[s.size()];
    int i = 0;

    for (char letter : s)
    {
        if (i && stack[i - 1] == letter) // Most optimized solution
            --i;
        else
            stack[i++] = letter;
    }

    return string(stack, i);
}

char getMaxOccuringChar(string str)
{
    vector<int> visited(26, 0);
    for (char i : str)
        visited[i - 'a']++;

    char largest = INT_MIN;

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] > visited[largest - 'a'])
            largest = i + 'a';
    }
    return largest;
}

char getMaxOccuringChar2(string str) // further optimizing above code, is the most optimized code for this type of problem
{
    int count[26] = {0}; // Array to store count of occurrences for each character

    // Iterate over each character in the string and update the count
    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']++;
        }
    }

    char maxChar = 'a';      // Initialize maxChar to 'a'
    int maxCount = count[0]; // Initialize maxCount to the count of 'a'

    // Iterate over the count array and find the character with the maximum count
    for (int i = 1; i < 26; i++)
    {
        if (count[i] > maxCount)
        {
            maxChar = 'a' + i;
            maxCount = count[i];
        }
    }

    return maxChar;
}

#include <cctype> // for tolower() and isalnum() functions

bool checkPalindrome(const std::string &str)
{
    int left = 0, right = str.length() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(str[left]))
            left++;

        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(str[right]))
            right--;

        // If characters are not equal, return false
        if (tolower(str[left]) != tolower(str[right]))
            return false;

        left++;
        right--;
    }

    // If the loop completes without returning false, the string is a palindrome
    return true;
}

bool checkPalindrome2(const std::string &str)
{
    int left = 0, right = str.length() - 1;

    while (left < right)
    {
        // If characters are not equal, return false
        if (tolower(str[left]) != tolower(str[right])) // on including non-alphanumeric characters we can check the way we were doing earlier
            return false;

        left++;
        right--;
    }

    // If the loop completes without returning false, the string is a palindrome
    return true;
}

// Writing every function used in the above code from scratch and implementing it into the code without using other unknown hearder files
char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

// Check if character is alphanumeric
bool isAlnum(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isPalindrome(const std::string& str) {
    int left = 0, right = str.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isAlnum(str[left]))
            left++;

        // Skip non-alphanumeric characters from the right
        while (left < right && !isAlnum(str[right]))
            right--;

        // If characters are not equal, return false
        if (toLower(str[left]) != toLower(str[right]))
            return false;

        left++;
        right--;
    }

    // If the loop completes without returning false, the string is a palindrome
    return true;
}

int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    if (checkPalindrome(str))
        std::cout << "Yes, it is a palindrome." << std::endl;
    else
        std::cout << "No, it is not a palindrome." << std::endl;

    return 0;
}