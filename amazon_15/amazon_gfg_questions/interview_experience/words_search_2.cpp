#include <bits/stdc++.h>
using namespace std;

/*

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically
 neighboring.
 The same letter cell may not be used more than once in a word.

*/

// class Solution
// {
// public:
//     bool visited[13][13];
//     bool solve(vector<vector<char>> &board, int i, int j, int n, int m, string word, int idx, vector<string> &ans)
//     {
//         if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || board[i][j] != word[idx])
//         {
//             return false;
//         }
//         visited[i][j] = true;
//         if (idx == word.length() - 1)
//         {
//             ans.push_back(word);
//             return true;
//         }
//         if (solve(board, i + 1, j, n, m, word, idx + 1, ans) ||
//             solve(board, i - 1, j, n, m, word, idx + 1, ans) ||
//             solve(board, i, j + 1, n, m, word, idx + 1, ans) ||
//             solve(board, i, j - 1, n, m, word, idx + 1, ans))
//         {
//             return true;
//         }
//         visited[i][j] = false;
//         return false;
//     }
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
//     {
//         vector<string> ans;
//         int n = board.size();
//         int m = board[0].size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 visited[i][j] = false;
//             }
//         }
//         // int count=0;
//         for (int k = 0; k < words.size(); k++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 bool flag = false;
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (board[i][j] == words[k][0])
//                     {
//                         // count+=1;
//                         if (solve(board, i, j, n, m, words[k], 0, ans))
//                         {
//                             flag = true;
//                             break;
//                         }
//                     }
//                 }
//                 if (flag)
//                 {
//                     break;
//                 }
//             }
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     visited[i][j] = false;
//                 }
//             }
//         }
//         // cout<<count<<endl;
//         return ans;
//     }
// };

class Solution
{
public:
    bool visited[13][13];

    struct TrieNode
    {
        char val;
        int wordEnd;
        TrieNode *arr[26];
    };

    TrieNode *getNode(char c)
    {
        TrieNode *root = new TrieNode;
        root->val = c;
        root->wordEnd = 0;
        for (int i = 0; i < 26; i++)
        {
            root->arr[i] = NULL;
        }
        return root;
    }

    void insert(TrieNode *root, string s)
    {
        TrieNode *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if (temp->arr[idx] == NULL)
            {
                temp->arr[idx] = getNode(s[i]);
            }
            temp = temp->arr[idx];
        }
        temp->wordEnd += 1;
    }

    void solve(TrieNode *temp, vector<vector<char>> &board, int i, int j, int n, int m, string word, int idx, vector<string> &ans)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || temp->arr[board[i][j] - 'a'] == NULL)
        {
            return;
        }
        word += board[i][j];
        visited[i][j] = true;
        if (temp->arr[board[i][j] - 'a']->wordEnd > 0)
        {

            ans.push_back(word);
            temp->arr[board[i][j] - 'a']->wordEnd -= 1;
        }
        solve(temp->arr[board[i][j] - 'a'], board, i + 1, j, n, m, word, idx + 1, ans);
        solve(temp->arr[board[i][j] - 'a'], board, i - 1, j, n, m, word, idx + 1, ans);
        solve(temp->arr[board[i][j] - 'a'], board, i, j + 1, n, m, word, idx + 1, ans);
        solve(temp->arr[board[i][j] - 'a'], board, i, j - 1, n, m, word, idx + 1, ans);

        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        TrieNode *root = getNode('/');
        for (int i = 0; i < words.size(); i++)
        {
            insert(root, words[i]);
        }
        memset(visited, false, sizeof(visited));
        string str = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (root->arr[board[i][j] - 'a'] != NULL)
                {
                    solve(root, board, i, j, n, m, "", 0, ans);
                }
            }
        }
        return ans;
    }
};

/*
Time complexity: O(4^(N^2)).
Even after applying trie the time complexity remains same. For every cell there are 4 directions and there are N^2 cells. So the time complexity is O(4^(N^2)).
Auxiliary Space: O(N^2).
The maximum length of recursion can be N^2, where N is the side of the matrix. So the space Complexity is O(N^2).

*/