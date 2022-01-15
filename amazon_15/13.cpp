/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkGrid(vector<vector<int>> grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int count = 0;
        bool flag = false;
        vector<vector<int>> temp;

        for (int x = 0; x < grid.size(); x++)
        {
            vector<int> v;
            for (int y = 0; y < grid[0].size(); y++)
            {
                v.push_back(0);
            }
            temp.push_back(v);
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                bool flag1 = false;

                for (int x = 0; x < grid.size(); x++)
                {

                    for (int y = 0; y < grid[0].size(); y++)
                    {
                        if (grid[x][y] == 1)
                        {
                            if ((x - 1) >= 0 && grid[x - 1][y] == 2)
                            {
                                temp[x][y] = 2;
                            }
                            else if ((y + 1) < grid[0].size() && grid[x][y + 1] == 2)
                            {
                                temp[x][y] = 2;
                            }
                            else if ((x + 1) < grid.size() && grid[x + 1][y] == 2)
                            {
                                temp[x][y] = 2;
                            }
                            else if ((y - 1) >= 0 && grid[x][y - 1] == 2)
                            {
                                temp[x][y] = 2;
                            }
                            else
                            {
                                temp[x][y] = grid[x][y];
                            }
                            flag1 = true;
                        }
                        else
                        {
                            temp[x][y] = grid[x][y];
                        }
                    }
                }
                for (int x = 0; x < grid.size(); x++)
                {

                    for (int y = 0; y < grid[0].size(); y++)
                    {
                        grid[x][y] = temp[x][y];
                    }
                }
                if (flag1)
                {
                    count += 1;
                }

                if (checkGrid(temp))
                {
                    flag = true;
                    // cout<<"krishna"<<endl;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            return count;
        }
        else
        {
            return -1;
        }
    }
};