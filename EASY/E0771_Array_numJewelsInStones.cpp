// https://leetcode-cn.com/problems/jewels-and-stones/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        // int sum = 0;
        // for (int i = 0; i < stones.size(); ++i)
        // {
        //     for (int j = 0; j < jewels.size(); ++j)
        //     {
        //         if (jewels[j] == stones[i])
        //             sum++;
        //     }
        // }
        // return sum;
        int count = 0;
        unordered_set<char> hashSet;
        for (int i = 0; i < jewels.length(); ++i)
        {
            hashSet.insert(jewels[i]);
        }
        for (int i = 0; i < stones.length(); ++i)
        {
            if (hashSet.count(stones[i]))
                count++;
        }
        return count;
    }
};

/* Solution2:
 * class Solution {
 * public:
 *     int numJewelsInStones(string jewels, string stones) {
 *         int jewelsCount = 0;
 *         unordered_set<char> jewelsSet;
 *         int jewelsLength = jewels.length(), stonesLength = stones.length();
 *         for (int i = 0; i < jewelsLength; i++) {
 *             char jewel = jewels[i];
 *             jewelsSet.insert(jewel);
 *         }
 *         for (int i = 0; i < stonesLength; i++) {
 *             char stone = stones[i];
 *             if (jewelsSet.count(stone)) {
 *                 jewelsCount++;
 *             }
 *         }
 *         return jewelsCount;
 *     }
 * };
*/