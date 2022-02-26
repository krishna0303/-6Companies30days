#include <bits/stdc++.h>
using namespace std;

/*

struct Trie {
    bool eow = false;
    Trie *children[26] = {};
};

class WordDictionary {
    Trie *root, *curr;
    bool res;
public:
    WordDictionary() {
        // initialising the trie
        root = new Trie;
    }

    void addWord(const string &word) {
        // adding word to the trie using curr as a pointer
        curr = root;
        for (char c: word) {
            c -= 'a';
            if (!curr->children[c]) curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->eow = true;
    }

    bool search(const string &word, int start = 0) {
        // base case: we start the search and thus set res to false
        if (!start) {
            res = false;
            curr = root;
        }
        // base case: we already found a match, so we stop recursing
        if (res) return res;
        // base case: we are done parsing the string
        if (start == word.size()) return curr->eow;
        // general case:
        char c = word[start];
        // wild card character
        if (c == '.') {
            Trie *origCurr = curr;
            for (auto child: curr->children) {
                if (!child) continue;
                curr = child;
                res |= this->search(word, start + 1);
                // stopping if we found a result already
                if (res) break;
            }
            // backtracking curr
            curr = origCurr;
            return res;
        }
        // any other character
        c -= 'a';
        if (!curr->children[c]) return false;
        curr = curr->children[c];
        return this->search(word, start + 1);
    }
};

*/

// class WordDictionary
// {
//     struct node
//     {
//         char c;
//         int end;
//         node *child[26];
//     };
//     node *getNode(char c)
//     {
//         node *newnode = new node;
//         newnode->c = c;
//         newnode->end = 0;
//         for (int i = 0; i < 26; ++i)
//             newnode->child[i] = NULL;
//         return newnode;
//     }
//     node *root = getNode('/');

//     void Trie_insert(string s)
//     {
//         int index;
//         int i = 0;
//         node *curr = root;
//         while (s[i])
//         {
//             index = s[i] - 'a';
//             if (!curr->child[index])
//                 curr->child[index] = getNode(s[i]);
//             curr = curr->child[index];
//             ++i;
//         }
//         curr->end += 1;
//     }

//     bool Trie_search(string s, node *curr, int pos, int n)
//     {
//         if (s[pos] == '.')
//         {
//             bool res = false;
//             node *current = curr;
//             for (int i = 0; i < 26; ++i)
//             {
//                 if (pos == n - 1 && curr->child[i])
//                 {
//                     current = curr->child[i];
//                     res |= current->end > 0 ? true : false;
//                 }
//                 else if (curr->child[i] && Trie_search(s, curr->child[i], pos + 1, n))
//                     return true;
//             }
//             return res;
//         }
//         else if (curr->child[s[pos] - 'a'])
//         {
//             if (pos == n - 1)
//             {
//                 curr = curr->child[s[pos] - 'a'];
//                 return curr->end > 0 ? true : false;
//             }
//             return Trie_search(s, curr->child[s[pos] - 'a'], pos + 1, n);
//         }
//         return false;
//     }

// public:
//     /** Initialize your data structure here. */
//     WordDictionary()
//     {
//     }

//     /** Adds a word into the data structure. */
//     void addWord(string word)
//     {
//         Trie_insert(word);
//     }

//     /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//     bool search(string word)
//     {
//         return Trie_search(word, root, 0, word.size());
//     }
// };
