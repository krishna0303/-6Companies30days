/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive
//  class Solution
//  {
//  public:
//      bool isSameTree(TreeNode *p, TreeNode *q)
//      {
//          if (!p && !q)
//          {
//              return true;
//          }
//          if ((!p && q) || (p && !q) || (p->val != q->val))
//          {
//              return false;
//          }

//         bool ans1 = isSameTree(p->left, q->right);
//         bool ans2 = isSameTree(p->right, q->left);

//         if (!ans1 || !ans2)
//         {
//             return false;
//         }
//         return true;
//     }
//     bool isSymmetric(TreeNode *root)
//     {
//         return isSameTree(root->left, root->right);
//     }
// };

// iterative

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> q1, q2;

        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *nod1 = q1.front();
            q1.pop();
            TreeNode *nod2 = q2.front();
            q2.pop();
            if ((!nod1 && nod2) || (nod1 && !nod2))
            {
                return false;
            }
            if (!nod1 && !nod2)
            {
                continue;
            }
            if (nod1->val != nod2->val)
            {
                return false;
            }

            q1.push(nod1->left);

            q1.push(nod1->right);

            q2.push(nod2->right);

            q2.push(nod2->left);
        }

        if (!q1.empty() || !q2.empty())
        {
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }
};