// https://leetcode-cn.com/problems/design-hashmap/
#include <list>
#include <vector>
using namespace std;

class MyHashMap
{
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;

    static int hash(int key) { return key % base; }

public:
    MyHashMap() : data(base) {}

    void put(int key, int value)
    {
        int h = hash(key);
        for (auto &it : data[h])
        {
            if (it.first == key)
            {
                it.second = value;
                return;
            }
        }
        data[h].emplace_back(key, value);
    }

    int get(int key)
    {
        int h = hash(key);
        for (auto &it : data[h])
        {
            if (it.first == key)
            {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(), end = data[h].end(); it != end; it++)
        {
            if ((*it).first == key)
            {
                data[h].erase(it);
                return;
            }
        }
    }
};