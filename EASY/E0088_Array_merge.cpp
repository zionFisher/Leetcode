// https://leetcode-cn.com/problems/merge-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> temp;

        int ptr1 = 0, ptr2 = 0;

        while (ptr1 < m && ptr2 < n)
        {
            if (nums1[ptr1] < nums2[ptr2])
            {
                temp.push_back(nums1[ptr1++]);
            }
            else
            {
                temp.push_back(nums2[ptr2++]);
            }
        }

        if (ptr1 == m)
        {
            while (ptr2 < n)
            {
                temp.push_back(nums2[ptr2++]);
            }
        }
        else if (ptr2 == n)
        {
            while (ptr1 < m)
            {
                temp.push_back(nums1[ptr1++]);
            }
        }

        nums1.swap(temp);
    }
};

// O(nlogn)
// class Solution
// {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//     {
//         if (nums2.size() == 0)
//             return;

//         int begin = m - 1;
//         int size = nums1.size();

//         for (int count = 0; count < n; count++)
//         {
//             if (begin++ < size)
//                 nums1[begin] = nums2[count];
//             else
//                 nums1.push_back(nums2[count]);
//         }

//         sort(nums1.begin(), nums1.end());
//     }
// };