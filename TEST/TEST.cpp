#include "QuickSort.hpp"
#include <iostream>
using namespace std;

int main()
{
    vector<int> arr = {5, 5, 7, 6, 4, 1, 0, 2, 5, 5, 8, 12, 34, 2, 5, 235, 235, 5, 54, -1, -41, -54, -2};
    QuickSort(arr, false);
    for (auto &it : arr)
    {
        std::cout << it << " ";
    }
}