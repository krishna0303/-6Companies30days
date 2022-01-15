// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

 /*
 Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

Example 1:

Input:
N = 28
Output: AB
Explanation: 1 to 26 are A to Z.
Then, 27 is AA and 28 = AB.
 
 */


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        bool flag=false;
        while(n!=0){
            
            long long int rem=n%26;
            // cout<<rem<<endl;
            string te="";
            if(flag){
                rem=rem-1;
                flag=false;
            }
            if(rem==0){
                flag=true;
                rem=26;
            }
            
            te+=('A'+rem-1);
            ans=te+ans;
             n=n/26;
            //  cout<<rem<<" "<<n<<endl;
            
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends