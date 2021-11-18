// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        int index = 1;
        for (auto x : nums)
            if (nums[index - 1] != x)
                nums[index++] = x;
        return index;
    }
};

// 借助 val 变量实现亦可
// class Solution 
// {
//     public int removeDuplicates(int[] nums) 
//     {
//         int n = nums.length;
//         int val = Integer.MAX_VALUE;
//         int k = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] != val)
//             {
//                 val = nums[i];
//                 nums[k++] = val;
//             }
//         }
//         return k;
//     }
// }