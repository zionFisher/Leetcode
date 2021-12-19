// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
#include <stack>
#include <vector>
#include "LinkedList.hpp"
using namespace std;

class Solution
{
private:
    stack<int> stack;
    vector<int> vec;

public:
    vector<int> reversePrint(ListNode* head)
    {
        ListNode* node = head;
        while (node != nullptr)
        {
            stack.push(node->val);
            node = node->next;
        }
        while (!stack.empty())
        {
            int val = stack.top();
            stack.pop();
            vec.push_back(val);
        }
        return vec;
    }
};