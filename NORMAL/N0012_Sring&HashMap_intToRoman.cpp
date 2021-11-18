// https://leetcode-cn.com/problems/integer-to-roman/submissions/
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> map = {{1, "I"},
                                          {4, "IV"},
                                          {5, "V"},
                                          {9, "IX"},
                                          {10, "X"},
                                          {40, "XL"},
                                          {50, "L"},
                                          {90, "XC"},
                                          {100, "C"},
                                          {400, "CD"},
                                          {500, "D"},
                                          {900, "CM"},
                                          {1000, "M"}};
        int sym[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}, counter = 12;
        string res;
        while (num > 0 && counter > -1)
        {
            if (num >= sym[counter])
            {
                num -= sym[counter];
                res += map[sym[counter]];
            }
            else
            {
                counter--;
            }
        }
        return res;
    }
};

// common solution
// const pair<int, string> valueSymbols[] = {
//     {1000, "M"},
//     {900, "CM"},
//     {500, "D"},
//     {400, "CD"},
//     {100, "C"},
//     {90, "XC"},
//     {50, "L"},
//     {40, "XL"},
//     {10, "X"},
//     {9, "IX"},
//     {5, "V"},
//     {4, "IV"},
//     {1, "I"},
// };
//
// class Solution
// {
// public:
//     string intToRoman(int num)
//     {
//         string roman;
//         for (const auto &[value, symbol] : valueSymbols)
//         {
//             while (num >= value)
//             {
//                 num -= value;
//                 roman += symbol;
//             }
//             if (num == 0)
//             {
//                 break;
//             }
//         }
//         return roman;
//     }
// };

// NiuBi solution
// const string thousands[] = {"", "M", "MM", "MMM"};
// const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
// const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
// const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//
// class Solution
// {
// public:
//     string intToRoman(int num)
//     {
//         return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
//     }
// };

// super NiuBi python solution
// class Solution:
//     def intToRoman(self, num: int) -> str:
//         s=str(num)
//         if num<4:
//             return 'I'*num
//         elif num==4:
//             return 'IV'
//         elif num<9:
//             return 'V'+'I'*(num-5)
//         elif num==9:
//             return 'IX'
// # <39
//         elif num<40:
//             if s[1]=='4':
//                 return 'X'*(num//10)+'IV'
//             elif s[1]=='9':
//                 return 'X'*(num//10)+'IX'
//             elif int(s[1])<4:
//                 return 'X'*(num//10)+'I'*(int(s[1]))
//             elif int(s[1])<9:
//                 return 'X'*(num//10)+'V'+'I'*(int(s[1])-5)
// # 40 - 49
//         elif num<50:
//             if s[1]=='4':
//                 return 'XL'+'IV'
//             elif s[1]=='9':
//                 return 'XL'+'IX'
//             elif int(s[1])<4:
//                 return 'XL'+'I'*(int(s[1]))
//             elif int(s[1])<9:
//                 return 'XL'+'V'+'I'*(int(s[1])-5)
// # 50 - 89
//         elif num<90:
//             if s[1]=='4':
//                 return 'L'+'X'*((num-50)//10)+'IV'
//             elif s[1]=='9':
//                 return 'L'+'X'*((num-50)//10)+'IX'
//             elif int(s[1])<4:
//                 return 'L'+'X'*((num-50)//10)+'I'*(int(s[1]))
//             elif int(s[1])<9:
//                 return 'L'+'X'*((num-50)//10)+'V'+'I'*(int(s[1])-5)
// # 90 - 99
//         elif num<100:
//             if s[1]=='4':
//                 return 'XC'+'IV'
//             elif s[1]=='9':
//                 return 'XC'+'IX'
//             elif int(s[1])<4:
//                 return 'XC'+'I'*(int(s[1]))
//             elif int(s[1])<9:
//                 return 'XC'+'V'+'I'*(int(s[1])-5)
// # 100 - 399
//         elif num<400:
//             if s[1]=='4':
//                 if s[2]=='4':
//                     return 'C'*(num//100)+'XL'+'IV'
//                 elif s[2]=='9':
//                     return 'C'*(num//100)+'XL'+'IX'
//                 elif int(s[2])<4:
//                     return 'C'*(num//100)+'XL'+'I'*int(s[2])
//                 else:
//                     return 'C'*(num//100)+'XL'+'V'+'I'*(int(s[2])-5)
//             elif s[1]=='9':
//                 if s[2]=='4':
//                     return 'C'*(num//100)+'XC'+'IV'
//                 elif s[2]=='9':
//                     return 'C'*(num//100)+'XC'+'IX'
//                 elif int(s[2])<4:
//                     return 'C'*(num//100)+'XC'+'I'*int(s[2])
//                 else:
//                     return 'C'*(num//100)+'XC'+'V'+'I'*(int(s[2])-5)
//             elif int(s[1])<4:
//                 if s[2]=='4':
//                     return 'C'*(num//100)+'X'*(int(s[1]))+'IV'
//                 elif s[2]=='9':
//                     return 'C'*(num//100)+'X'*(int(s[1]))+'IX'
//                 elif int(s[2])<4:
//                     return 'C'*(num//100)+'X'*(int(s[1]))+'I'*int(s[2])
//                 else:
//                     return 'C'*(num//100)+'X'*(int(s[1]))+'V'+'I'*(int(s[2])-5)    
//             else:
//                 if s[2]=='4':
//                     return 'C'*(num//100)+'L'+'X'*(int(s[1])-5)+'IV'
//                 elif s[2]=='9':
//                     return 'C'*(num//100)+'L'+'X'*(int(s[1])-5)+'IX'
//                 elif int(s[2])<4:
//                     return 'C'*(num//100)+'L'+'X'*(int(s[1])-5)+'I'*int(s[2])
//                 else:
//                     return 'C'*(num//100)+'L'+'X'*(int(s[1])-5)+'V'+'I'*(int(s[2])-5)
// # 400 - 499
//         elif num<500:
//             if s[1]=='4':
//                 if s[2]=='4':
//                     return 'CD'+'XL'+'IV'
//                 elif s[2]=='9':
//                     return 'CD'+'XL'+'IX'
//                 elif int(s[2])<4:
//                     return 'CD'+'XL'+'I'*int(s[2])
//                 else:
//                     return 'CD'+'XL'+'V'+'I'*(int(s[2])-5)
//             elif s[1]=='9':
//                 if s[2]=='4':
//                     return 'CD'+'XC'+'IV'
//                 elif s[2]=='9':
//                     return 'CD'+'XC'+'IX'
//                 elif int(s[2])<4:
//                     return 'CD'+'XC'+'I'*int(s[2])
//                 else:
//                     return 'CD'+'XC'+'V'+'I'*(int(s[2])-5)
//             elif int(s[1])<4:
//                 if s[2]=='4':
//                     return 'CD'+'X'*(int(s[1]))+'IV'
//                 elif s[2]=='9':
//                     return 'CD'+'X'*(int(s[1]))+'IX'
//                 elif int(s[2])<4:
//                     return 'CD'+'X'*(int(s[1]))+'I'*int(s[2])
//                 else:
//                     return 'CD'+'X'*(int(s[1]))+'V'+'I'*(int(s[2])-5)    
//             else:
//                 if s[2]=='4':
//                     return 'CD'+'L'+'X'*(int(s[1])-5)+'IV'
//                 elif s[2]=='9':
//                     return 'CD'+'L'+'X'*(int(s[1])-5)+'IX'
//                 elif int(s[2])<4:
//                     return 'CD'+'L'+'X'*(int(s[1])-5)+'I'*int(s[2])
//                 else:
//                     return 'CD'+'L'+'X'*(int(s[1])-5)+'V'+'I'*(int(s[2])-5)
// # 500 - 899
//         elif num<900:
//             if s[1]=='4':
//                 if s[2]=='4':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XL'+'IV'
//                 elif s[2]=='9':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XL'+'IX'
//                 elif int(s[2])<4:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XL'+'I'*int(s[2])
//                 else:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XL'+'V'+'I'*(int(s[2])-5)
//             elif s[1]=='9':
//                 if s[2]=='4':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XC'+'IV'
//                 elif s[2]=='9':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XC'+'IX'
//                 elif int(s[2])<4:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XC'+'I'*int(s[2])
//                 else:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'XC'+'V'+'I'*(int(s[2])-5)
//             elif int(s[1])<4:
//                 if s[2]=='4':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'X'*(int(s[1]))+'IV'
//                 elif s[2]=='9':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'X'*(int(s[1]))+'IX'
//                 elif int(s[2])<4:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'X'*(int(s[1]))+'I'*int(s[2])
//                 else:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'X'*(int(s[1]))+'V'+'I'*(int(s[2])-5)    
//             else:
//                 if s[2]=='4':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'L'+'X'*(int(s[1])-5)+'IV'
//                 elif s[2]=='9':
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'L'+'X'*(int(s[1])-5)+'IX'
//                 elif int(s[2])<4:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'L'+'X'*(int(s[1])-5)+'I'*int(s[2])
//                 else:
//                     return 'D'*(num//500)+'C'*((num-500)//100)+'L'+'X'*(int(s[1])-5)+'V'+'I'*(int(s[2])-5)
// # 900 - 999                    
//         elif num<1000:
//             if s[1]=='4':
//                 if s[2]=='4':
//                     return 'CM'+'XL'+'IV'
//                 elif s[2]=='9':
//                     return 'CM'+'XL'+'IX'
//                 elif int(s[2])<4:
//                     return 'CM'+'XL'+'I'*int(s[2])
//                 else:
//                     return 'CM'+'XL'+'V'+'I'*(int(s[2])-5)
//             elif s[1]=='9':
//                 if s[2]=='4':
//                     return 'CM'+'XC'+'IV'
//                 elif s[2]=='9':
//                     return 'CM'+'XC'+'IX'
//                 elif int(s[2])<4:
//                     return 'CM'+'XC'+'I'*int(s[2])
//                 else:
//                     return 'CM'+'XC'+'V'+'I'*(int(s[2])-5)
//             elif int(s[1])<4:
//                 if s[2]=='4':
//                     return 'CM'+'X'*(int(s[1]))+'IV'
//                 elif s[2]=='9':
//                     return 'CM'+'X'*(int(s[1]))+'IX'
//                 elif int(s[2])<4:
//                     return 'CM'+'X'*(int(s[1]))+'I'*int(s[2])
//                 else:
//                     return 'CM'+'X'*(int(s[1]))+'V'+'I'*(int(s[2])-5)    
//             else:
//                 if s[2]=='4':
//                     return 'CM'+'L'+'X'*(int(s[1])-5)+'IV'
//                 elif s[2]=='9':
//                     return 'CM'+'L'+'X'*(int(s[1])-5)+'IX'
//                 elif int(s[2])<4:
//                     return 'CM'+'L'+'X'*(int(s[1])-5)+'I'*int(s[2])
//                 else:
//                     return 'CM'+'L'+'X'*(int(s[1])-5)+'V'+'I'*(int(s[2])-5)
// # 1000 - 3999
//         else:
//             if s[1]=='4':
//                 if s[2]=='4':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CD'+'XL'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CD'+'XL'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CD'+'XL'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CD'+'XL'+'V'+'I'*(int(s[3])-5)
//                 elif s[2]=='9':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CD'+'XC'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CD'+'XC'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CD'+'XC'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CD'+'XC'+'V'+'I'*(int(s[3])-5)
//                 elif int(s[2])<4:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CD'+'X'*(int(s[2]))+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CD'+'X'*(int(s[2]))+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CD'+'X'*(int(s[2]))+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CD'+'X'*(int(s[2]))+'V'+'I'*(int(s[3])-5)    
//                 else:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CD'+'L'+'X'*(int(s[2])-5)+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CD'+'L'+'X'*(int(s[2])-5)+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CD'+'L'+'X'*(int(s[2])-5)+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CD'+'L'+'X'*(int(s[2])-5)+'V'+'I'*(int(s[3])-5)     
//             elif s[1]=='9':
//                 if s[2]=='4':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CM'+'XL'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CM'+'XL'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CM'+'XL'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CM'+'XL'+'V'+'I'*(int(s[3])-5)
//                 elif s[2]=='9':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CM'+'XC'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CM'+'XC'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CM'+'XC'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CM'+'XC'+'V'+'I'*(int(s[3])-5)
//                 elif int(s[2])<4:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CM'+'X'*(int(s[2]))+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CM'+'X'*(int(s[2]))+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CM'+'X'*(int(s[2]))+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CM'+'X'*(int(s[2]))+'V'+'I'*(int(s[3])-5)    
//                 else:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'CM'+'L'+'X'*(int(s[2])-5)+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'CM'+'L'+'X'*(int(s[2])-5)+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'CM'+'L'+'X'*(int(s[2])-5)+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'CM'+'L'+'X'*(int(s[2])-5)+'V'+'I'*(int(s[3])-5)  
//             elif int(s[1])<4:
//                 if s[2]=='4':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XL'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XL'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XL'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XL'+'V'+'I'*(int(s[3])-5)
//                 elif s[2]=='9':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XC'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XC'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XC'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'XC'+'V'+'I'*(int(s[3])-5)
//                 elif int(s[2])<4:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'X'*(int(s[2]))+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'X'*(int(s[2]))+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'X'*(int(s[2]))+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'X'*(int(s[2]))+'V'+'I'*(int(s[3])-5)    
//                 else:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'L'+'X'*(int(s[2])-5)+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'L'+'X'*(int(s[2])-5)+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'L'+'X'*(int(s[2])-5)+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'C'*(int(s[1]))+'L'+'X'*(int(s[2])-5)+'V'+'I'*(int(s[3])-5)  
//             else:
//                 if s[2]=='4':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XL'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XL'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XL'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XL'+'V'+'I'*(int(s[3])-5)
//                 elif s[2]=='9':
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XC'+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XC'+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XC'+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'XC'+'V'+'I'*(int(s[3])-5)
//                 elif int(s[2])<4:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'X'*(int(s[2]))+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'X'*(int(s[2]))+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'X'*(int(s[2]))+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'X'*(int(s[2]))+'V'+'I'*(int(s[3])-5)    
//                 else:
//                     if s[3]=='4':
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'L'+'X'*(int(s[2])-5)+'IV'
//                     if int(s[3])<4:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'L'+'X'*(int(s[2])-5)+'I'*(int(s[3]))
//                     if int(s[3])==9:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'L'+'X'*(int(s[2])-5)+'IX'
//                     else:
//                         return 'M'*(int(s[0]))+'D'+'C'*(int(s[1])-5)+'L'+'X'*(int(s[2])-5)+'V'+'I'*(int(s[3])-5)