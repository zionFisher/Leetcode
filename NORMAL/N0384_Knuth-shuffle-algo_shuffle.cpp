// https://leetcode-cn.com/problems/shuffle-an-array/
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
private:
    vector<int> original;

public:
    Solution(vector<int> &nums)
    {
        original = nums;
    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        vector<int> nums(original); //用原数组来初始化新数组

        for (int i = nums.size() - 1; ~i; i--) //从后往前遍历
        {
            swap(nums[i], nums[rand() % (i + 1)]); //rand()能随机生成0到最大随机数的任意整数
        }                                          //rand() % (i + 1)能随机生成0到i中的任意整数

        return nums;
    }
};
