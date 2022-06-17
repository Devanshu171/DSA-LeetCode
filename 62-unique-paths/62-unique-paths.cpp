class Solution {
public:

int helper(int i,int j,int n,int m,vector<vector<int>>&dp)
{
          if(i>=m || j>=n)
             return 0;
    
        if(i==m-1 && j==n-1)  
            return 1;
    if(dp[i][j]!=-1) return dp[i][j];
     
   int l= helper(i+1,j,n,m,dp);
   int r= helper(i,j+1,n,m,dp);
    
    return dp[i][j]= l+r;
    
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            return helper(0,0,n,m,dp);
    
    }
};