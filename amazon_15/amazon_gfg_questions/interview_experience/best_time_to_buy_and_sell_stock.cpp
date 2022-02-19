#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = INT_MIN;
        int minm = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minm > prices[i])
            {
                minm = prices[i];
            }
            else
            {
                profit = max(profit, (prices[i] - minm));
            }
        }
        if (profit == INT_MIN)
        {
            return 0;
        }
        return profit;
    }
};