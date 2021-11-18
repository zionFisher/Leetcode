// https://leetcode-cn.com/problems/remove-linked-list-elements/
#include "LinkedList.hpp"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *cur = head, *pre = nullptr, *res = head;
        while (cur)
        {
            if (cur->val == val)
                if (!pre)
                    res = cur->next;
                else
                    pre->next = cur->next;
            else
                pre = cur;
            cur = cur->next;
        }
        return res;
    }
};

// recurse
// class Solution
// {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         if (head == nullptr)
//         {
//             return head;
//         }
//         head->next = removeElements(head->next, val);
//         return head->val == val ? head->next : head;
//     }
// };

// iterate
// class Solution
// {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         struct ListNode *dummyHead = new ListNode(0, head);
//         struct ListNode *temp = dummyHead;
//         while (temp->next != NULL)
//         {
//             if (temp->next->val == val)
//             {
//                 temp->next = temp->next->next;
//             }
//             else
//             {
//                 temp = temp->next;
//             }
//         }
//         return dummyHead->next;
//     }
// };