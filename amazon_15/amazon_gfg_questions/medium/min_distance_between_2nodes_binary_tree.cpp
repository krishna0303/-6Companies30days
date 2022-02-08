// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*

Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2.

*/
class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *lca(Node *root, int a, int b)
    {
        if (root == NULL)
            return NULL;

        if (root->data == a || root->data == b)
        {
            return root;
        }

        Node *left = lca(root->left, a, b);
        Node *right = lca(root->right, a, b);

        if (left == NULL && right == NULL)
            return NULL;
        if (left && right)
            return root;

        if (left)
            return lca(root->left, a, b);
        return lca(root->right, a, b);
    }
    int distance(Node *ancestor, int a, int d)
    {
        if (ancestor == NULL)
            return -1;

        if (ancestor->data == a)
        {
            return d;
        }

        int left = distance(ancestor->left, a, d + 1);

        if (left != -1)
            return left;

        return distance(ancestor->right, a, d + 1);
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *commonAnc = lca(root, a, b);

        int d1 = distance(commonAnc, a, 0);
        int d2 = distance(commonAnc, b, 0);

        return d1 + d2;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}
// } Driver Code Ends