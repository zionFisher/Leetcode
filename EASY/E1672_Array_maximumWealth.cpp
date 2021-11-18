// https://leetcode-cn.com/problems/richest-customer-wealth/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int target = 0;
        int sum = 0;
        for (int i = 0; i < accounts.size(); ++i)
        {
            for (int j = 0; j < accounts[i].size(); ++j)
                sum += accounts[i][j];
            if (sum > target)
                target = sum;
            sum = 0;
        }
        return target;
    }
};