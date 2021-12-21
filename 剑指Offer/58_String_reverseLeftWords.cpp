// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
#include <string>
using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n) { return s.substr(n) + s.substr(0, n); }
};

// class Solution
// {
// public:
//     string reverseLeftWords(string s, int n)
//     {
//         string res;
//         int size = s.size();
//         for (int i = n; i < n + size; ++i)
//             res += s[i % size];
//         return res;
//     }
// };