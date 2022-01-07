// { Driver Code Starts

/*

Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

*/
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:


    int *findTwoElement(int *arr, int n) {
        // code here
        int a;
        int b;
        int i=0;
        while(i<n){
            while(arr[i]!=arr[arr[i]-1] && i<n)swap(arr[i],arr[arr[i]-1]);
            
            i++;
        }
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]!=(i+1)){
                a=i+1;
                b=arr[i];
                break;
                
            }
        }
        int *ans=new int[2];
        ans[0]=b;
        ans[1]=a;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends