// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        int x = 0, y = matrix.size() - 1;
        while (y > -1 && x < matrix[0].size())
        {
            if (matrix[y][x] == target)
                return true;
            if (matrix[y][x] > target)
                y--;
            else if (matrix[y][x] < target)
                x++;
        }
        return false;
    }
};