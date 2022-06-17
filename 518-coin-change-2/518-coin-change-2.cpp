class Solution {
public:
    int solve(int x, int n,vector<int>& coins,vector<vector<int>>& dp){
        if(x==0) return 1;
        if(x<0 || n<0) return 0;
        if(dp[x][n]!=-1) return dp[x][n];
        
     return dp[x][n]=  solve(x,n-1,coins,dp)+solve(x-coins[n],n,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
            return solve(amount,coins.size()-1,coins,dp);
    }
};