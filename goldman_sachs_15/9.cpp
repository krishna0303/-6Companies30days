// { Driver Code Starts


/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

 

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing,
So we choose the minimum number
among 21,31,54,87,etc.

*/
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        int num=1;
        int i=0,j=0;
        bool flag=false;
        if(S.length()==1){
            if(S[0]=='I'){
                return "12";
            }else{
                return "21";
            }
        }
        while(i<S.length()-1){
            if(S[i]=='I'){
                if(i==0){
                    ans+="1";
                    num++;
                }
                if(S[i+1]=='D'){
                    int count=0;
                    int j=i+1;
                    while(j<S.length()){
                        if(S[j]=='D'){
                            count+=1;
                            j++;
                        }else{
                            break;
                        }
                    }
                    if(j==S.length()){
                        flag=true;
                    }
                    
                    // count+=1;
                    count+=num;
                    int temp1=count;
                    while(count!=num-1){
                        ans+=to_string(count);
                        count--;
                    }
                    i=j;
                    num=temp1+1;
                    
                }else{
                    ans+=to_string(num);
                    num++;
                    i++;
                }
            }else{
                    int count=0;
                    int j=i+1;
                    if(i==0&&S[i+1]=='I'){
                        ans+="21";
                        num=3;
                        i++;
                        continue;
                    }
                    while(j<S.length()){
                        if(S[j]=='D'){
                            count+=1;
                            j++;
                        }else{
                            break;
                        }
                    }
                    if(j==S.length()){
                        flag=true;
                    }
                    count+=1;
                    count+=num;
                    int temp1=count;
                    while(count!=num-1){
                        ans+=to_string(count);
                        count--;
                    }
                    i=j;
                    num=temp1+1;
                    
                
            }
            
        }
        if(!flag){
            ans+=to_string(num);
        }
        return ans;
        
    }
    
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends