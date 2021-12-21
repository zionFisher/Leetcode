//
#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;
        for (auto &it : s)
        {
            if (it == ' ')
                res += "%20";
            else
                res += it;
        }
        return res;
    }
};