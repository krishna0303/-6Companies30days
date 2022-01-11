// { Driver Code Starts
// Initial template for C++

/*
In the stock market, a person buys a stock and sells it on some future date. 
Given the stock prices of N days in an array A[ ] and a positive integer K, 
find out the maximum profit a person can make in at-most K transactions. 
A transaction is equivalent to (buying + selling) of a stock and new transaction 
can start only when the previous transaction has been completed.


Example 1:

Input: K = 2, N = 6
A = {10, 22, 5, 75, 65, 80}
Output: 87
Explaination: 
1st transaction: buy at 10 and sell at 22. 
2nd transaction : buy at 5 and sell at 80.


*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxProfitUtil(int k, int n, int arr[], int minm, int ***dp)
    {
        if (n == 0 || k == 0)
        {
            return dp[k][n][minm] = 0;
        }
        if (dp[k][n][minm] != -1)
        {
            return dp[k][n][minm];
        }
        if (minm)
        {

            return dp[k][n][minm] = max(maxProfitUtil(k - 1, n - 1, arr, 0, dp) + arr[n - 1], maxProfitUtil(k, n - 1, arr, minm, dp));
        }
        else
        {

            return dp[k][n][minm] = max(maxProfitUtil(k, n - 1, arr, 1, dp) - arr[n - 1], maxProfitUtil(k, n - 1, arr, minm, dp));
        }
    }
    int maxProfit(int k, int n, int A[])
    {

        reverse(A, A + n);
        int ***dp = new int **[k + 1];
        for (int i = 0; i <= k; i++)
        {
            dp[i] = new int *[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = new int[2];
                for (int k = 0; k < 2; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        return maxProfitUtil(k, n, A, 0, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} // } Driver Code Ends