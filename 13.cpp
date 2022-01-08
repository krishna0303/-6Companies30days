// { Driver Code Starts
// Initial Template for C++

/*
An encoded string (s) is given, the task is to decode it. 
The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]

Example 1:

Input: s = 1[b]
Output: b
Explaination: 'b' is present only one time.
Example 2:

Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string decodedString(string s)
    {
        // code here
        stack<char> st;
        string ans = "";

        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp = "";
                while (st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string k = "";
                while (!st.empty() && isdigit(st.top()))
                {
                    k = st.top() + k;
                    st.pop();
                }
                int num = stoi(k);
                string to = "";
                // cout<<num<<endl;
                while (num != 0)
                {
                    to += temp;
                    num -= 1;
                }
                // cout<<to<<endl;
                for (int i = 0; i < to.length(); i++)
                {
                    st.push(to[i]);
                }
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
} // } Driver Code Ends