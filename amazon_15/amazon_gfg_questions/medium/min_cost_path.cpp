// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        dp[0][0]=Matrix[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+Matrix[0][i];
            dp[i][0]=dp[i-1][0]+Matrix[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+Matrix[i][j];
            }
        }
        return dp[n-1][n-1];
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends