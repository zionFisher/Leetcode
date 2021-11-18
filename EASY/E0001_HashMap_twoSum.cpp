// https://leetcode-cn.com/problems/two-sum/
#include <iostream>
#include <unordered_map> // HashSet
#include <vector>        // Array
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashTable;

        for (int i = 0; i < nums.size(); ++i)
        {
            hashTable.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = hashTable.find(target - nums[i]);

            /* notice that if target = someValidValue, iter->first = target / 2, 
             * then iter->second == i, return invalid result **{iter->second, iter->second}**
             * e.g nums = {3, 2, 4}, target = 6
             * then if dont judge the condition **iter->second != i**
             * will return {0, 0}
             */
            if (iter != hashTable.end() && iter->second != i)
            {
                return {iter->second, i};
            }
        }
        return {};
    }
};

/* better solution
 * vector<int> twoSum(vector<int>& nums, int target)
 * {
 *     unordered_map<int, int> hashtable;
 *     for (int i = 0; i < nums.size(); ++i)
 *     {
 *         auto it = hashtable.find(target - nums[i]);
 *         if (it != hashtable.end())
 *         {
 *             return {it->second, i};
 *         }
 *         hashtable[nums[i]] = i;
 *     }
 *     return {};
 * }
 */