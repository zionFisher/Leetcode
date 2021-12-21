// Binary Search
#include <vector>

int BinarySearch(std::vector<int> &arr, int target);
int BinarySearch(std::vector<int> &arr, int left, int right, int target);

int BinarySearch(std::vector<int> &arr, int target)
{
    return BinarySearch(arr, 0, arr.size() - 1, target);
}

int BinarySearch(std::vector<int> &arr, int left, int right, int target)
{
    if (left > right)
        return -1;
    int pivot = (left + right) / 2;
    if (arr[pivot] == target)
        return pivot;
    else if ((arr[pivot]) > target)
        return BinarySearch(arr, left, pivot - 1, target);
    else
        return BinarySearch(arr, pivot + 1, right, target);
}