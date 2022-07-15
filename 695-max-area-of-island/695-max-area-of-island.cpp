class Solution {
public:
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && vis[x][y]==0);
} 

int solve(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
  int ans=0;
  
  int di[]={1,-1,0,0};
  int dj[]={0,0,1,-1};
  vis[x][y]=1;

  for(int i=0;i<4;i++){
    int newX=x+di[i];
    int newY=y+dj[i];
    if (isValid(newX, newY, n, m, grid, vis))
    {
      ans+=solve(newX,newY,n,m,grid,vis);
    }
  }

  return ans+1;
}


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
  int n=grid.size();
  int m=grid[0].size();
  vector<vector<int>>vis(n,vector<int>(m,0));
  int maxArea=0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]==1 && vis[i][j]!=1){
        int area=solve(i,j,n,m,grid,vis);
        maxArea=max(area,maxArea);
      }
    }
  }

  return maxArea;
    }
};