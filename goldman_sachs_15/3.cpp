/*
Given an array of positive numbers, 
the task is to find the number of possible contiguous subarrays having product less than a given number k.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        long long i = 0, j = 0;
        long long count = 1;
        int ans = 0;
        long long temp = 1;
        bool flag = true;
        while (i < n && j < n)
        {
            if (i > j)
            {
                j++;
                temp = 1;
                count = 1;
                flag = true;
            }
            if (flag)
            {
                temp = temp * a[j];
            }

            // cout<<count<<endl;
            if (temp < k)
            {
                // cout<<a[j]<<" "<<count<<endl;
                // cout<<i<<" "<<j<<endl;
                ans += count;
                count += 1;
                j++;
                flag = true;
            }
            else
            {
                temp /= a[i];
                count -= 1;
                i++;
                flag = false;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends