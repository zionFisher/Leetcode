// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <string>
#include <vector>
using namespace std;

// DP solution
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        int length = 1;
        int begin = 0, end = 0;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i)
            dp[i][i] = 1;

        for (int r = 1; r < size; ++r)
        {
            for (int l = 0; l < r; ++l)
            {
                if (s[r] == s[l] && (r - l <= 2 || dp[l + 1][r - 1]))
                {
                    dp[l][r] = 1;
                    if (r - l + 1 > length)
                    {
                        length = r - l + 1;
                        begin = l;
                        end = r;
                    }
                }
            }
        }

        return s.substr(begin, end - begin + 1);
    }
};

// better solution
// class Solution
// {
// public:
//     pair<int, int> expandAroundCenter(const string &s, int left, int right)
//     {
//         while (left >= 0 && right < s.size() && s[left] == s[right])
//         {
//             --left;
//             ++right;
//         }
//         return {left + 1, right - 1};
//     }
//
//     string longestPalindrome(string s)
//     {
//         int start = 0, end = 0;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             auto [left1, right1] = expandAroundCenter(s, i, i);
//             auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//             if (right1 - left1 > end - start)                        // end - start represent length or result
//             {
//                 start = left1;
//                 end = right1;
//             }
//             if (right2 - left2 > end - start)
//             {
//                 start = left2;
//                 end = right2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// };

// common DP solution, but slow and weird, enum the length of substring rather enum the right border
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         if (n < 2)
//         {
//             return s;
//         }
//
//         int maxLen = 1;
//         int begin = 0;
//         // dp[i][j] ?????? s[i..j] ??????????????????
//         vector<vector<int>> dp(n, vector<int>(n));
//         // ??????????????????????????? 1 ????????????????????????
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][i] = true;
//         }
//         // ????????????
//         // ?????????????????????
//         for (int L = 2; L <= n; L++)
//         {
//             // ????????????????????????????????????????????????????????????
//             for (int i = 0; i < n; i++)
//             {
//                 // ??? L ??? i ??????????????????????????? j - i + 1 = L ???
//                 int j = L + i - 1;
//                 // ???????????????????????????????????????????????????
//                 if (j >= n)
//                 {
//                     break;
//                 }
//
//                 if (s[i] != s[j])
//                 {
//                     dp[i][j] = false;
//                 }
//                 else
//                 {
//                     if (j - i < 3)
//                     {
//                         dp[i][j] = true;
//                     }
//                     else
//                     {
//                         dp[i][j] = dp[i + 1][j - 1];
//                     }
//                 }
//
//                 // ?????? dp[i][L] == true ???????????????????????? s[i..L] ???????????????????????????????????????????????????
//                 if (dp[i][j] && j - i + 1 > maxLen)
//                 {
//                     maxLen = j - i + 1;
//                     begin = i;
//                 }
//             }
//         }
//         return s.substr(begin, maxLen);
//     }
// };