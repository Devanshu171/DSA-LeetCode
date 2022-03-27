class Solution {
public:
    bool findEmptyCell(vector<vector<char>>& board,int &row,int &col){
        for(row=0;row<9;row++){
            for(col=0;col<9;col++){
                if(board[row][col]=='.')
                    return true;
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,int row,int col,int num){
        char x=num+'0';
        // cout<<x<<endl;
        for(int i=0;i<9;i++){
            if(board[row][i]==x)
                return false;
            if(board[i][col]==x)
                return false;
        }
        int rowfact=(row/3)*3,colfact=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[rowfact+i][colfact+j]==x)
                    return false;
            }
        }
        return true;
    }
    bool sudokuHelper(vector<vector<char>>& board){
        int row,col;
        if(!findEmptyCell(board,row,col)){
                return true;
        }
      
        for(int i=1;i<=9;i++){
            if(isValid(board,row,col,i)){
                // char x=;
                board[row][col]=(i+'0');
                if(sudokuHelper(board)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuHelper(board);
    }
};