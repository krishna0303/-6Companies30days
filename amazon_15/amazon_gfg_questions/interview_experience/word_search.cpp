
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool visited[7][7];
    bool solve(vector<vector<char>>& board,int i,int j,int k,string word){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]||board[i][j]!=word[k]){
            return false;
        }
        k++;
        visited[i][j]=true;
        if(k==word.length()){
            return true;
        }
        bool ans1= solve(board,i+1,j,k,word);
        bool ans2=solve(board,i,j+1,k,word);
        bool ans3=solve(board,i-1,j,k,word);
        bool ans4=solve(board,i,j-1,k,word);
        visited[i][j]=false;
        if(ans1||ans2||ans3||ans4){
            return true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                visited[i][j]=false;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(board,i,j,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};