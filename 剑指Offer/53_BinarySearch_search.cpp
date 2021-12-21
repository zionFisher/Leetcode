// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include <vector>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
};

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         int pos = binarySearch(nums, 0, nums.size() - 1, target);
//         if (pos == -1)
//             return 0;
//         int res = 0, left = pos, right = pos + 1;
//         while (left > -1 && nums[left--] == target)
//             res++;
//         while (right < nums.size() && nums[right++] == target)
//             res++;

//         return res;
//     }

//     int binarySearch(vector<int> &arr, int left, int right, int target)
//     {
//         if (left > right || arr.size() == 0)
//             return -1;
//         int pivot = (left + right) / 2;
//         if (arr[pivot] == target)
//             return pivot;
//         else if ((arr[pivot]) > target)
//             return binarySearch(arr, left, pivot - 1, target);
//         else
//             return binarySearch(arr, pivot + 1, right, target);
//     }
// };