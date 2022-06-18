class Solution {
public:
      int solve(int i,int j,vector<vector<int>>&grid){
    
    if(i==0) return grid[i][j];
          
    int ans=INT_MAX;
   for(int l=0;l<grid.size();l++ ){
       if(l!=j)
       ans=min(ans,solve(i-1,l,grid));
   }
    return ans==INT_MAX?ans:ans+grid[i][j];
}
int solveMemo(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
   
    if(i==0) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
  int ans=INT_MAX;
   for(int l=0;l<grid.size();l++ ){
       if(l!=j)
       ans=min(ans,solveMemo(i-1,l,grid,dp));
   }
    return dp[i][j]= ans==INT_MAX?ans:ans+grid[i][j];
}
int solveTabu(vector<vector<int>>&grid){
    int n=grid.size();
           vector<vector<int>>dp(n,vector<int>(n,0));
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(i==0) dp[i][j]=grid[i][j];
                   else{
                     int ans=INT_MAX;
           for(int l=0;l<grid.size();l++ ){
               if(l!=j)
               ans=min(ans,dp[i-1][l]);
           }
         dp[i][j]= ans==INT_MAX?ans:ans+grid[i][j];
                       
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
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(n-1,i,grid));
        // }
        //  for(int i=0;i<n;i++){
        //     ans=min(ans,solveMemo(n-1,i,grid,dp));
        // }
        // return ans;
        return solveTabu(grid);
    }
};