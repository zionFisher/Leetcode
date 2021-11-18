// https://leetcode-cn.com/problems/3sum/
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ptrA, ptrB;
        vector<vector<int>> res;
        for (int i = 0; i < size - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            ptrA = i + 1;
            ptrB = size - 1;
            while (ptrA < ptrB)
            {
                if (ptrA > i + 1 && nums[ptrA] == nums[ptrA - 1])
                {
                    ptrA++;
                    continue;
                }
                if (ptrB < size - 1 && nums[ptrB] == nums[ptrB + 1])
                {
                    ptrB--;
                    continue;
                }

                int s = nums[i] + nums[ptrA] + nums[ptrB];
                if (s > 0)
                    ptrB--;
                if (s < 0)
                    ptrA++;
                if (s == 0)
                {
                    res.push_back({nums[i], nums[ptrA], nums[ptrB]});
                    ptrA++;
                    ptrB--;
                }
            }
        }
        return res;
    }
};

// common solution
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         // 枚举 a
//         for (int first = 0; first < n; ++first)
//         {
//             // 需要和上一次枚举的数不相同
//             if (first > 0 && nums[first] == nums[first - 1])
//             {
//                 continue;
//             }
//             // c 对应的指针初始指向数组的最右端
//             int third = n - 1;
//             int target = -nums[first];
//             // 枚举 b
//             for (int second = first + 1; second < n; ++second)
//             {
//                 // 需要和上一次枚举的数不相同
//                 if (second > first + 1 && nums[second] == nums[second - 1])
//                 {
//                     continue;
//                 }
//                 // 需要保证 b 的指针在 c 的指针的左侧
//                 while (second < third && nums[second] + nums[third] > target)
//                 {
//                     --third;
//                 }
//                 // 如果指针重合，随着 b 后续的增加
//                 // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
//                 if (second == third)
//                 {
//                     break;
//                 }
//                 if (nums[second] + nums[third] == target)
//                 {
//                     ans.push_back({nums[first], nums[second], nums[third]});
//                 }
//             }
//         }
//         return ans;
//     }
// };