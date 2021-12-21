// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/submissions/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i)
            {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

// class Solution
// {
// private:
//     unordered_set<int> set;
// public:
//     int findRepeatNumber(vector<int>& nums)
//     {
//         for (auto &it : nums)
//         {
//             if (set.count(it))
//                 return it;
//             else
//                 set.insert(it);
//         }
//         return -1;
//     }
// };