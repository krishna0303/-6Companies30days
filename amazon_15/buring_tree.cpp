// { Driver Code Starts
//Initial Template for C++

/*
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

for better undersanding watch striver burining tree video it has great explanation


*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    Node * findTargetPos(Node *root,int target){
        if(!root){
            return NULL;
        }
        if(root->data==target){
            return root;
        }
        
        Node *temp1=findTargetPos(root->left,target);
        if(temp1!=NULL){
            return temp1;
        }
        Node *temp2=findTargetPos(root->right, target);
        if(temp2!=NULL){
            return temp2;
        }
        
        
        
        
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>m;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
        Node *targetPos=findTargetPos(root,target);
        // cout<<targetPos->data<<endl;
        q.push(targetPos);
        map<Node*,bool>vis;
        int timeTaken =0;
        vis[targetPos]=true;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++){
                Node *temp=q.front();
                q.pop();
                
                if(m[temp]){
                    if(!vis[m[temp]]){
                        q.push(m[temp]);
                        vis[m[temp]]=true;
                        flag=true;
                    }
                    
                }
                if(temp->left&&!vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                    flag=true;
                }
                if(temp->right&&!vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                    flag=true;
                }
            }
            if(flag){
                timeTaken+=1;
            }
            
            
        }
        
        
        
        return timeTaken;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends