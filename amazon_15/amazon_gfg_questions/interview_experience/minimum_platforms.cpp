// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool compare(const pair<int,int>&a,const pair<int,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    // 	vector<pair<int,int>>v;
    // 	for(int i=0;i<n;i++){
    // 	    v.push_back({arr[i],dep[i]});
    // 	}
    // 	sort(v.begin(),v.end(),compare);
    // 	int count=1;
    	
    // 	priority_queue<int,vector<int>,greater<int>>pq;
    // 	pq.push(v[0].second);
    // 	for(int i=1;i<n;i++){
    // 	    int dept=pq.top();
    // 	   // cout<<dept<<endl;
    // 	   //cout<<v[i].first<<" "<<v[i].second<<endl;
    	    
    // 	    if(dept<v[i].first){
    // 	        pq.pop();
    // 	        pq.push(v[i].second);
    // 	    }else{
    // 	        pq.push(v[i].second);
    // 	        count+=1;
    // 	    }
    	    
    // 	}
    // 	return count;
    
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1,j=0,result=1,plat_needed=1;
    while(i<n&&j<n){
        if(arr[i]<=dep[j]){
            i++;
            plat_needed+=1;
        }else{
            plat_needed-=1;
            j++;
        }
        if(plat_needed>result){
            result=plat_needed;
        }
    }
    return result;
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends