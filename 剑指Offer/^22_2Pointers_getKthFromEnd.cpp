// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
#include "SuperSet.hpp"

// Traverse nodes once only
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && k > 0)
        {
            fast = fast->next;
            k--;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

// Traverse nodes twice
// class Solution
// {
// public:
//     ListNode *getKthFromEnd(ListNode *head, int k)
//     {
//         if (head == nullptr)
//             return nullptr;
//
//         int length = 0;
//         ListNode *ptr = head;
//         while (ptr != nullptr)
//         {
//             length++;
//             ptr = ptr->next;
//         }
//
//         ptr = head;
//         while (ptr != nullptr)
//         {
//             length--;
//             if (length == k - 1)
//                 return ptr;
//             ptr = ptr->next;
//         }
//
//         return nullptr;
//     }
// };