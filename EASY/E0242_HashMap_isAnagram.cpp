// https://leetcode-cn.com/problems/valid-anagram/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> map;
        for (auto x : s)
        {
            map[x]++;
        }
        for (auto x : t)
        {
            map[x]--;
            /*
            if(map[x] < 0)
            {
                return false;
            }
            */
        }
        for (auto x : map)
        {
            if (x.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         if (s.length() != t.length())
//         {
//             return false;
//         }
//         vector<int> table(26, 0);
//         for (auto &ch : s)
//         {
//             table[ch - 'a']++;
//         }
//         for (auto &ch : t)
//         {
//             table[ch - 'a']--;
//             if (table[ch - 'a'] < 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };