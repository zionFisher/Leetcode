// https://leetcode-cn.com/problems/first-bad-version/
// assume the API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (isBadVersion(1))
        {
            return 1;
        }
        return firstBadVersion(1, n);
    }
    int firstBadVersion(long low, long high)
    {
        long mid = (low + high) / 2 ;
        if (!isBadVersion(mid) && isBadVersion(mid + 1))
        {
            return mid + 1;
        }
        else if (!isBadVersion(mid))
        {
            return firstBadVersion(mid, high);
        }
        else
        {
            return firstBadVersion(low, mid);
        }
        return -1;
    }
};