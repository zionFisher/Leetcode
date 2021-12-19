// https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
private:
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head)
    {
        Node* node = head;
        for (; node; node = node->next)
        {
            Node* newNode = new Node(node->val);
            map[node] = newNode;
        }

        node = head;
        for (; node; node = node->next)
        {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
        }

        return map[head];
    }
};

// class Solution
// {
// public:
//     unordered_map<Node *, Node *> cachedNode;

//     Node *copyRandomList(Node *head)
//     {
//         if (head == nullptr)
//         {
//             return nullptr;
//         }
//         if (!cachedNode.count(head))
//         {
//             Node *headNew = new Node(head->val);
//             cachedNode[head] = headNew;
//             headNew->next = copyRandomList(head->next);
//             headNew->random = copyRandomList(head->random);
//         }
//         return cachedNode[head];
//     }
// };

// class Solution
// {
// public:
//     Node* copyRandomList(Node* head)
//     {
//         if (head == nullptr)
//         {
//             return nullptr;
//         }
//         for (Node* node = head; node != nullptr; node = node->next->next)
//         {
//             Node* nodeNew = new Node(node->val);
//             nodeNew->next = node->next;
//             node->next = nodeNew;
//         }
//         for (Node* node = head; node != nullptr; node = node->next->next)
//         {
//             Node* nodeNew = node->next;
//             nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
//         }
//         Node* headNew = head->next;
//         for (Node* node = head; node != nullptr; node = node->next)
//         {
//             Node* nodeNew = node->next;
//             node->next = node->next->next;
//             nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
//         }
//         return headNew;
//     }
// };