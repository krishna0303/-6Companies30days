/*

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return gcd(b % a, a);
    }
    string gcdOfStrings(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        if (str1.compare(str2) == 0)
        {
            return str1;
        }
        else
        {
            int g = gcd(n, m);
            // cout<<g<<endl;
            string ans = "";

            for (int i = 0; i < g; i++)
            {
                if (str1[i] == str2[i])
                {
                    ans += str1[i];
                }
                else
                {
                    ans = "";
                    break;
                }
            }
            int i = 0, j = 0;
            while (i < n)
            {
                if (str1[i] == ans[j])
                {
                    i++;
                    j++;
                    if (j == ans.length())
                    {
                        j = 0;
                    }
                }
                else
                {
                    ans = "";
                    break;
                }
            }
            if (j == 0)
            {
                i = 0, j = 0;
                while (i < m)
                {
                    if (str2[i] == ans[j])
                    {
                        i++;
                        j++;
                        if (j == ans.length())
                        {
                            j = 0;
                        }
                    }
                    else
                    {
                        ans = "";
                        break;
                    }
                }
            }
            else
            {
                ans = "";
            }
            if (j != 0)
            {
                ans = "";
            }
            return ans;
        }
    }
};

int main()
{
    Solution ob;
    string s1, s2;
    cin >> s1 >> s2;
    cout << ob.gcdOfStrings(s1, s2) << endl;

    return 0;
}