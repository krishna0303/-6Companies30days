// { Driver Code Starts

/*

A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example 1:

Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).

for better understanding of this approach
watch: https://www.youtube.com/watch?v=jFZmBQ569So


*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1000000007;
    int CountWays(string str)
    {
        // Code here
        int n = str.length();
        int dp[n];
        if (str[0] == '0')
        {
            dp[0] = 0;
        }
        else
        {
            dp[0] = 1;
        }

        //  dp[1]=1;
        for (int i = 1; i < n; i++)
        {
            if (str[i - 1] == '0' && str[i] == '0')
            {
                dp[i] = 0;
            }
            else if (str[i - 1] == '0' && str[i] != '0')
            {
                dp[i] = dp[i - 1];
            }
            else if (str[i - 1] != '0' && str[i] == '0')
            {
                if (str[i - 1] == '1' || str[i - 1] == '2')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 1) % mod;
                }
                else
                {
                    dp[i] = 0;
                }
            }
            else
            {
                string temp = "";
                temp += str[i - 1];
                temp += str[i];
                // cout<<temp<<endl;
                int count = stoi(temp);
                // cout<<count<<endl;
                if (count <= 26)
                {
                    dp[i] = (dp[i - 1] % mod + (i >= 2 ? dp[i - 2] : 1) % mod) % mod;
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[n - 1] % mod;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends