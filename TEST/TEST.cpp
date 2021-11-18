#include <iostream>
#include <algorithm>     // sort()
#include <vector>        // Array Implementation based on Array
#include <unordered_map> // Map Implementation based on HashSet
#include <unordered_set> // Set Implementation based on HashSet
using namespace std;

int main()
{
    int n;
    bool flag = true;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    float cur = 100;
    if (arr[0] > arr[1])
        cur = arr[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1] && i != n - 2)
        {
            cur *= (arr[i] / 100.0f);
            flag = false;
        }
        else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1] && i != n - 2)
        {
            cur /= (arr[i] / 100.0f);
            flag = true;
        }
    }
    if (arr[n - 2] < arr[n - 1])
    {
        cur *= (arr[n - 1] / 100.0f);
        flag = false;
    }
    else if (arr[n - 2] > arr[n - 1])
    {
        cur /= (arr[n - 1] / 100.0f);
        flag = true;
    }
    if (!flag)
    {
        cur /= (arr[n - 1] / 100.0f);
    }
    int res = cur;
    cout << res;
}