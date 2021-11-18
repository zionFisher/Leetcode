// https://leetcode-cn.com/problems/longest-common-prefix/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int size = strs.size();
        string result;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            result += strs[0][i];
            for (int j = 0; j < size; ++j)
            {
                if (strs[j].size() < result.size() || strs[j][i] != result[i])
                {
                    result.pop_back();
                    return result;
                }
            }
        }
        return result;
    }
};