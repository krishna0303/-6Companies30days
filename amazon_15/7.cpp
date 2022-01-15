// { Driver Code Starts

/*

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'


best tricky part is 
map (like set) is an ordered sequence of unique keys whereas in unordered_map key can be stored in any order,
so unordered.The map is implemented as a balanced tree structure that is why it is possible to maintain order
between the elements (by specific tree traversal). 

............The time complexity of map operations is O(log n) while for unordered_map, it is O(1) on average. 


*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        // Code here
        unordered_map<char, int> m;
        char firstN = '#';
        string ans = "";
        int i = 0, j = 0;
        int n = s.length();
        queue<char> q;
        while (j < n)
        {
            if (m.find(s[j]) == m.end())
            {

                m[s[j]] = 1;
                q.push(s[j]);

                if (firstN == '#')
                {

                    while (!q.empty())
                    {
                        char top = q.front();
                        q.pop();
                        if (m[top] == 1)
                        {
                            firstN = top;
                            break;
                        }
                    }
                }
                s[j] = firstN;
                j++;
            }
            else
            {
                m[s[j]] += 1;
                if (s[j] == firstN)
                {
                    bool flag = false;
                    while (!q.empty())
                    {
                        char top = q.front();
                        q.pop();
                        if (m[top] == 1)
                        {
                            flag = true;
                            firstN = top;
                            break;
                        }
                    }
                    if (!flag)
                    {

                        firstN = '#';
                    }
                }
                s[j] = firstN;
                j++;
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends