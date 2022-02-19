#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     //recursive solution
//     int dp[201][201];
//     int minPathSumUtil(vector<vector<int>>&grid,int i,int j,int n,int m){
//         if(i<0||j<0||i>=n||j>=m){
//             return INT_MAX;
//         }

//         if(i==n-1&&j==m-1){

//             return grid[i][j];

//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         return dp[i][j]=grid[i][j]+min(minPathSumUtil(grid,i+1,j,n,m),minPathSumUtil(grid,i,j+1,n,m));

//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int res=INT_MAX;
//         int count=0;
//         memset(dp,-1,sizeof(dp));
//         return minPathSumUtil(grid,0,0,grid.size(),grid[0].size());
//         // return res;

//     }
// };

// iterative solution using top down approach
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];

        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};