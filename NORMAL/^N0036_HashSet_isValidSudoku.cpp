// https://leetcode-cn.com/problems/valid-sudoku/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int count = 0; count < 9; count++)
        {
            unordered_set<char> set;
            for (int num = 0; num < 9; num++)
            {
                if (set.find(board[count][num]) != set.end())
                {
                    return false;
                }
                if (board[count][num] != '.')
                {
                    set.insert(board[count][num]);
                }
            }
        }
        for (int num = 0; num < 9; num++)
        {
            unordered_set<char> set;
            for (int count = 0; count < 9; count++)
            {
                if (set.find(board[count][num]) != set.end())
                {
                    return false;
                }
                if (board[count][num] != '.')
                {
                    set.insert(board[count][num]);
                }
            }
        }
        for (int outer = 0; outer < 3; outer++)
        {
            for (int inter = 0; inter < 3; inter++)
            {
                unordered_set<char> set;
                for (int outside = 0; outside < 3; outside++)
                {
                    for (int inside = 0; inside < 3; inside++)
                    {
                        if (set.find(board[outside + outer * 3][inside + inter * 3]) != set.end())
                        {
                            return false;
                        }
                        if (board[outside + outer * 3][inside + inter * 3] != '.')
                        {
                            set.insert(board[outside + outer * 3][inside + inter * 3]);
                        }
                    }
                }
            }
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isValidSudoku(vector<vector<char>> &board)
//     {
//         int row[9][10] = {0}; // 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
//         // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
//         int col[9][10] = {0}; // 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
//         int box[9][10] = {0}; // 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
//         for (int i = 0; i < 9; i++)
//         {
//             for (int j = 0; j < 9; j++)
//             {
//                 // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
//                 // 同时判断这个数在其所在的列有没有出现过
//                 // 同时判断这个数在其所在的box中有没有出现过
//                 if (board[i][j] == '.')
//                     continue;
//                 int curNumber = board[i][j] - '0';
//                 if (row[i][curNumber])
//                     return false;
//                 if (col[j][curNumber])
//                     return false;
//                 if (box[j / 3 + (i / 3) * 3][curNumber])
//                     return false;

//                 row[i][curNumber] = 1; // 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
//                 col[j][curNumber] = 1;
//                 box[j / 3 + (i / 3) * 3][curNumber] = 1;
//             }
//         }
//         return true;
//     }
// };