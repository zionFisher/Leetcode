// https://leetcode-cn.com/problems/roman-to-integer/
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = map[s[s.size() - 1]];

        for (int i = s.size() - 2; i >= 0; --i)
            if (map[s[i]] < map[s[i + 1]])
                result -= map[s[i]];
            else
                result += map[s[i]];

        return result;
    }
};