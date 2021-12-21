// https://leetcode-cn.com/problems/day-of-the-year/
#include <string>
using namespace std;

class Solution
{
private:
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    int dayOfYear(string date)
    {
        string year, month, day;
        int iyear, imonth, iday;
        year = date.substr(0, 4);
        month = date.substr(5, 2);
        day = date.substr(8, 2);
        iyear = stoi(year);
        imonth = stoi(month);
        iday = stoi(day);

        if (iyear == 2000)
            days[1]++;
        else if (iyear % 4 == 0)
            days[1]++;

        int res = 0;
        for (int i = 0; i < imonth - 1; ++i)
            res += days[i];
        res += iday;

        return res;
    }
};