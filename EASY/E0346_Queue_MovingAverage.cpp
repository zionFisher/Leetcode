// https://leetcode-cn.com/problems/moving-average-from-data-stream/
#include <queue>
using namespace std;

class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        _size = size;
    }
    
    double next(int val)
    {
        if (que.size() == _size)
        {
            sum -= que.front();
            que.pop();
        }

        que.push(val);
        sum += val;

        return sum / que.size();
    }

private:
    queue<int> que;
    int _size;
    double sum = 0.0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */