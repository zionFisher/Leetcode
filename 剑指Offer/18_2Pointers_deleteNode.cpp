// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    ListNode* deleteNode(ListNode* head, int val)
    {
        if (head == nullptr)
            return nullptr;
        if (head->val == val)
            return head->next;

        ListNode *front = head, *back = head->next;

        while (back != nullptr)
        {
            if (back->val == val)
            {
                front->next = back->next;
                return head;
            }
            front = back;
            back = back->next;
        }

        return head;
    }
};