// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == headB)
            return headA;

        unordered_set<ListNode *> nodes;
        ListNode *node = headA;
        while (node != nullptr)
        {
            nodes.insert(node);
            node = node->next;
        }

        node = headB;
        while (node != nullptr)
        {
            if (nodes.count(node))
                return node;
            node = node->next;
        }

        return nullptr;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};