// https://leetcode-cn.com/problems/merge-two-sorted-lists/
#include "LinkedList.hpp"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        else if (!l1 && l2)
        {
            return l2;
        }
        else if (!l2 && l1)
        {
            return l1;
        }
        if (l1->val > l2->val) // ensure the sequence
        {
            ListNode *node = l1;
            l1 = l2;
            l2 = node;
        }

        ListNode *l1Node = l1;
        ListNode *l1Next = l1Node->next;
        ListNode *l2Next = l2;
        while (l1Next || l2Next)
        {
            if ((l1Next && !l2Next) || (l1Next && l1Next->val < l2Next->val))
            {
                l1Node->next = l1Next;
                l1Node = l1Next;
                l1Next = l1Next->next;
            }
            else if (l2Next)
            {
                l1Node->next = l2Next;
                l1Node = l2Next;
                l2Next = l2Next->next;
            }
        }
        return l1;
    }
};

// recurse
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == nullptr)
//         {
//             return l2;
//         }
//         else if (l2 == nullptr)
//         {
//             return l1;
//         }
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

// iterate
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         ListNode *preHead = new ListNode(-1);

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

//         // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
//         prev->next = l1 == nullptr ? l2 : l1;

//         return preHead->next;
//     }
// };