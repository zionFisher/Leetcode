// https://leetcode.cn/problems/generate-parentheses/
#include "SuperSet.hpp"

class Solution
{
private:
    vector<string> res;
    string sta;

public:
    vector<string> generateParenthesis(int n)
    {
        lookBack(2 * n, '(', n - 1, n);
        return res;
    }

    void lookBack(int size, char cha, int leftLeft, int rightLeft)
    {
        sta.push_back(cha);

        if (sta.size() == size)
            res.emplace_back(sta);

        if (leftLeft > 0)
            lookBack(size, '(', leftLeft - 1, rightLeft);
        if (leftLeft < rightLeft)
            lookBack(size, ')', leftLeft, rightLeft - 1);

        sta.pop_back();
    }
};