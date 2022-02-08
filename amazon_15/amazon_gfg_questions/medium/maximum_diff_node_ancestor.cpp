// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int maxDiff(Node *root);

// Function to Build Tree
Node *buildTree(string str)
{
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
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        cout << maxDiff(root) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
/*
Given a Binary Tree, you need to find the maximum value which you can get by subtracting the
value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B.

Example 1:

Input:
    5
 /    \
2      1
Output: 4
Explanation:The maximum difference we can
get is 4, which is bewteen 5 and 1.

*/
// Function to return the maximum difference between any node and its ancestor.
void maxDiffUtil(Node *root, int &anc, int &maxm)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        if ((anc - root->left->data) > maxm)
        {
            maxm = anc - root->left->data;
        }
        if (anc < root->left->data)
        {

            maxDiffUtil(root->left, root->left->data, maxm);
        }
        else
        {
            maxDiffUtil(root->left, anc, maxm);
        }
    }
    if (root->right)
    {
        if ((anc - root->right->data) > maxm)
        {
            maxm = anc - root->right->data;
        }
        if (anc < root->right->data)
        {

            maxDiffUtil(root->right, root->right->data, maxm);
        }
        else
        {
            maxDiffUtil(root->right, anc, maxm);
        }
    }
}
int maxDiff(Node *root)
{
    int maxm = INT_MIN;
    int anc = root->data;
    maxDiffUtil(root, anc, maxm);
    return maxm;
}
