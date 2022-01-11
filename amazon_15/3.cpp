// { Driver Code Starts

/*
He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 


*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        multiset <int>hp;
        for(int i=0;i<k;i++){
            hp.insert(arr[i]);
        }
        // make_heap(hp.begin(),hp.end());
        vector<int>ans;
        
        int j=k;
        int i=0;
        while(j<=n){
            int to=*hp.rbegin();
            ans.push_back(to);
            hp.erase(hp.find(arr[i]));
            i++;
            hp.insert(arr[j]);
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends