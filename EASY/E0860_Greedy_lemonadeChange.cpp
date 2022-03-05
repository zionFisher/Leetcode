// https://leetcode-cn.com/problems/lemonade-change/
#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        bool flag = true;
        int c5 = 0, c10 = 0;

        for (auto &it : bills)
        {
            if (it == 5)
                c5++;
            else if (it == 10)
            {
                if (c5 > 0)
                {
                    c5--;
                    c10++;
                }
                else
                    flag = false;
            }
            else if (it == 20)
            {
                if (c10 > 0 and c5 > 0)
                {
                    c10--;
                    c5--;
                }
                else if (c5 > 2)
                    c5 -= 3;
                else
                    flag = false;
            }
        }

        return flag;
    }
};