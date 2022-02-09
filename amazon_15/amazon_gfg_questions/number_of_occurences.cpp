// { Driver Code Starts

/*

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.

*/

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    //time complexity is O(logn)

    // 	int count(int arr[], int n, int x) {
    // 	    int *low = lower_bound(arr, arr+n, x);

    //   // If element is not present, return 0
    //   if (low == (arr + n) || *low != x)
    //      return 0;

    //   /* Else get the index of last occurrence of x.
    //      Note that we  are only looking in the
    //      subarray after first occurrence */
    //   int *high = upper_bound(low, arr+n, x);

    //   /* return count */
    //   return high - low;

    /* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0.
        

        Time complexity of this approach is:O(log(n)+count) where count is no of occurences
        
         */

    int binarySearch(int arr[], int low, int high, int x, int &count)
    {
        int idx = -1;
        bool flag = false;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                idx = mid;
                flag = true;
                break;
            }
        }

        return idx;
    }
    int count(int arr[], int n, int x)
    {
        // code here
        int count = 0;
        int idx = binarySearch(arr, 0, n - 1, x, count);
        if (idx == -1)
        {
            return 0;
        }
        count += 1;
        int i = idx - 1;
        while (i >= 0 && arr[i] == x)
        {
            count += 1;
            i--;
        }
        i = idx + 1;
        while (i < n && arr[i] == x)
        {
            count += 1;
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends