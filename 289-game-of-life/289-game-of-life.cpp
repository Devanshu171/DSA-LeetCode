class Solution {
public:
    int count(int x,int y,vector<vector<int>>& board){
        int di[]={1,-1,0,0,1,-1,1,-1};
        int dj[]={0,0,-1,1,1,-1,-1,1};
        int ans=0;
        for(int i=0;i<8;i++){
            int newX=x+di[i],newY=y+dj[i];
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size()){
                ans+=(board[newX][newY]==1 || board[newX][newY]==3);
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
// 3->newly dead 2->newly dead
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=count(i,j,board);
                  if(board[i][j]==0){
                    if(cnt==3) board[i][j]=2;
                }else{
                    if(cnt<2){
                        board[i][j]=3;
                    }else if(cnt==2 || cnt==3){
                            continue;
                    }else if(cnt>3){
                        board[i][j]=3;
                    }
               }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(board[i][j]==3) board[i][j]=0;
            else if(board[i][j]==2)board[i][j]=1;
            }
        }
    }
};