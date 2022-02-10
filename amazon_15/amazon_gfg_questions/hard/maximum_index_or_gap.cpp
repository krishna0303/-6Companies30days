// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
for this problem refer gfg page for better understanding and to know about different approaches of this problem

*/
class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {
        vector<int> Lmin(n), Rmax(n);
        Lmin[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            Lmin[i] = min(arr[i], Lmin[i - 1]);
        }
        Rmax[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            Rmax[j] = max(arr[j], Rmax[j + 1]);
        }
        int i = 0, j = 0;
        int maxDiff = INT_MIN;
        while (i < n && j < n)
        {
            if (Lmin[i] <= Rmax[j])
            {
                maxDiff = max(maxDiff, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return maxDiff;
    }
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    // this is my recursvie solution but it is not working for all test case it giving tle logic is correct
    // map<string, int>dp;
    // int solve(int arr[],int i,int j){
    //     if(i>=j){
    //         return 0;
    //     }
    //     string key=to_string(i)+" "+to_string(j);
    //     if(dp.find(key) != dp.end()){
    //         return dp[key];
    //     }
    //     if(arr[j-1]>=arr[i]){
    //         return dp[key]=(j-1-i);

    //     }else{
    //         // return dp[key]
    //         string key1=to_string(i+1)+" "+to_string(j);
    //         string key2=to_string(i)+" "+to_string(j-1);
    //         int lf=INT_MIN,rf=INT_MIN;
    //         if(dp.find(key1) != dp.end()){
    //             return dp[key1];
    //         }else{
    //             lf=solve(arr,i+1,j);

    //         }
    //         if(dp.find(key2) != dp.end()){
    //             return dp[key2];
    //         }else{
    //             rf=solve(arr,i,j-1);

    //         }
    //         return dp[key]=max(lf,rf);
    //     }

    // }
    // int maxIndexDiff(int arr[], int n)
    // {
    //     // Your code here

    //     bool flag=false;
    //     for(int i=1;i<n;i++){
    //        if(arr[i-1]<=arr[i]){
    //            flag=true;

    //        }
    //     }
    //     if(!flag){
    //         return 0;
    //     }
    //     // memset(dp,-1,sizeof(dp));
    //     dp.clear();
    //     return solve(arr,0,n);
    // }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
} // } Driver Code Ends