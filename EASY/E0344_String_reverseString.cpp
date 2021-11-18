// https://leetcode-cn.com/problems/reverse-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int size = s.size();
        for (int count = 0; count < (size / 2); count++)
        {
            swap(s[count], s[size - count - 1]);
        }
    }
};