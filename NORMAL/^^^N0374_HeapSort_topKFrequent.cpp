// https://leetcode-cn.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (auto &it : nums)
            map[it]++;

        auto compare = [](pair<int, int> &lhs, pair<int, int> &rhs)
        { return lhs.second < rhs.second; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
            pq(compare);

        for (auto &it : map)
            pq.push(it);

        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            res.emplace_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};