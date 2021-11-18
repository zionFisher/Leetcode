// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void percolate(vector<int> &nums, int father, int size)
    {
        int largerEle = father;
        int lChild = father * 2 + 1;
        int rChild = father * 2 + 2;
        if (lChild < size && nums[lChild] > nums[father])
        {
            largerEle = lChild;
        }
        if (rChild < size && nums[rChild] > nums[father])
        {
            largerEle = rChild;
        }
        if (largerEle != father) // 递归上滤
        {
            swap(nums[father], nums[largerEle]);
            percolate(nums, largerEle, size);
        }
    }

    void buildBigHeap(vector<int> &nums)
    {
        for (int i = nums.size() / 2; i >= 0; i--)
        {
            percolate(nums, i, nums.size());
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// HeapSort // 大顶堆，实际上利用小顶堆是更好的选择
// class Solution
// {
// public:
//     void maxHeapify(vector<int> &a, int i, int heapSize)
//     {
//         int l = i * 2 + 1, r = i * 2 + 2, largest = i;
//         if (l < heapSize && a[l] > a[largest])
//         {
//             largest = l;
//         }
//         if (r < heapSize && a[r] > a[largest])
//         {
//             largest = r;
//         }
//         if (largest != i)
//         {
//             swap(a[i], a[largest]);
//             maxHeapify(a, largest, heapSize);
//         }
//     }

//     void buildMaxHeap(vector<int> &a, int heapSize)
//     { // 建堆，对每个内部节点进行下滤
//         for (int i = heapSize / 2; i >= 0; --i)
//         {
//             maxHeapify(a, i, heapSize);
//         }
//     }

//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int heapSize = nums.size();
//         buildMaxHeap(nums, heapSize);
//         for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i)
//         { // 通过删除堆顶节点来获得第 k 大元素
//             swap(nums[0], nums[i]);
//             --heapSize;
//             maxHeapify(nums, 0, heapSize);
//         }
//         return nums[0];
//     }
// };
