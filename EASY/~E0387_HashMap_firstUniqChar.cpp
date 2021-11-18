// https://leetcode-cn.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> map;
        for (auto x : s)
        {
            if (map.find(x) == map.end())
            {
                map[x] = 1;
            }
            else
            {
                map[x] = 2;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// public int firstUniqChar(String s)
// {
//     int[] arr = new int[26];
//     int n = s.length();
//     for (int i = 0; i < n; i++)
//     {
//         arr[s.charAt(i) - 'a']++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[s.charAt(i) - 'a'] == 1)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// class Solution
// {
// public:
//     int firstUniqChar(string s)
//     {
//         unordered_map<int, int> position;
//         int n = s.size();
//         for (int i = 0; i < n; ++i)
//         {
//             if (position.count(s[i]))
//             {
//                 position[s[i]] = -1;
//             }
//             else
//             {
//                 position[s[i]] = i;
//             }
//         }
//         int first = n;
//         for (auto [_, pos] : position)
//         {
//             if (pos != -1 && pos < first)
//             {
//                 first = pos;
//             }
//         }
//         if (first == n)
//         {
//             first = -1;
//         }
//         return first;
//     }
// };