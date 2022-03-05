// https://leetcode-cn.com/problems/smallest-k-lcci/
#include <queue>
using namespace std;

// heap sort using priority_queue
class Solution
{
public:
    vector<int> smallestK(vector<int> &arr, int k)
    {
        vector<int> vec(k, 0);
        if (k == 0)
            return vec;

        priority_queue<int> Q;
        for (int i = 0; i < k; ++i)
            Q.push(arr[i]);

        for (int i = k; i < (int)arr.size(); ++i)
        {
            if (Q.top() > arr[i])
            {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i)
        {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

// build heap yourself
// class Solution
// {
// public:
//     vector<int> smallestK(vector<int> &arr, int k)
//     {
//         buildHeap(arr);
//         return vector<int>(arr.begin(), arr.begin() + k);
//     }
//
//     void buildHeap(vector<int> &arr)
//     {
//         for (int i = arr.size() / 2 - 1; i > -1; i--)
//             maxHeap(arr, i, arr.size());
//
//         for (int i = arr.size() - 1; i > 0; i--)
//         {
//             swap(arr[i], arr[0]);
//             maxHeap(arr, 0, i);
//         }
//     }
//
//     void maxHeap(vector<int> &arr, int start, int end)
//     {
//         int father = start;
//         int son = father * 2 + 1;
//
//         while (son < end)
//         {
//             if (son + 1 < end and arr[son] < arr[son + 1])
//                 son++;
//
//             if (arr[father] < arr[son])
//             {
//                 swap(arr[father], arr[son]);
//                 father = son;
//                 son = father * 2 + 1;
//             }
//             else
//                 return;
//         }
//     }
// };

// #include <algorithm>
// quick sort
// class Solution
// {
// public:
//     vector<int> smallestK(vector<int> &arr, int k)
//     {
//         vector<int> vec(k, 0);
//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < k; ++i)
//         {
//             vec[i] = arr[i];
//         }
//         return vec;
//     }
// };