#include <bits/stdc++.h>
using namespace std;

/*

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

*/
/*

this is brute force it uses extra 2d matrix space to copy the initial matrix
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        if(i<0||j<0||i>=n||j>=m){
            return false;
        }
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        // vector<vector<int>>copy=board;
        int dx[]={1,1,0,-1,-1,-1,0,1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>copy=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int liveCount=0;
                for(int k=0;k<8;k++){
                    if(isSafe(i+dx[k],j+dy[k],n,m)&&copy[i+dx[k]][j+dy[k]]==1){
                        liveCount+=1;
                    }
                }
                if(copy[i][j]==0&&liveCount==3){
                    board[i][j]=1;

                }
                if(copy[i][j]==1&&(liveCount<2||liveCount>3)){
                    board[i][j]=0;
                }

            }

        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j]==-1){
        //             board[i][j]=0;
        //         }
        //         if(board[i][j]==2){
        //             board[i][j]=1;
        //         }
        //     }
        // }

    }
};

*/

// this is efficient approach to solve this problem in place
class Solution
{
public:
    bool isSafe(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return false;
        }
        return true;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        // vector<vector<int>>copy=board;
        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int liveCount = 0;
                for (int k = 0; k < 8; k++)
                {
                    if (isSafe(i + dx[k], j + dy[k], n, m) && abs(board[i + dx[k]][j + dy[k]]) == 1)
                    {
                        liveCount += 1;
                    }
                }
                if (board[i][j] == 0 && liveCount == 3)
                {
                    board[i][j] = 2;
                }
                if (board[i][j] == 1 && (liveCount < 2 || liveCount > 3))
                {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};