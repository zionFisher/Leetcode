// https://leetcode-cn.com/problems/implement-strstr/
#include <iostream>
#include <vector>
using namespace std;

// KMP algorithm using
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
        {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == m)
            {
                return i - m + 1;
            }
        }
        return -1;
    }
};

// KMP algorithm using
// class Solution
// {
// public:
//     int strStr(string s, string p)
//     {
//         int n = s.size(), m = p.size();
//         if (m == 0)
//             return 0;
//         //设置哨兵
//         s.insert(s.begin(), ' ');
//         p.insert(p.begin(), ' ');
//         vector<int> next(m + 1);
//         //预处理next数组
//         for (int i = 2, j = 0; i <= m; i++)
//         {
//             while (j and p[i] != p[j + 1])
//                 j = next[j];
//             if (p[i] == p[j + 1])
//                 j++;
//             next[i] = j;
//         }
//         //匹配过程
//         for (int i = 1, j = 0; i <= n; i++)
//         {
//             while (j and s[i] != p[j + 1])
//                 j = next[j];
//             if (s[i] == p[j + 1])
//                 j++;
//             if (j == m)
//                 return i - m;
//         }
//         return -1;
//     }
// };

// Sunday solution
// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         // 建立偏移表
//         int hSize = haystack.size();
//         int nSize = needle.size();
//         unordered_map<char, int> pianyi;
//         for (int i = 0; i < nSize; i++)
//             pianyi[needle[i]] = nSize - i;

//         // 遍历
//         int i = 0;
//         while (i <= hSize - nSize)
//         {
//             if (haystack.substr(i, nSize) == needle)
//                 return i;
//             else
//             {
//                 // 查询substr后的字符的偏移值
//                 if (i + nSize > hSize - 1)
//                     return -1;
//                 else
//                 {
//                     if (pianyi.find(haystack[i + nSize]) != pianyi.end())
//                     {
//                         i += pianyi[haystack[i + nSize]];
//                     }
//                     else
//                     {
//                         i += nSize + 1;
//                     }
//                 }
//             }
//         }

//         return -1;
//     }
// };