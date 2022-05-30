class Solution {
public:
    
    void getCordinates(int n,int x,int &row,int &col){
         row=n-1-(x-1)/n;
         col=(x-1)%n;
        
        if((n%2==0 && row%2==0)|| (n%2!=0 && row%2!=0)){
            col=n-1-col;
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n=board.size();
        vector<int>vis(n*n+1,0);
        vis[1]=1;
        queue<int>q;
        q.push(1);
        
        int steps=0;
        while(!q.empty()){
            int m=q.size();
            for(int j=0;j<m;j++){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
            int row,col;
            
            for(int i=1;i<=6;i++){
                if(x+i>n*n)
                    break;
                getCordinates(n,x+i,row,col);
                
                int pos=board[row][col]==-1?i+x:board[row][col];
                
                if(!vis[pos]){
                    vis[pos]=1;
                    q.push(pos);
                }
            }
        }
            steps++;
        }
        
        return -1;
    }
};