// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void swap(string &s, int x, int y)
    {
        char m = s[x];
        s[x] = s[y];
        s[y] = m;
    }
    string reverseVowels(string s)
    {
        vector<int> vec;
        vec.clear();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'o' || s[i] == 'O' || s[i] == 'i' || s[i] == 'I' || s[i] == 'u' || s[i] == 'U' || s[i] == 'e' || s[i] == 'E')
            {
                vec.push_back(i);
            }
        }
        for (int i = 0, j = vec.size() - 1; i <= j; i++, j--)
        {
            swap(s, vec[i], vec[j]);
        }
        return s;
    }
};

// class Solution
// {
// public:
//     string reverseVowels(string s)
//     {
//         string temp;
//         int head = 0, tail = s.size() - 1;
//         for (char t : s)
//         {
//             if (isalnum(t))
//             {
//                 temp += tolower(t);
//             }
//             else
//             {
//                 temp += t;
//             }
//         }

//         while (head < tail)
//         {
//             while (temp[head] != 'a' && temp[head] != 'e' && temp[head] != 'i' && temp[head] != 'o' && temp[head] != 'u')
//             {
//                 head++;
//                 if (head >= s.size())
//                 {
//                     break;
//                 }
//             }
//             while (temp[tail] != 'a' && temp[tail] != 'e' && temp[tail] != 'i' && temp[tail] != 'o' && temp[tail] != 'u')
//             {
//                 tail--;
//                 if (tail <= 0)
//                 {
//                     break;
//                 }
//             }
//             if (head >= tail)
//             {
//                 break;
//             }

//             char t = s[head];
//             s[head] = s[tail];
//             s[tail] = t;
//             head++;
//             tail--;
//         }

//         return s;
//     }
// };