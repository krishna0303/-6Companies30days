// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    int dp[10001];
    int solve(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = (solve(n - 1) % mod + solve(n - 2) % mod) % mod;
    }
    int nthPoint(int n)
    {
        // Code here
        memset(dp, -1, sizeof(dp));
        return solve(n + 1);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthPoint(n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends