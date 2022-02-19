// { Driver Code Starts
// Initial template for C++
/*

Algorithm :

Create two indices i and j, where i = 0 and j = n-1
Run a loop until i is less than j.
Check if i knows j, then i can’t be a celebrity. so increment i, i.e. i++
Else j cannot be a celebrity, so decrement j, i.e. j–
Assign i as the celebrity candidate
Now at last check that whether the candidate is actually a celebrity by re-running a loop from 0 to n-1
 and constantly checking that if the candidate knows a person or if there is a candidate who does not know the candidate,
then we should return -1. else at the end of the loop, we can be sure that the candidate is actually a celebrity.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (M[j][i] == 1)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        int cand = i;
        for (i = 0; i < n; i++)
        {
            if (cand == i)
            {
                continue;
            }
            if (M[cand][i] == 1 || (M[i][cand] == 0))
            {
                return -1;
            }
        }
        return cand;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends