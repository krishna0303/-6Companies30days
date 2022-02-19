#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int k = q.size();

            bool flag = false;
            for (int x = 0; x < k; x++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if (i - 1 >= 0 && (arr[i - 1][j] == 1))
                {
                    arr[i - 1][j] = 2;
                    q.push({i - 1, j});
                    flag = true;
                }
                if (i + 1 < n && (arr[i + 1][j] == 1))
                {
                    arr[i + 1][j] = 2;
                    q.push({i + 1, j});
                    flag = true;
                }
                if (j - 1 >= 0 && (arr[i][j - 1] == 1))
                {
                    arr[i][j - 1] = 2;
                    q.push({i, j - 1});
                    flag = true;
                }
                if (j + 1 < m && (arr[i][j + 1] == 1))
                {
                    arr[i][j + 1] = 2;
                    q.push({i, j + 1});
                    flag = true;
                }
            }
            if (flag)
            {
                count += 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};