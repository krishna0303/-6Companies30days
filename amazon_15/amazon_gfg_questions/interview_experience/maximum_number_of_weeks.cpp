#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        long long sum = 0;
        int maxm = 0;
        for (int i = 0; i < milestones.size(); i++)
        {
            sum += milestones[i];
            maxm = max(maxm, milestones[i]);
        }
        long long rem = sum - maxm;
        if (maxm > (rem + 1))
        {
            return (2 * rem + 1);
        }
        return sum;
    }
}