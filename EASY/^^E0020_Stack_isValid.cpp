// https://leetcode-cn.com/problems/valid-parentheses/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;

        stack<char> stack;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else if (!stack.empty())
            {
                auto t = stack.top();
                stack.pop();
                if (t == '(' && c == ')' || t == '{' && c == '}' || t == '[' && c == ']')
                    ;
                else
                    return false;
            }
            else
            {
                stack.pop();
                return false;
            }
        }
        return stack.empty();
    }
};

// common solution
// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         int n = s.size();
//         if (n % 2 == 1)
//         {
//             return false;
//         }
//
//         unordered_map<char, char> pairs = {
//             {')', '('},
//             {']', '['},
//             {'}', '{'}};
//         stack<char> stk;
//         for (char ch : s)
//         {
//             if (pairs.count(ch))
//             {
//                 if (stk.empty() || stk.top() != pairs[ch])
//                 {
//                     return false;
//                 }
//                 stk.pop();
//             }
//             else
//             {
//                 stk.push(ch);
//             }
//         }
//         return stk.empty();
//     }
// };

// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         unordered_map<char, int> m{{'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}};
//         stack<char> st;
//         bool istrue = true;
//         for (char c : s)
//         {
//             int flag = m[c];
//             if (flag >= 1 && flag <= 3)
//                 st.push(c);
//             else if (!st.empty() && m[st.top()] == flag - 3)
//                 st.pop();
//             else
//             {
//                 istrue = false;
//                 break;
//             }
//         }
//         if (!st.empty())
//             istrue = false;
//         return istrue;
//     }
// };