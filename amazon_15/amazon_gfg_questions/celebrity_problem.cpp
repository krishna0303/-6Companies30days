// { Driver Code Starts
//Initial template for C++

/*

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

*/

/*

Time Complexity : O(N)
Space Complexity : O(1)
bool knows(vector<vector<int>>& matrix, int first, int second)
    {
        return matrix[first][second];
    }
    
    int celebrity(vector<vector<int> >& matrix, int n) 
    {
         stack<int> st;
         
         for(int i = 0; i < n; i++)
         {
             st.push(i);
         }
         
         while(st.size() != 1)
         {
             int first = st.top();
             st.pop();
             
             int second = st.top();
             st.pop();
             
             if(knows(matrix, first, second))
             {
                 st.push(second);
             }
             else
             {
                 st.push(first);
             }
         }
         
         int ans =  st.top();
         
         int i;
         
         int row = ans;
         
         int col = ans;
         
         for(i = 0; i < n; i++)
         {
             if(matrix[row][i] == 1)
             {
                 break;
             }
         }
         
         if(i != n)
         return -1;
         
         for(i = 0; i < n; i++)
         {
             if(i == ans)
             continue;
             
             else
             {
                 if(matrix[i][col] == 0)
                 {
                     break;
                 }
             }
         }
         
         if(i != n)
         return -1;
         
         return ans;
    }



*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int count1 = 0;
            int count2 = 0;
            int indexz = 0;
            for (int j = 0; j < n; j++)
            {
                if (M[j][i] == 1)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                    indexz = j;
                }
            }
            if (count2 == 1 && (count2 + count1 == n))
            {
                bool flag = false;
                for (int j = 0; j < n; j++)
                {
                    if (M[indexz][j] == 1)
                    {
                        flag = true;
                    }
                }
                if (!flag)
                {
                    ans = indexz;
                    break;
                }
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