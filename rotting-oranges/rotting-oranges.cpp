struct node{
    int x,y,time;
    node(int x_,int y_,int time_){
            x=x_;
             y=y_;
             time=time_;
    }
};

class Solution {
public:
    
    bool isFresh(int x,int y,vector<vector<int>>&grid){
        
         int n=grid.size();
        int m=grid[0].size();
        
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            return true;
        else
            return false;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int cntOranges=0;
        queue<node>q;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(node(i,j,0));
                }
                if(grid[i][j]!=0) cntOranges++;
            }
        }
        
        int ans=0;
        int cnt=0;
        
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int time=q.front().time;
            q.pop();
            cnt++;
            
            ans=max(ans,time);
            int dx[]={-1,0,0,1};
            int dy[]={0,-1,1,0};
            
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                
                if(isFresh(newX,newY,grid)){
                    grid[newX][newY]=2;
                    q.push(node(newX,newY,time+1));
                }
            }
        }
        
        if(cnt==cntOranges)
            return ans;
        else
            return -1;
        
    }
};