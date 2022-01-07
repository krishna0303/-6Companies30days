// { Driver Code Starts

/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:

Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.


*/
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/

    ull getNthUglyNo(int n)
    {
        // code here
        int c2(0), c3(0), c5(0);
        vector<ull> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
            if (dp[i] == (2 * dp[c2]))
            {
                c2++;
            }
            if (dp[i] == (3 * dp[c3]))
            {
                c3++;
            }
            if (dp[i] == (5 * dp[c5]))
            {
                c5++;
            }
        }
        return dp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends