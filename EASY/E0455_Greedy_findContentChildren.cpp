// https://leetcode-cn.com/problems/assign-cookies/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0, gSize = g.size(), sSize = s.size();

        for (int i = 0, j = 0; i < gSize and j < sSize; j++)
        {
            if (g[i] <= s[j])
            {
                i++;
                res++;
            }
        }

        return res;
    }
};