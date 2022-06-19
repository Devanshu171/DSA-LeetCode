class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        queue<pair<int,pair<int,int>>>q;
        vector<vector<vector<int>>>vis(k+1,vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),0)));
        q.push({k,{0,0}});
        vis[k][0][0]=1;
    
        int path=0;
        
        while(!q.empty()){
            int n=q.size();
          
            
            for(int i=0;i<n;i++){
                int k=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                  bool flag=false;
                q.pop();
                if(x==grid.size()-1 && y==grid[0].size()-1) return path;
                if(grid[x][y]==1){
                 if(k>0)  k--;
                  else continue;  
                }
  
                int di[]={0,0,1,-1};
                int dj[]={1,-1,0,0};
                
                for(int i=0;i<4;i++){
                    int newX=di[i]+x;
                    int newY=dj[i]+y;
                    if(newX>=0 && newY>=0 && newX<grid.size() && newY<grid[0].size() && vis[k][newX][newY]!=1){
                        vis[k][newX][newY]=1;
                            q.push({k,{newX,newY}});
                    }
                }
                
            }
           
            path++;
        }
        
        return -1;
    }
};