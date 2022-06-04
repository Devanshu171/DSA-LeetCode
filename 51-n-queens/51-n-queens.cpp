class Solution {
public:
    
    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        int i=row,j=col-1;
        for(;i>=0;i--){
            if(board[i][col]==1)
                return false;
        }
        i=row-1,j=col+1;
        for(;i>=0 && j<n;i--,j++){
            if(board[i][j]==1)
                return false;
        }
        i=row-1,j=col-1;
    for(;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
            return false;
    }
        
        return true;
    }
    void nQueen(int row,int n,vector<vector<int>>&board,vector<vector<string>> &ans,vector<string>&vec){
        
        if(row==n){
            ans.push_back(vec);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                        vec[row][col]='Q';
                    board[row][col]=1;
                nQueen(row+1,n,board,ans,vec);
                        vec[row][col]='.';
                    board[row][col]=0;
                                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<string>vec(n,string(n,'.'));
        nQueen(0,n,board,ans,vec);
        return ans;
    }
};