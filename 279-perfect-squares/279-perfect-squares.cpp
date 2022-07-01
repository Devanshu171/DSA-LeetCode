class Solution {
public:
    int solveRec(int n){
            if(n==0) return 0;
        if(n<0) return 1e8;
        
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            ans=min(ans,solveRec(n-i*i)+1);
        }
        
        return ans;
    }
    int solveMemo(int n,vector<int>&dp){
            if(n==0) return 0;
        if(n<0) return 1e8;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,solveMemo(n-i*i,dp)+1);
        }
        
        return dp[n]=ans;
    }
    int solveTabu(int n){
          vector<int>dp(n+1,1e8);
        
        dp[0]=0;
        for(int i=1;i<=n;i++){
     
             for(int j=1;j<=n;j++){
          if(j*j<=i) dp[i]=min(dp[i],dp[n-j*j]+1);
            }
        
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        // return solveRec(n);
        return solveMemo(n,dp);
        return solveTabu(n);

    }
};