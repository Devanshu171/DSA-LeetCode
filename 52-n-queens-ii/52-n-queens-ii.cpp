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
    int count=0;
      int nqueen(int col,vector<string>&temp,int n)
    {
        if(col==n)
        {
            // mat.push_back(temp);
                count++;
        }
        
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,temp,n)){
                temp[row][col]='Q';
                nqueen(col+1,temp,n);
                temp[row][col]='.';
            }
        }
        return count;
    }
    
    int totalNQueens(int n) {
         // vector<vector<string>>mat;
        if(n==3 || n==0 ||n==2)
            return 0;
        vector<string>temp(n,string(n,'.'));
       return nqueen(0,temp,n);
        
    }
};