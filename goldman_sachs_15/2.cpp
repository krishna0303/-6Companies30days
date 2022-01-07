// { Driver Code Starts
// Initial Template for C++
/*
Given two rectangles, find if the given two rectangles overlap or not.
 A rectangle is denoted by providing the x and y coordinates of two points:
  the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        // code here
        if ((L2[0] > R1[0] || R2[0] < L1[0]))
        {
            return 0;
        }
        else if (R2[1] > L1[1] || R1[1] > L2[1])
        {
            return 0;
        }
        else
        {
            return 1;
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
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
} // } Driver Code Ends