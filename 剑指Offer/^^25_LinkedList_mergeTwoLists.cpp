// https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0), *newList = head, *list1 = l1, *list2 = l2;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                newList->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                newList->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            newList = newList->next;
        }

        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 != nullptr)
            {
                newList->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                newList->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            newList = newList->next;
        }

        return head->next;
    }
};

// Local solution, but it can cause problems that break the original data structure.
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         ListNode *preHead = new ListNode(-1);
//
//         ListNode *prev = preHead;
//         while (l1 != nullptr && l2 != nullptr)
//         {
//             if (l1->val < l2->val)
//             {
//                 prev->next = l1;
//                 l1 = l1->next;
//             }
//             else
//             {
//                 prev->next = l2;
//                 l2 = l2->next;
//             }
//             prev = prev->next;
//         }
//
//         prev->next = l1 == nullptr ? l2 : l1;
//
//         return preHead->next;
//     }
// };

// recursion
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == nullptr)
//             return l2;
//         else if (l2 == nullptr)
//             return l1;
//         else if (l1->val < l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else
//         {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };