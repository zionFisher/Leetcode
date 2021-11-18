// https://leetcode-cn.com/problems/palindrome-linked-list/
#include "LinkedList.hpp"
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vec;
        ListNode *node = head;
        while (node)
        {
            vec.push_back(node->val);
            node = node->next;
        }
        int size = vec.size();
        for (int i = 0; i < size / 2; ++i)
        {
            if (vec[i] != vec[size - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

// double pointer (reverse frist then judge then reverse back)
// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         if (head == nullptr)
//         {
//             return true;
//         }
//
//         // 找到前半部分链表的尾节点并反转后半部分链表
//         ListNode *firstHalfEnd = endOfFirstHalf(head);
//         ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
//
//         // 判断是否回文
//         ListNode *p1 = head;
//         ListNode *p2 = secondHalfStart;
//         bool result = true;
//         while (result && p2 != nullptr)
//         {
//             if (p1->val != p2->val)
//             {
//                 result = false;
//             }
//             p1 = p1->next;
//             p2 = p2->next;
//         }
//
//         // 还原链表并返回结果
//         firstHalfEnd->next = reverseList(secondHalfStart);
//         return result;
//     }
//
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         ListNode *curr = head;
//         while (curr != nullptr)
//         {
//             ListNode *nextTemp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextTemp;
//         }
//         return prev;
//     }
//
//     ListNode *endOfFirstHalf(ListNode *head)
//     {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         while (fast->next != nullptr && fast->next->next != nullptr)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };

// recurse
// class Solution
// {
//     ListNode *frontPointer;
//
// public:
//     bool recursivelyCheck(ListNode *currentNode)
//     {
//         if (currentNode != nullptr)
//         {
//             if (!recursivelyCheck(currentNode->next))
//             {
//                 return false;
//             }
//             if (currentNode->val != frontPointer->val)
//             {
//                 return false;
//             }
//             frontPointer = frontPointer->next;
//         }
//         return true;
//     }
//
//     bool isPalindrome(ListNode *head)
//     {
//         frontPointer = head;
//         return recursivelyCheck(head);
//     }
// };