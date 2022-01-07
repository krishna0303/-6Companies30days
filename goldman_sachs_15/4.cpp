
/*

Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

Example 1:

Input:
str = aaaabbbccc
Output: a4b3c3
Explanation: a repeated 4 times
consecutively b 3 times, c also 3
times.




*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
    //Your code here
    int n = src.length();
    string str = "";
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (src[i - 1] != src[i])
        {
            str += src[i - 1];
            str += to_string(count);
            count = 1;
        }
        else
        {
            count += 1;
        }
    }

    str += src[n - 1];
    str += to_string(count);
    return str;
}
