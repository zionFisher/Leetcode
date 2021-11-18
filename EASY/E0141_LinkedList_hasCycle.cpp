// https://leetcode-cn.com/problems/linked-list-cycle/
#include "LinkedList.hpp"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// hash set
// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         unordered_set<ListNode *> seen;
//         while (head != nullptr)
//         {
//             if (seen.count(head))
//             {
//                 return true;
//             }
//             seen.insert(head);
//             head = head->next;
//         }
//         return false;
//     }
// };