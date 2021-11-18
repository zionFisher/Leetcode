// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
#include "LinkedList.hpp"
#include <iostream>

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *nnext = node->next->next;
        delete node->next;
        node->next = nnext;
    }
};