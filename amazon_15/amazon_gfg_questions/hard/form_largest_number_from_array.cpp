// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    /*

    A simple solution that comes to our mind is to sort all numbers in descending order, but simply sorting doesn’t work. For example, 548 is greater than 60, but in output 60 comes before 548. As a second example, 98 is greater than 9, but 9 comes before 98 in output.

So how do we go about it? The idea is to use any comparison based sorting algorithm.
In the used sorting algorithm, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.

Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example,
let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.

    */
    static bool compare(const string &s1, const string &s2)
    {
        return s1 + s2 > s2 + s1;
    }
    string printLargest(vector<string> &arr)
    {
        // code here
        // sort(s.begin(),s.end(),greater<string>());
        sort(arr.begin(), arr.end(), compare);
        string ans = "";
        // string prev=s[0];
        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
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
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends