// https://leetcode-cn.com/problems/contiguous-array/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int nums0 = nums[0] == 0 ? 1 : -1;
        unordered_map<int, int> map = {{0, -1}, {nums0, 0}};
        int size = nums.size();
        int offset[size];
        offset[0] = nums0;
        int length = 0;

        for (int i = 1; i < size; ++i)
        {
            offset[i] = offset[i - 1] + (nums[i] == 0 ? 1 : -1);
            if (map.count(offset[i]))
            {
                if ((i - map[offset[i]]) > length)
                    length = i - map[offset[i]];
            }
            else
                map[offset[i]] = i;
        }

        return length;
    }
};

// better solution
// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {
//         int maxLength = 0;
//         unordered_map<int, int> mp;
//         int counter = 0;
//         mp[counter] = -1;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             int num = nums[i];
//             if (num == 1)
//             {
//                 counter++;
//             }
//             else
//             {
//                 counter--;
//             }
//             if (mp.count(counter))
//             {
//                 int prevIndex = mp[counter];
//                 maxLength = max(maxLength, i - prevIndex);
//             }
//             else
//             {
//                 mp[counter] = i;
//             }
//         }
//         return maxLength;
//     }
// };

// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {
//         unordered_map<int, int> Map;
//         int sum = 0, ans = 0;

//         Map[0] = -1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i] ? 1 : -1;
//             auto p = Map.find(sum);
//             if (p != Map.end())
//                 ans = max(ans, i - p->second);
//             else
//                 Map[sum] = i;
//         }
//         return ans;
//     }
// };