// { Driver Code Starts

/*
Given an array of integers, your task is to find the smallest and second smallest element in the array. If smallest and second smallest do not exist, print -1.


*/
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}// } Driver Code Ends

//it uses one traversal efficient soultion
vector<int> minAnd2ndMin(int arr[], int n) {
    int max1=INT_MAX;
    int max2=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<max1){
            if(max1<max2){
                max2=max1;
            }
            max1=arr[i];
            
        }else{
            if(arr[i]!=max1&&arr[i]<max2){
                max2=arr[i];
            }
        }
    }
    
    
    vector<int>v;
    if(max1==INT_MAX||max2==INT_MAX){
        v.push_back(-1);
        v.push_back(-1);
    }else{
        v.push_back(max1);
        v.push_back(max2);
    }
    return v;
    
}



//it uses two traversal
// vector<int> minAnd2ndMin(int arr[], int n) {
//     int max1=INT_MAX;
//     int max2=INT_MAX;
//     for(int i=0;i<n;i++){
//         if(arr[i]<max1){
//             max1=arr[i];
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         if(arr[i]!=max1&&arr[i]<max2){
            
//             max2=arr[i];
       
//         }
//     }
//     vector<int>v;
//     if(max1==INT_MAX||max2==INT_MAX){
//         v.push_back(-1);
//         v.push_back(-1);
//     }else{
//         v.push_back(max1);
//         v.push_back(max2);
//     }
//     return v;
    
// }