// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
#include "SuperSet.hpp"

// DFS
class Solution
{
private:
    vector<vector<int>> matrix;
    int sum = 0, width, height;

public:
    int movingCount(int m, int n, int k)
    {
        width = m;
        height = n;

        for (int j = 0; j < height; j++)
            matrix.push_back(vector<int>());

        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++)
                matrix[j].push_back(calSum(j, i));

        dfs(k, 0, 0);
        return sum;
    }

    void dfs(int k, int posX, int posY)
    {
        matrix[posY][posX] = 21;
        sum++;

        if (posX + 1 < width && matrix[posY][posX + 1] <= k)
            dfs(k, posX + 1, posY);
        if (posY + 1 < height && matrix[posY + 1][posX] <= k)
            dfs(k, posX, posY + 1);
        if (posX - 1 > -1 && matrix[posY][posX - 1] <= k)
            dfs(k, posX - 1, posY);
        if (posY - 1 > -1 && matrix[posY - 1][posX] <= k)
            dfs(k, posX, posY - 1);
    }

    int calSum(int x, int y)
    {
        x = x == 100 ? 1 : x / 10 + x % 10;
        y = y == 100 ? 1 : y / 10 + y % 10;
        return x + y;
    }
};

// BFS
// class Solution
// {
// public:
//     int movingCount(int m, int n, int k)
//     {
//         vector<vector<bool>> visited(m, vector<bool>(n, 0));
//         int res = 0;
//         queue<vector<int>> que;
//         que.push({0, 0, 0, 0});
//         while (que.size() > 0)
//         {
//             vector<int> x = que.front();
//             que.pop();
//             int i = x[0], j = x[1], si = x[2], sj = x[3];
//             if (i >= m || j >= n || k < si + sj || visited[i][j])
//                 continue;
//             visited[i][j] = true;
//             res++;
//             que.push({i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj});
//             que.push({i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8});
//         }
//         return res;
//     }
// };