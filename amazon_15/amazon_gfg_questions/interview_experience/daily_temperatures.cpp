#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int n=temperatures.size();
        s.push({temperatures[n-1],n-1});
        temperatures[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int val=temperatures[i];
            bool flag=false;
            while(!s.empty()){
                int maxm=s.top().first;
                // cout<<maxm<<endl;
                if(maxm>val){
                    int day=s.top().second-i;
                    
                    s.push({val,i});
                    temperatures[i]=day;
                    flag=true;
                    break;
                    
                    
                }else{
                    s.pop();
                }
            }
            if(!flag){
                temperatures[i]=0;
                s.push({val,i});
                
            }
        }
        return temperatures;
        
    }
};