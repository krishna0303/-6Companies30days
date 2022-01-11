// { Driver Code Starts
// Initial Template for C++

/*

mycode for matrix chain multiplication i have follow pepcoding video

int matrixChainOrder(int p[], int n){
        // code here
        int **dp=new int*[n-1];
        for(int i=0;i<n-1;i++){
            dp[i]=new int[n-1];
        }
        for(int g=0;g<n-1;g++){
            for(int i=0,j=g;j<n-1;i++,j++){
                if(g==0){
                    dp[i][j]=0;
                }else if(g==1){
                    dp[i][j]=arr[i]*arr[j]*arr[j+1];
                }else{
                    int min=INT_MAX;
                    for(int k=i;k<j;k++){
                        int lc=dp[i][k];
                        int rc=dp[k+1][j];
                        int mc=arr[i]*arr[k+1]*arr[j+1];
                        int tc=lc+rc+mc;
                        if(tc<min){
                            min=tc;
                        }
                        
                        
                        
                    }
                    dp[i][j]=min;
                }
            }
            
        }
        return dp[0][n-1];
    }



*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void OptimalParanthesis(int i, int j, int n, int brackets[101][101], char &name, string &s)
    {

        if (i == j)
        {
            s.push_back(name++);
            return;
        }
        s.push_back('(');

        OptimalParanthesis(i, brackets[i][j], n, brackets, name, s);
        OptimalParanthesis(brackets[i][j] + 1, j, n, brackets, name, s);

        s.push_back(')');
    }

    string matrixChainOrder(int arr[], int n)
    {
        int t[101][101];
        int brackets[101][101];

        int i, j, k, temp;
        int min = 0;

        for (int i = 0; i < n; i++)
        {
            t[i][i] = 0;
        }

        for (int L = 2; L < n; L++)
        {
            for (int i = 0; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                t[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    temp = t[i][k] + t[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                    if (temp < t[i][j])
                    {
                        t[i][j] = temp;
                        brackets[i][j] = k;
                    }
                }
            }
        }
        char name = 'A';
        string s;
        OptimalParanthesis(1, n - 1, n, brackets, name, s);
        return s;
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
} // } Driver Code Ends