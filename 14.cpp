/*
Given an array of positive integers nums and a positive integer target,
 return the minimal length of a contiguous subarray [numsl, numsl+1, ..., 
 numsr-1, numsr] of which the sum is greater than or equal to target. 
 If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int ans = INT_MAX;
        int i = 0, j = 0;
        long long int sum = 0;
        bool flag = false;
        while (i <= j && (j < nums.size() || i < nums.size()))
        {

            if (sum == target)
            {
                ans = min(ans, (j - i));
                flag = true;
                if (j < nums.size())
                {
                    sum += nums[j];
                    j++;
                }
                else
                {
                    break;
                }
            }
            else if (sum > target)
            {
                ans = min(ans, (j - i));
                flag = true;
                sum -= nums[i];
                i++;
            }
            else
            {

                if (j < nums.size())
                {
                    sum += nums[j];
                    j++;
                }
                else
                {
                    break;
                }
            }
            // cout<<sum<<endl;
        }
        if (flag)
        {
            return ans;
        }
        else
        {
            return 0;
        }
    }
};