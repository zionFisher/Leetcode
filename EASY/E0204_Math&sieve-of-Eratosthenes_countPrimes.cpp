// https://leetcode-cn.com/problems/count-primes/
#include <iostream>
#include <vector>
using namespace std;

// sieve-of-Eratosthenes 埃筛
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> vec(n + 1, 1);
        int counter = 0;
        for (int count = 2; count < n; ++count)
        {
            if (vec[count])
            {
                counter++;
                for (int i = 2 * count; i < n; i += count)
                {
                    vec[i] = 0;
                }
            }
        }
        return counter;
    }
};

// better solution
// class Solution
// {
// public:
//     int countPrimes(int n)
//     {
//         vector<int> isPrime(n, 1);
//         int ans = 0;
//         for (int i = 2; i < n; ++i)
//         {
//             if (isPrime[i])
//             {
//                 ans += 1;
//                 if ((long long)i * i < n)
//                 {
//                     for (int j = i * i; j < n; j += i)
//                     {
//                         isPrime[j] = 0;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// common solution but TLE
// class Solution
// {
// public:
//     bool isPrime(int x)
//     {
//         for (int i = 2; i * i <= x; ++i)
//         {
//             if (x % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//
//     int countPrimes(int n)
//     {
//         int ans = 0;
//         for (int i = 2; i < n; ++i)
//         {
//             ans += isPrime(i);
//         }
//         return ans;
//     }
// };