// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (lookup.find(s[i]) != lookup.end())
            {
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i - left + 1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         // 哈希集合，记录每个字符是否出现过
//         unordered_set<char> occ;
//         int n = s.size();
//         // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
//         int rk = -1, ans = 0;
//         // 枚举左指针的位置，初始值隐性地表示为 -1
//         for (int i = 0; i < n; ++i)
//         {
//             if (i != 0)
//             {
//                 // 左指针向右移动一格，移除一个字符
//                 occ.erase(s[i - 1]);
//             }
//             while (rk + 1 < n && !occ.count(s[rk + 1]))
//             {
//                 // 不断地移动右指针
//                 occ.insert(s[rk + 1]);
//                 ++rk;
//             }
//             // 第 i 到 rk 个字符是一个极长的无重复字符子串
//             ans = max(ans, rk - i + 1);
//         }
//         return ans;
//     }
// };

// stupid solution
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<char> set;
//         int res = 0;
//         int counter = 0;
//         int size = s.size();
//         for (int i = 0; i < size; ++i)
//         {
//             for (int j = i; j < size; ++j)
//             {
//                 if (set.count(s[j]))
//                 {
//                     set.clear();
//                     counter = 0;
//                     break;
//                 }
//                 else
//                     counter++;
//                 set.insert(s[j]);
//                 res = max(res, counter);
//             }
//         }
//         return res;
//     }
// };