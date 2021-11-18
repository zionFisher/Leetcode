// https://leetcode-cn.com/problems/valid-palindrome/
#include <cctype>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sgood;
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (sgood[left] != sgood[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isPalindrome(string s)
//     {
//         int head = 0, tail = s.size() - 1;
//         while (head < tail)
//         {
//             char a = s[head];
//             char b = s[tail];
//             if ((s[head] > '9' || s[head] < '0') && (s[head] > 'Z' || s[head] < 'A')
//                    && (s[head] > 'z' || s[head] < 'a') || s[head] == ' ')
//             {
//                 head++;
//                 continue;
//             }
//             if ((s[tail] > '9' || s[tail] < '0') && (s[tail] > 'Z' || s[tail] < 'A')
//                     && (s[tail] > 'z' || s[tail] < 'a') || s[tail] == ' ')
//             {
//                 tail--;
//                 continue;
//             }

//             if (s[head] <= '9' && s[tail] <= '9')
//             {
//                 if(s[head] != s[tail])
//                 {
//                     return false;
//                 }
//             }
//             if (s[head] < 'a' && s[tail] < 'a')
//             {
//                 if (s[head] != s[tail])
//                 {
//                     return false;
//                 }
//             }
//             else if (s[head] < 'a' && s[tail] >= 'a')
//             {
//                 if (s[head] + 32 != s[tail])
//                 {
//                     return false;
//                 }
//             }
//             else if (s[head] >= 'a' && s[tail] < 'a')
//             {
//                 if (s[head] != s[tail] + 32)
//                 {
//                     return false;
//                 }
//             }
//             else if (s[head] >= 'a' && s[tail] >= 'a')
//             {
//                 if (s[head] != s[tail])
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 return false;
//             }

//             head++;
//             tail--;
//         }
//         return true;
//     }
// };