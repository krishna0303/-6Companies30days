#include <bits/stdc++.h>
using namespace std;

// this is my working approach TC-n!*n^2 and space complexity O(n)
//  class Solution {
//  public:
//      vector<vector<int>> permuteUtil(vector<int> nums){
//          vector<vector<int>>temp,ans;
//          if(nums.size()==0){
//              return temp;

//         }
//         for(int i=0;i<nums.size();i++){
//             vector<int>v;
//             for(int j=0;j<nums.size();j++){
//                 if(i!=j){
//                     v.push_back(nums[j]);
//                 }

//             }
//             temp=permuteUtil(v);
//             if(temp.size()==0){
//                 vector<int>v1;
//                 v1.push_back(nums[i]);
//                 ans.push_back(v1);
//             }else{
//                 for(auto it:temp){
//                 it.insert(it.begin(),nums[i]);
//                 ans.push_back(it);
//             }

//             }

//         }
//         return ans;

//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         return permuteUtil(nums);

//     }
// };

/*
Striver 1st approach TC-O(n!*n) SC-O(n)+O(n)
class Solution {
public:
   void permuteUtil(vector<int>&nums,vector<int>&ds,int freq[],vector<vector<int>>&ans){
       if(ds.size()==nums.size()){
           ans.push_back(ds);
           return;
       }
       for(int i=0;i<nums.size();i++){
           if(!freq[i]){
               freq[i]=1;
               ds.push_back(nums[i]);
               permuteUtil(nums,ds,freq,ans);
               freq[i]=0;
               ds.pop_back();
           }

       }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)freq[i]=0;
        vector<vector<int>>ans;
        permuteUtil(nums,ds,freq,ans);
        return ans;

    }
};




striver end approach to reduce space complexity--TC(n!*n) SC-(1)
class Solution {
public:
   void permuteUtil(int idx,vector<int>&nums,vector<vector<int>>&ans){
       if(idx==nums.size()){
           ans.push_back(nums);
           return;
       }
       for(int i=idx;i<nums.size();i++){
               swap(nums[idx],nums[i]);
               permuteUtil(idx+1,nums,ans);
               swap(nums[idx],nums[i]);


       }


    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        permuteUtil(0,nums,ans);
        return ans;

    }
};

 */