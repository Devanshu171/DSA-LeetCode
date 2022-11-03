class Solution {
public:
    int dfs(int x,int y,vector<vector<int>>& grid){
      
        if(grid[x][y]==1){
            if( y+1==grid[0].size() || grid[x][y+1]==-1) return -1;
            return x==grid.size()-1?y+1: dfs(x+1,y+1,grid);
        }else{
            if( y-1==-1 || grid[x][y-1]==1) return -1;
            return  x==grid.size()-1?y-1:dfs(x+1,y-1,grid);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<m;i++){
            ans.push_back(dfs(0,i,grid));
        }
        return ans;
    }
};