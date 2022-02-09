// { Driver Code Starts
/*
Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained while 
traversing the matrix spirally. You need to complete the method findK which takes four arguments the 
first argument is the matrix A and the next two arguments will be n and m denoting the size of the m
atrix A and then the forth argument is an integer  k denoting the kth element . The function will return the 
kth element obtained while traversing the matrix spirally.


Example 1:

Input:
n = 3, m = 3, k = 4
A[][] = {{1 2 3},
         {4 5 6},
         {7 8 9}}
         
Output:
6
Explanation:
The matrix above will look like 
1 2 3
4 5 6
7 8 9

spiral matrix of this matrix is 1 2 3 6 9 8 7 4 5
and the 4th element in spiral fashion
will be 6 .

*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}// } Driver Code Ends


/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
    int top=0,left=0,right=m-1,bottom=n-1;
    vector<int>ans;
    while(top<=bottom&&left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(A[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(A[i][right]);
        }
        right--;
        for(int i=right;i>=left;i--){
            ans.push_back(A[bottom][i]);
            
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            ans.push_back(A[i][left]);
        }
        left++;
    }
    return ans[k-1];
    
    

}

