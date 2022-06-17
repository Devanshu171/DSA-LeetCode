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
    int solveTabu(int m,int n){
                vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    
                
                int down=0,right=0;
                if(i>0)
                   down =dp[i-1][j];
                if(j>0)
                    right=dp[i][j-1];
                
                // if(i!=0 && j!=0)
                dp[i][j]=right+down;
                }
            }
        }
        return dp[m-1][n-1];

    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            // return helper(m-1,n-1,dp);
        return solveTabu(m,n);
    
    }
};