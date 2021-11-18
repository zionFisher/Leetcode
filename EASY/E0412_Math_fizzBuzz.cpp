// https://leetcode-cn.com/problems/fizz-buzz/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        if (n <= 0)
            return vector<string>();
        vector<string> res;
        for (int count = 1; count <= n; ++count)
        {
            if (count % 3 == 0 && count % 5 == 0)
                res.push_back("FizzBuzz");
            else if (count % 3 == 0)
                res.push_back("Fizz");
            else if (count % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(count));
        }
        return res;
    }
};

// solution without if-else
// class Solution
// {
// public:
//     vector<string> fizzBuzz(int n)
//     {
//         vector<string> result;
//         for (int i = 1; i <= n; ++i)
//             result.push_back(to_string(i));
//         for (int i = 2; i < n; i += 3)
//             result[i] = "Fizz";
//         for (int i = 4; i < n; i += 5)
//             result[i] = "Buzz";
//         for (int i = 14; i < n; i += 15)
//             result[i] = "FizzBuzz";
//         return result;
//     }
// };

// string concatenation in java
// class Solution
// {
// public
//     List<String> fizzBuzz(int n)
//     {
//         // ans list
//         List<String> ans = new ArrayList<String>();
//
//         for (int num = 1; num <= n; num++)
//         {
//             boolean divisibleBy3 = (num % 3 == 0);
//             boolean divisibleBy5 = (num % 5 == 0);
//
//             String numAnsStr = "";
//             if (divisibleBy3)
//             {
//                 // Divides by 3, add Fizz
//                 numAnsStr += "Fizz";
//             }
//             if (divisibleBy5)
//             {
//                 // Divides by 5, add Buzz
//                 numAnsStr += "Buzz";
//             }
//             if (numAnsStr.equals(""))
//             {
//                 // Not divisible by 3 or 5, add the number
//                 numAnsStr += Integer.toString(num);
//             }
//
//             // Append the current answer str to the ans list
//             ans.add(numAnsStr);
//         }
//         return ans;
//     }
// }