/*
Given an array of strings, return all groups of strings that are anagrams.
 The groups must be created in order of their appearance in the original array. 
Look at the sample case for clarification.

*/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        //code here
        map<string, bool> m;
        int n = string_list.size();
        vector<vector<string>> ans;
        map<string, vector<string>> temp;
        // cout<<n<<endl;
        for (int i = 0; i < n; i++)
        {
            string str = string_list[i];

            sort(str.begin(), str.end());
            if (!m[str])
            {
                m[str] = true;
                temp[str].push_back(string_list[i]);
            }
            else
            {
                temp[str].push_back(string_list[i]);
            }
        }
        for (auto it : temp)
        {
            ans.push_back(it.second);
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
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends