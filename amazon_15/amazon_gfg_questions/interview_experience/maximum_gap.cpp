#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

*/


class Solution {
public:

int maximumGap(vector<int>& nums) {
    int n=nums.size();
    //Base Case
    if(n<=1) return 0;
    //finding min and max
    int maxi=INT_MIN,mini=INT_MAX;
    for(int i=0; i<n; i++){
        maxi=max(nums[i],maxi);
        mini=min(nums[i],mini);
    }
    //finding ceil interval
    int interval=(maxi-mini+n-2)/(n-1);
    //creating bucket
    int minarr[n-1],maxarr[n-1];
    for(int i=0; i<n-1; i++){
        minarr[i]=INT_MAX;
        maxarr[i]=INT_MIN;
    }
    //filling buckets
    for(int i=0; i<n; i++){
        if(nums[i]==mini || nums[i]==maxi) continue;
        int index=(nums[i]-mini)/interval;
        minarr[index]=min(minarr[index],nums[i]);
        maxarr[index]=max(maxarr[index],nums[i]);
    }
    //finding res or maxGap
    int prev=mini,res=0;
    for(int i=0; i<n-1; i++)
    {
        if(maxarr[i]==INT_MIN) continue;
        res=max(res,minarr[i]-prev);
        prev=maxarr[i];
    }
    res=max(res,maxi-prev);
    
    return res;
}
};