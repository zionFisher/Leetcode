// https://leetcode-cn.com/problems/sort-colors/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int count[3] = {0};
        for (int x : nums)
            switch(x)
            {
                case 2:
                    count[2]++;
                    break;
                case 1:
                    count[1]++;
                    break;
                case 0:
                    count[0]++;
                    break;
                default:
                    return;
            }
        int index = 0;
        for (int j = 0; j < count[0]; j++)
            nums[index++] = 0;
        for (int j = 0; j < count[1]; j++)
            nums[index++] = 1;
        for (int j = 0; j < count[2]; j++)
            nums[index++] = 2;
    }
};

/*单指针法
 *class Solution {
 *public:
 *    void sortColors(vector<int>& nums) {
 *        int n = nums.size();
 *        int ptr = 0;
 *        for (int i = 0; i < n; ++i) {
 *            if (nums[i] == 0) {
 *                swap(nums[i], nums[ptr]);
 *                ++ptr;
 *            }
 *        }
 *        for (int i = ptr; i < n; ++i) {
 *            if (nums[i] == 1) {
 *                swap(nums[i], nums[ptr]);
 *                ++ptr;
 *            }
 *        }
 *    }
 *};
 */

/*双指针法，使用两个指针分别交换0和1，但需要注意的是，交换1无需多考虑；
 *但交换0时为了防止把1交换出去，要在p0 < p1的情况下在额外进行一次交换
 *class Solution {
 *public:
 *    void sortColors(vector<int>& nums) {
 *        int n = nums.size();
 *        int p0 = 0, p1 = 0;
 *        for (int i = 0; i < n; ++i) {
 *            if (nums[i] == 1) {
 *                swap(nums[i], nums[p1]);
 *                ++p1;
 *            } else if (nums[i] == 0) {
 *                swap(nums[i], nums[p0]);
 *                if (p0 < p1) {
 *                    swap(nums[i], nums[p1]);
 *                }
 *                ++p0;
 *                ++p1;
 *            }
 *        }
 *    }
 *};
 */

/*双指针法2，使用两个指针分别交换0和2，交换2的指针p2从右向左移动
 *class Solution {
 *public:
 *    void sortColors(vector<int>& nums) {
 *        int n = nums.size();
 *        int p0 = 0, p2 = n - 1;
 *        for (int i = 0; i <= p2; ++i) {
 *            while (i <= p2 && nums[i] == 2) {
 *                swap(nums[i], nums[p2]);
 *                --p2;
 *            }
 *            if (nums[i] == 0) {
 *                swap(nums[i], nums[p0]);
 *                ++p0;
 *            }
 *        }
 *    }
 *};
 */