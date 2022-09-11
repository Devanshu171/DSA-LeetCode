class Solution {
public:
    int count(int x,int y,vector<vector<int>>& board){
        int di[]={1,-1,0,0,1,-1,1,-1};
        int dj[]={0,0,-1,1,1,-1,-1,1};
        int ans=0;
        for(int i=0;i<8;i++){
            int newX=x+di[i],newY=y+dj[i];
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size()){
                ans+=board[newX][newY];
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>countn(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=count(i,j,board);
                countn[i][j]=cnt;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    if(countn[i][j]==3) board[i][j]=1;
                }else{
                    if(countn[i][j]<2){
                        board[i][j]=0;
                    }else if(countn[i][j]==2 || countn[i][j]==3){
                            continue;
                    }else if(countn[i][j]>3){
                        board[i][j]=0;
                    }
               }
            }
        }
    }
};