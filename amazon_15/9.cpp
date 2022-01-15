// { Driver Code Starts
// Initial Template for C++

//check if given sudoku configuration is valid or not
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isValidHorizontal(vector<vector<int>> mat){
        
        for(int i=0;i<9;i++){
            int arr[10]={0};
            for(int j=0;j<9;j++){
                arr[mat[i][j]]+=1;
                if(mat[i][j]!=0&&arr[mat[i][j]]>1){
                            return false;
                        }
                
            }
            // for(int k=1;k<=9;k++){
            //     if(arr[k]>1){
            //         return false;
            //     }
            // }
        }
        return true;
        
    }
    bool isValidVertical(vector<vector<int>> mat){
        for(int i=0;i<9;i++){
            int arr[10]={0};
            for(int j=0;j<9;j++){
                arr[mat[j][i]]+=1;
                if(mat[j][i]!=0&&arr[mat[j][i]]>1){
                            return false;
                        }
                
            }
            // for(int k=1;k<=9;k++){
            //     if(arr[k]>1){
            //         return false;
            //     }
            // }
        }
        return true;
        
    }
    bool isValidSquare(vector<vector<int>> mat){
        for(int i=0;i<7;i+=3){
            
            for(int j=0;j<7;j+=3){
                int arr[10]={0};
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        arr[mat[x][y]]+=1;
                        if(mat[x][y]!=0&&arr[mat[x][y]]>1){
                            return false;
                        }
                    }
                }
                
                
            }
            
        }
        return true;
        
    }
    int isValid(vector<vector<int>> mat){
        // code here
        // cout<<isValidHorizontal(mat)<<endl;
        // cout<<isValidVertical(mat)<<endl;
        // cout<<isValidSquare(mat)<<endl;
        if(isValidHorizontal(mat)&&isValidVertical(mat)&&isValidSquare(mat)){
            return 1;
        }else{
            return 0;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends