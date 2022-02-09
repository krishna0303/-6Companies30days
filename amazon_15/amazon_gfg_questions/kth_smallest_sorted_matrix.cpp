// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends




//Heapify Method-Didn't understand

//for better understanding https://www.youtube.com/watch?v=dpsp1hP6P-U refer this video

int count(int mat[MAX][MAX],int n,int num){
    int count=0;
    int j=n-1;
    for(int i=0;i<n;i++){
        for(j;j>=0;j--){
            if(mat[i][j]<=num){
                count+=(j+1);
                break;
            }
        }
    }
    return count;

}
void BinarySearch(int mat[MAX][MAX],int low,int high,int n,int k,int &ans){
    while(low<high){
        int mid=(low+high)/2;
        int c=count(mat,n,mid);
        if(c<k){
            low=mid+1;
        }else{
            ans=mid;
            high=mid;
        }
    }
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  if(n==1&&k==1){
      return mat[0][0];
  }
  int low=mat[0][0];
  int high=mat[n-1][n-1];
  int ans=0;
  BinarySearch(mat,low,high,n,k,ans);
  return ans;
}
