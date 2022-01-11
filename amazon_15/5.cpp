// Initial Template for C++

/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


typedef struct TrieNode{
        vector<int> data;
        int prefixcnt;
        TrieNode*child[26];
    }TrieNode;
    
TrieNode* CreateTrie(int idx){
        TrieNode *root=new TrieNode;
        root->data.push_back(idx);
        root->prefixcnt=1;
        for(int i=0;i<26;i++){
            root->child[i]=NULL;
        }
        return root;
    }
    
    void insertTrie(TrieNode *root, string s,int index){
        int n=s.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++){
            int idx=(s[i]-'a');
            if(temp->child[idx]==NULL){
                temp->child[idx]=CreateTrie(index);
            }else{
                temp->child[idx]->data.push_back(index);
                temp->child[idx]->prefixcnt+=1;
            }
            temp=temp->child[idx];
        }
        
    }
    
    bool findTrie(TrieNode *root,string s,vector<int>&index){
        int n=s.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++){
            int idx=(s[i]-'a');
            if(temp->child[idx]==NULL){
                return false;
            }
            temp=temp->child[idx];
        }
        if(temp!=NULL&&temp->prefixcnt>0){
            index=temp->data;
            
            return true;
        }else{
            return false;
        }
        
        
    }

class Solution{
public:
    

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
       int m=s.length();
        TrieNode *root=CreateTrie(-1);
        for(int i=0;i<n;i++){
            insertTrie(root,contact[i],i);
            
        }
       vector<vector<string>>ans;
       string temp="";
       
       for(int i=0;i<m;i++){
           vector<string>v;
           vector<int>index;
           set<string>st;
           temp+=s[i];
           if(findTrie(root,temp,index)){
               for(int j=0;j<index.size();j++){
                //   cout<<index[j]<<" ";
                   if(st.find(contact[index[j]])==st.end()){
                       st.insert(contact[index[j]]);
                       v.push_back(contact[index[j]]);
                   }
                   
               }
               sort(v.begin(),v.end());
               
           }else{
               v.push_back("0");
           }
           
           
        //   v.push_back("\n");
           ans.push_back(v);
           
       }
       return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends