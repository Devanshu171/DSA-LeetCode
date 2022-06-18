class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0) return INT_MAX ;
        if(i==0 && j==0) return grid[i][j];
        
        int up=solve(i-1,j,grid);
        int left=solve(i,j-1,grid);
        
        return min(up,left)+grid[i][j];
    }
    int solveMemo(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0) return INT_MAX ;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=solveMemo(i-1,j,grid,dp);
        int left=solveMemo(i,j-1,grid,dp);
        
        return dp[i][j]= min(up,left)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,grid);
        return solveMemo(m-1,n-1,grid,dp);
    }
};