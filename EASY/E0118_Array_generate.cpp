// https://leetcode-cn.com/problems/pascals-triangle/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows <= 0)
            return vector<vector<int>>();
        vector<vector<int>> res;

        for (int i = 0; i < numRows; ++i)
        {
            res.push_back(vector<int>(i + 1));
            res[i][0] = 1;
            res[i][i] = 1;
            for (int j = 1; j < i; ++j)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }

        return res;
    }
};