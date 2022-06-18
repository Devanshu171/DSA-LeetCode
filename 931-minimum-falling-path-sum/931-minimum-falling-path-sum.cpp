class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid){
    if(i<0 || j<0 || j==grid.size()) return INT_MAX;
    if(i==0) return grid[i][j];
    
    int up=solve(i-1,j,grid);
    int topRight=solve(i-1,j+1,grid);
    int topLeft=solve(i-1,j-1,grid);
    
    return min(up,min(topRight,topLeft))+grid[i][j];
}
int solveMemo(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i<0 || j<0 || j==grid.size()) return INT_MAX;
    if(i==0) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solveMemo(i-1,j,grid,dp);
    int topRight=solveMemo(i-1,j+1,grid,dp);
    int topLeft=solveMemo(i-1,j-1,grid,dp);
    
    return dp[i][j]= min(up,min(topRight,topLeft))+grid[i][j];
}
int solveTabu(vector<vector<int>>&grid){
    int n=grid.size();
           vector<vector<int>>dp(n,vector<int>(n,0));
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(i==0) dp[i][j]=grid[i][j];
                   else{
                       int up=INT_MAX,topRight=INT_MAX,topLeft=INT_MAX;
                        if(i>0)        up=dp[i-1][j];
                        if(i>0 && j<n-1)  topRight=dp[i-1][j+1];
                        if(i>0 && j>0)   topLeft=dp[i-1][j-1];
        
     dp[i][j]= min(up,min(topRight,topLeft))+grid[i][j];
                       
                   }
               }
           }
           int ans=INT_MAX;
           for(int i=0;i<n;i++){
               ans=min(ans,dp[n-1][i]);
           }
           return ans;

    
}
    int minFallingPathSum(vector<vector<int>>& grid) {
         int ans=INT_MAX;
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(n-1,i,grid));
        // }
         for(int i=0;i<n;i++){
            ans=min(ans,solveMemo(n-1,i,grid,dp));
        }
        return ans;
        // return solveTabu(grid);
    }
};