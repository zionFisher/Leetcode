// https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        bool flag = false;
        bool positive = true;
        int counter = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && !flag)
            {
            }
            else if ((s[i] == '+' || s[i] == '-') && !flag)
            {
                positive = s[i] == '+' ? true : false;
                flag = true;
            }
            else if (s[i] <= '9' && s[i] >= '0')
            {
                s[counter++] = s[i];
                flag = true;
            }
            else if (counter == 0)
            {
                return 0;
            }
            else
            {
                break;
            }
        }

        flag = false;
        int res = 0; // it is a better solution using long

        for (int i = counter - 1; i >= 0; --i)
        {
            if (res + pow(10, counter - i - 1) * (s[i] - '0') > INT_MAX)
            {
                flag = true;
                res = INT_MAX;
            }
            else
            {
                res += pow(10, counter - i - 1) * (s[i] - '0');
            }
        }

        if (res == INT_MAX && positive == false && flag)
        {
            res = INT_MIN;
        }
        else
        {
            res = positive == true ? res : -res;
        }

        return res;
    }
};