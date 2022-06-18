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
    
    int solveTabu(int m,int n,vector<vector<int>>& grid){
        
    vector<vector<int>>dp(m,vector<int>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                   dp[i][j]= min(up,left)+grid[i][j];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    int solveTabuSo(int m,int n,vector<vector<int>>& grid){
        
    vector<int>prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int>cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) cur[j]=grid[i][j];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                   cur[j]= min(up,left)+grid[i][j];
                }
            }
            prev=cur;
        }
        
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,grid);
        // return solveMemo(m-1,n-1,grid,dp);
        // return solveTabu(m,n,grid);
        return solveTabuSo(m,n,grid);
    }
};