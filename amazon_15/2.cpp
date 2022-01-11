#include<bits/stdc++.h>
using namespace std;

/*

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.


*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int i=0,j=0;
        int maxm=INT_MIN;
        int n=arr.size();
        int count=0;
        while(i<n-1&&j<n-1){
            if(arr[i]<arr[i+1]){
                count+=2;
                j=i+1;
                bool flag=false;
                while(j<n-1){
                    if(arr[j]<arr[j+1]){
                        if(flag){
                            i=j;
                            break;
                        }
                        count+=1;
                        j++;
                    }else if(arr[j]>arr[j+1]){
                        flag=true;
                        count+=1;
                        j++;
                        
                        
                        
                    }else{
                        break;
                    }
                }
                if(count>=3&&flag){
                    maxm=max(count,maxm);
                    count=0;
                    i=j;
                }else{
                    i=j;
                    count=0;
                    
                }
                
                
            }else{
                i++;
            }
            
        }
        return maxm!=INT_MIN?maxm:0;
    }
};
int main(){
    return 0;
}