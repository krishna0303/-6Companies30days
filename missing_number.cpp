// { Driver Code Starts
// Initial template for C++

/*

Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
*/

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        /*
        basically there are three method:
        1)method is using hashmap and mark true or false but it takes extra O(n) Space 
        2)Using sum f n natural numbers n*(n+1)/2-sum array elemnts but in this there is problem of overflow
        3) using xor if we take xor between (1^2^3^5)^(1^2^3^4^5)=4 because 1^1=0,2^2=0
        
        
        */
        int a=array[0],b=1;
        for(int i=1;i<n;i++){
            a=a^array[i];
        }
        for(int i=2;i<=n;i++){
            b=b^i;
        }
        return a^b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends