// https://leetcode-cn.com/problems/rotate-image/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int Layer = matrix.size() / 2;
        int Move = matrix.size();

        /* Top, Left, Bottom, Right */
        int T = 0;
        int L = 0;
        int B = matrix.size() - 1;
        int R = matrix.size() - 1;

        for (int LayerIdx = 0; LayerIdx < Layer; ++LayerIdx)
        {
            for (int i = 0; i < (Move - 1); i++)
            {
                swap(matrix[T][L + i], matrix[T + i][R]);
                swap(matrix[T][L + i], matrix[B][R - i]);
                swap(matrix[T][L + i], matrix[B - i][L]);
            }
            ++T;
            --B;
            --R;
            ++L;
            Move -= 2;
        }
    }
};

// class Solution
// {
// public:
//     void rotate(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
//         auto matrix_new = matrix;
//         for (int i = 0; i < n; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 matrix_new[j][n - i - 1] = matrix[i][j];
//             }
//         }
//         // 这里也是值拷贝
//         matrix = matrix_new;
//     }
// };

// class Solution
// {
// public:
//     void rotate(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         for (int i = 0; i < n / 2; ++i)
//         {
//             for (int j = 0; j < (n + 1) / 2; ++j)
//             {
//                 int temp = matrix[i][j];
//                 matrix[i][j] = matrix[n - j - 1][i];
//                 matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
//                 matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
//                 matrix[j][n - i - 1] = temp;
//             }
//         }
//     }
// };