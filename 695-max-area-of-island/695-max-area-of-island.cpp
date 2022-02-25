class Solution {
public:
    bool isvalid(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i>=0 && i<n && j<m && j>=0 && grid[i][j]==1) return true;
        return false;
    }
    void dfs(int i,int j,int n,int m,int &area,vector<vector<int>>&grid){
        area++;
        grid[i][j]=2;
        int di[]={1,-1,0,0};
        int dj[]={0,0,-1,1};
        
        for(int k=0;k<4;k++){
            int col=i+di[k];
            int row=j+dj[k];
            if(isvalid(col,row,n,m,grid)){
                dfs(col,row,n,m,area,grid);
            }
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;
                if(grid[i][j]==1){
                    dfs(i,j,n,m,area,grid);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};