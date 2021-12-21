// Quick Sort.
#include <vector>
#include <iostream>

void QuickSort(std::vector<int> &arr, bool lowerToUpper = true);
void QuickSort(std::vector<int> &arr, int left, int right, bool lowerToUpper = true);
int GeneratePivot(std::vector<int> &arr, int left, int right, bool lowerToUpper = true);

void QuickSort(std::vector<int> &arr, bool lowerToUpper)
{
    QuickSort(arr, 0, arr.size() - 1, lowerToUpper);
}

void QuickSort(std::vector<int> &arr, int left, int right, bool lowerToUpper)
{
    if (left >= right)
        return;
    int pivot = GeneratePivot(arr, left, right, lowerToUpper);
    QuickSort(arr, left, pivot - 1, lowerToUpper);
    QuickSort(arr, pivot + 1, right, lowerToUpper);
}

int GeneratePivot(std::vector<int> &arr, int left, int right, bool lowerToUpper)
{
    if (left >= right)
        return left;
    int pivotOriginPos = left;
    int pivotVal = arr[pivotOriginPos];
    while (left < right)
    {
        while ((lowerToUpper && arr[right] >= pivotVal && left < right) ||
              (!lowerToUpper && arr[right] <= pivotVal && left < right))
            right--;
        while ((lowerToUpper && arr[left] <= pivotVal && left < right) ||
              (!lowerToUpper && arr[left] >= pivotVal && left < right))
            left++;
        if (left < right)
            std::swap(arr[left], arr[right]);
    }
    std::swap(arr[pivotOriginPos], arr[left]);
    return left; // pivot == left == right
}