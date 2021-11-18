// https://leetcode-cn.com/problems/plus-one/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int size = digits.size();
        for(int count = size - 1; count >= 0; count--)
        {
            if(digits[count] == 9)
            {
                digits[count] = 0;
            }
            else
            {
                digits[count]++;
                return digits;
            }
        }
        vector<int> result(size + 1,0);
        result[0] = 1;
        return result;
    }
};