// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
#include <stack>
#include <climits>
using namespace std;

class MinStack
{
private:
    stack<int> outside;
    stack<int> inside;

public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        outside.push(x);
        if (inside.empty() || inside.top() >= x) // equality means multiple same minima
            inside.push(x);
    }

    void pop()
    {
        if (outside.top() == inside.top())
            inside.pop();
        outside.pop();
    }

    int top()
    {
        return outside.top();
    }

    int min()
    {
        return inside.top();
    }
};

// class MinStack
// {
// private:
//     stack<pair<int, int>> stack;
//     int curMin = INT_MAX;
//
// public:
//     /** initialize your data structure here. */
//     MinStack()
//     {
//
//     }
//
//     void push(int x)
//     {
//         if (x < curMin)
//             curMin = x;
//         stack.push(pair(x, curMin));
//     }
//
//     void pop()
//     {
//         stack.pop();
//         if (stack.empty())
//             curMin = INT_MAX;
//         else
//             curMin = stack.top().second;
//     }
//
//     int top()
//     {
//         return stack.top().first;
//     }
//
//     int min()
//     {
//         return stack.top().second;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */