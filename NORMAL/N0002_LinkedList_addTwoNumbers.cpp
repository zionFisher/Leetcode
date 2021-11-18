// https://leetcode-cn.com/problems/add-two-numbers/
#include <LinkedList.hpp>

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = l1->val + l2->val, carry = sum > 9 ? 1 : 0;
        ListNode *it1 = l1->next, *it2 = l2->next,
                 *res = new ListNode(sum % 10), *itRes = res, *itPre = nullptr;

        while (it1 or it2 or carry)
        {
            int val1 = it1 == nullptr ? 0 : it1->val;
            int val2 = it2 == nullptr ? 0 : it2->val;
            sum = val1 + val2 + carry;
            carry = sum / 10;

            itPre = itRes;
            itRes = new ListNode(sum % 10);
            itPre->next = itRes;

            it1 = it1 == nullptr ? nullptr : it1->next;
            it2 = it2 == nullptr ? nullptr : it2->next;
        }

        return res;
    }
};