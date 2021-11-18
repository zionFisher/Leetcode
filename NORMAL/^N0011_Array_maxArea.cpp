// https://leetcode-cn.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int head = 0, tail = height.size() - 1;
        int area = 0;
        while (head < tail)
        {
            int s = min(height[head], height[tail]);
            if (s * (tail - head) > area)
            {
                area = s * (tail - head);
            }
            if (height[head] < height[tail])
            {
                head++;
            }
            else
            {
                tail--;
            }
        }
        return area;
    }
};