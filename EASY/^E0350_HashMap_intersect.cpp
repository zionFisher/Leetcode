// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> target;
        unordered_set<int> key;
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for (auto x : nums1)
        {
            key.insert(x);
            map1[x] += 1;
        }
        for (auto x : nums2)
        {
            map2[x] += 1;
        }
        for (auto x : key)
        {
            if (map2.find(x) != map2.end())
            {
                int times = min(map1[x], map2[x]);
                for (int count = 0; count < times; count++)
                {
                    target.push_back(x);
                }
            }
        }
        return target;
    }
};

// The better HashSet solution O(m + n) space using O(min(m, n))
// class Solution
// {
// public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         if (nums1.size() > nums2.size())
//         {
//             return intersect(nums2, nums1);
//         }
//         unordered_map<int, int> m;
//         for (int num : nums1)
//         {
//             ++m[num];
//         }
//         vector<int> intersection;
//         for (int num : nums2)
//         {
//             if (m.count(num))
//             {
//                 intersection.push_back(num);
//                 --m[num];
//                 if (m[num] == 0)
//                 {
//                     m.erase(num);
//                 }
//             }
//         }
//         return intersection;
//     }
// };

// Double pointer solution O(mlogm + nlogn) space using O(min(m, n))
// class Solution
// {
// public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int length1 = nums1.size(), length2 = nums2.size();
//         vector<int> intersection;
//         int index1 = 0, index2 = 0;
//         while (index1 < length1 && index2 < length2)
//         {
//             if (nums1[index1] < nums2[index2])
//             {
//                 index1++;
//             }
//             else if (nums1[index1] > nums2[index2])
//             {
//                 index2++;
//             }
//             else
//             {
//                 intersection.push_back(nums1[index1]);
//                 index1++;
//                 index2++;
//             }
//         }
//         return intersection;
//     }
// };