// https://leetcode-cn.com/problems/reverse-linked-list/
#include "LinkedList.hpp"

// iterate
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// recurse
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head || !head->next)
//         {
//             return head;
//         }
//         ListNode *newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }
// };

// bad solution
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head)
//         {
//             return nullptr;
//         }
//         else if (!head->next)
//         {
//             return head;
//         }

//         ListNode *pre = head;
//         ListNode *node = head;
//         while (node->next != nullptr)
//         {
//             pre = node;
//             node = node->next;
//         }
//         if (pre != node)
//         {
//             pre->next = nullptr;
//             node->next = pre;
//         }
//         reverseList(head);
//         return node;
//     }
// };