// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int minArray(vector<int>& numbers)
    {
        int left = 0, right = numbers.size() - 1;

        while (left < right)
        {
            int pivot = (left + right) / 2;
            if (numbers[pivot] < numbers[right])
                right = pivot;
            else if (numbers[pivot] > numbers[right])
                left = pivot + 1;
            else
                right--;
        }
        return numbers[left];
    }
};