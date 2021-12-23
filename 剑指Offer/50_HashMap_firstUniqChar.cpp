// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, bool> map;
        for (auto &it : s)
            map[it] = map.find(it) != map.end() ? false : true;
        for (auto &it : s)
            if (map[it])
                return it;

        return ' ';
    }
};