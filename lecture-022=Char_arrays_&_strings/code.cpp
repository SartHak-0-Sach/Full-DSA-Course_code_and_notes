#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>
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

bool checkPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        while (i < j && !isalnum(s[i])) // Skip non-alphanumeric characters from start
            i++;
        while (i < j && !isalnum(s[j])) // Skip non-alphanumeric characters from end
            j--;

        if (tolower(s[i++]) != tolower(s[j--])) // Ignore case
            return false;
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



int main(int argc, char const *argv[])
{

    return 0;
}
