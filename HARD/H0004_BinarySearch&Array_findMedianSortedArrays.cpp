// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res = merge(nums1, nums2);
        int size = res.size();
        return size % 2 == 0 ? (double)(res[size / 2] + res[size / 2 - 1]) / 2 : (double)res[size / 2];
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        int ptr1 = 0, ptr2 = 0, size1 = nums1.size(), size2 = nums2.size();

        while (ptr1 < size1 or ptr2 < size2)
        {
            if ((ptr1 < size1 ? nums1[ptr1] : INT_MAX) < (ptr2 < size2 ? nums2[ptr2] : INT_MAX))
                res.emplace_back(nums1[ptr1++]);
            else
                res.emplace_back(nums2[ptr2++]);
        }

        return res;
    }
};