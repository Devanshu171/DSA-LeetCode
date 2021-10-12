class Solution {
public:
    
    bool issafe(int row,int col,vector<string>&temp,int n)
    {
        
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {   
            if(temp[i][j]=='Q')
            return false;
        }
        for(int i=row,j=col;j>=0;j--)
        {   
            if(temp[i][j]=='Q')
            return false;
        }
        for(int i=row,j=col;i<n&&j>=0;i++,j--)
        {   
            if(temp[i][j]=='Q')
            return false;
        }
        
        return true;
    }
    void nqueen(int col,vector<vector<string>>&mat,vector<string>&temp,int n)
    {
        if(col==n)
        {
            mat.push_back(temp);
                return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,temp,n)){
                temp[row][col]='Q';
                nqueen(col+1,mat,temp,n);
                temp[row][col]='.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>mat;
        vector<string>temp(n,string(n,'.'));
        nqueen(0,mat,temp,n);
        return mat;
    }
};