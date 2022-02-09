// { Driver Code Starts

/*
Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land).
 Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., 
in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void solve(vector<vector<char>>& grid,int n,int m,int i,int j,int**visited){
        if(i<0||i>=n||j<0||j>=m||visited[i][j]||grid[i][j]=='0'){
            return;
        }
        visited[i][j]=true;
        solve(grid,n,m,i-1,j,visited);
        solve(grid,n,m,i+1,j,visited);
        solve(grid,n,m,i,j-1,visited);
        solve(grid,n,m,i,j+1,visited);
        solve(grid,n,m,i-1,j-1,visited);
        solve(grid,n,m,i-1,j+1,visited);
        solve(grid,n,m,i+1,j-1,visited);
        solve(grid,n,m,i+1,j+1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int **visited=new int*[n];
        for(int i=0;i<n;i++){
            visited[i]=new int[m];
            for(int j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    count+=1;
                    solve(grid,n,m,i,j,visited);
                }
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends