#include <bits/stdc++.h>
using namespace std;

// watch striver video for better undertsanding TC_(N^2) SC-O(N)

string getKthPermutations(int n, int k)
{
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    k = k - 1;
    string ans = "";
    while (true)
    {
        ans = ans + to_string(num[k / fact]);
        num.erase(num.begin() + (k / fact));
        if (num.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / num.size();
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getKthPermutations(n, k) << endl;

    return 0;
}