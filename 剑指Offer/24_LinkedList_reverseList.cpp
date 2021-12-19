// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
#include "LinkedList.hpp"

class Solution
{
private:
    ListNode* preNode;

public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *preNode = nullptr;
        ListNode *curNode = head;
        ListNode *nextNode = head ? head->next : nullptr;

        while (curNode != nullptr)
        {
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
            if (nextNode)
                nextNode = nextNode->next;
        }

        return preNode;
    }
};