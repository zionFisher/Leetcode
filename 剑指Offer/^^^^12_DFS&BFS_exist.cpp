// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
#include "SuperSet.hpp"

class Solution
{
private:
    int top = -1, bottom, left = -1, right;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        bottom = board.size();
        right = board[0].size();

        for (int i = 0; i < bottom; i++)
            for (int j = 0; j < right; j++)
                if (board[i][j] == word[0])
                    if (dfs(board, word, 1, j, i))
                        return true;

        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int index, int posX, int posY)
    {
        if (index == word.size())
            return true;

        board[posY][posX] = '\0';

        bool flag = false;

        if (posX + 1 < right && board[posY][posX + 1] == word[index])
            flag |= dfs(board, word, index + 1, posX + 1, posY);
        if (posY + 1 < bottom && board[posY + 1][posX] == word[index])
            flag |= dfs(board, word, index + 1, posX, posY + 1);
        if (posX - 1 > left && board[posY][posX - 1] == word[index])
            flag |= dfs(board, word, index + 1, posX - 1, posY);
        if (posY - 1 > top && board[posY - 1][posX] == word[index])
            flag |= dfs(board, word, index + 1, posX, posY - 1);

        if (!flag)
            board[posY][posX] = word[index - 1];
        return flag;
    }
};