#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][0];
        int last=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=last){
                last=max(last,intervals[i][1]);
            }else{
                vector<int>v;
                v.push_back(prev);
                v.push_back(last);
                ans.push_back(v);
                prev=intervals[i][0];
                last=intervals[i][1];
            }
            
        }
        vector<int>v;
        v.push_back(prev);
        v.push_back(last);
        ans.push_back(v);
        return ans;
        
    }
};