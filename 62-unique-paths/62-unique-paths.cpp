class Solution {
public:

int helper(int i,int j,vector<vector<int>>&dp)
{
          if(i<0 || j<0)
             return 0;
    
        if(i==0 && j==0)  
            return 1;
    if(dp[i][j]!=-1) return dp[i][j];
     
   int l= helper(i-1,j,dp);
   int r= helper(i,j-1,dp);
    
    return dp[i][j]= l+r;
    
}
    int solveTabu(int n,int m){
                vector<vector<int>>dp(m+1,vector<int>(n+1,1));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            // return helper(m-1,n-1,dp);
        return solveTabu(n,m);
    
    }
};