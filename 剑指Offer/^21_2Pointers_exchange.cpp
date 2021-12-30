// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int size = nums.size(), ptr1 = 0, ptr2 = size - 1;

        while (ptr1 < ptr2)
        {
            while (ptr2 > 0 && (nums[ptr2] & 1) == 0)
                ptr2--;
            while (ptr1 < size && (nums[ptr1] & 1) == 1)
                ptr1++;
            if (ptr1 < ptr2)
                swap(nums[ptr1], nums[ptr2]);
        }

        return nums;
    }
};

// class Solution
// {
// public:
//     vector<int> exchange(vector<int> &nums)
//     {
//         vector<int> odd, even;
//
//         for (auto &it : nums)
//         {
//             if (it % 2 == 0)
//                 even.push_back(it);
//             else
//                 odd.push_back(it);
//         }
//
//         odd.insert(odd.end(), even.begin(), even.end());
//
//         return odd;
//     }
// };