// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
#include <stack>
using namespace std;

class CQueue
{
private:
    stack<int> first;
    stack<int> last;

public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        first.push(value);
    }

    int deleteHead()
    {
        if (!last.empty())
        {
            int res = last.top();
            last.pop();
            return res;
        }

        while (!first.empty())
        {
            last.push(first.top());
            first.pop();
        }

        if (!last.empty())
        {
            int res = last.top();
            last.pop();
            return res;
        }

        return -1;
    }
};