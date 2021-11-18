// https://leetcode-cn.com/problems/min-stack/
#include <climits>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop()
    {
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

// less space overhead/cost solution, using tuple
// class MinStack
// {
// public:
//     /** initialize your data structure here. */
//     MinStack()
//     {
//     }
//
//     void push(int x)
//     {
//         if (st.size() == 0)
//         {
//             st.push({x, x});
//         }
//         else
//         {
//             st.push({x, min(x, st.top().second)});
//         }
//     }
//
//     void pop()
//     {
//         st.pop();
//     }
//
//     int top()
//     {
//         return st.top().first;
//     }
//
//     int getMin()
//     {
//         return st.top().second;
//     }
//
// private:
//     stack<pair<int, int>> st;
// };