// https://leetcode-cn.com/problems/non-overlapping-intervals/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int count = 1;             // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
                count++;
            }
        }

        return intervals.size() - count;
    }
};