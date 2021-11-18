// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
#include "LinkedList.hpp"
#include <cmath>
using namespace std;

// offset solution
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        int lengthA = 0, lengthB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != nullptr)
        {
            lengthA++;
            ptrA = ptrA->next;
        }
        while (ptrB != nullptr)
        {
            lengthB++;
            ptrB = ptrB->next;
        }
        int offset = abs(lengthA - lengthB);
        ptrA = headA;
        ptrB = headB;
        for (int i = 0; i < offset; ++i)
        {
            if (lengthA > lengthB)
                ptrA = ptrA->next;
            else
                ptrB = ptrB->next;
        }
        while (ptrA != ptrB)
        {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return ptrA;
    }
};

// DoublePtr solution
// class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         if (headA == nullptr || headB == nullptr)
//             return nullptr;
//
//         ListNode *ptrA = headA, *ptrB = headB;
//         while (ptrA != ptrB)
//         {
//             ptrA = ptrA == nullptr ? headB : ptrA->next;
//             ptrB = ptrB == nullptr ? headA : ptrB->next;
//         }
//         return ptrA;
//
//         return nullptr;
//     }
// };

// HashMap solution
// class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         if (headA == nullptr || headB == nullptr)
//             return nullptr;
//
//         unordered_set<ListNode *> set;
//         ListNode *temp = headA;
//         while (temp != nullptr)
//         {
//             set.insert(temp);
//             temp = temp->next;
//         }
//         temp = headB;
//         while (temp != nullptr)
//         {
//             if (set.count(temp))
//                 return temp;
//             temp = temp->next;
//         }
//         return nullptr;
//     }
// };