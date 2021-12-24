// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int begin = 0, size = s.size(), length = 1, res = 1;
        unordered_set<char> set = {s[0]};

        for (int i = 1; i < size; ++i)
        {
            while (set.count(s[i]))
            {
                set.erase(s[begin++]);
                length--;
            }
            set.insert(s[i]);
            length++;
            res = max(res, length);
        }

        return res;
    }
};