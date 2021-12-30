// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/submissions/
#include "SuperSet.hpp"

// need only one line, space complexity: O(grid[0].size())
class Solution
{
public:
    int maxValue(vector<vector<int>>& grid)
    {
        int width = grid[0].size(), height = grid.size();
        vector<int> line(width, 0);

        for (int row = 0; row < height; row++)
        {
            line[0] += grid[row][0];
            for (int column = 1; column < width; column++)
                line[column] = grid[row][column] + max(line[column - 1], line[column]);
        }

        return line[width - 1];
    }
};

// need two line, space complexity: O(2 * grid[0].size())
// class Solution
// {
// public:
//     int maxValue(vector<vector<int>>& grid)
//     {
//         int width = grid[0].size(), height = grid.size();
//         vector<int> line = { grid[0][0] };
//
//         for (int column = 1; column < width; column++)
//             line.push_back(line[column - 1] + grid[0][column]);
//
//         vector<int> res(line);
//
//         for (int row = 1; row < height; row++)
//         {
//             res[0] = line[0] + grid[row][0];
//             for (int column = 1; column < width; column++)
//                 res[column] = grid[row][column] + max(res[column - 1], line[column]);
//             line = res;
//         }
//
//         return res[width - 1];
//     }
// };