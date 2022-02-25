class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>&board){
        board[i][j]='B';
        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};
        for(int k=0;k<4;k++){
           int col =i+di[k];
            int row=j+dj[k];
            if( col>=0 && col<n && row>=0 && row<m && board[col][row]=='O'){
                dfs(col,row,n,m,board);
            }
        }
    }
    void convert(vector<vector<char>>&board){
        int n=board.size();
        int m=board[0].size();
                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='B')
                    board[i][j]='O';
        }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        bool flag=false;
       
        
         for(int i=0;i<n;i++){
            int j=0;
                if(board[i][j]=='O')
                     dfs(i,j,n,m,board);

              j=m-1;
                if(board[i][j]=='O')
                     dfs(i,j,n,m,board);    
        }
         
            for(int j=0;j<m;j++){
                int i=n-1;
                if(board[i][j]=='O')
                      dfs(i,j,n,m,board);
                    i=0;
                if(board[i][j]=='O')
                    dfs(i,j,n,m,board);
            }
    convert(board);
        }
    
};