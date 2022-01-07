// { Driver Code Starts

/*

M items are to be delivered in a circle of size N. Find the position where the M-th 
item will be delivered if we start from a given position K. Note that items are distributed  
at adjacent positions starting from K.

 

Example 1:

Input:
N = 5, M = 2, K = 1
Output:
2
Explanation:
If we start from 1st position, the
2nd item will land at the 2nd position.
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findPosition(int N, int M, int K)
    {
        // code here
        int ans = M % N;

        int temp = ans + K - 1;
        if (N == 1 && M == 1 && ans == 0)
        {
            temp += 1;
        }
        if (temp > N)
        {
            return temp % N;
        }
        else
        {
            return temp;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, K;

        cin >> N >> M >> K;

        Solution ob;
        cout << ob.findPosition(N, M, K) << endl;
    }
    return 0;
} // } Driver Code Ends