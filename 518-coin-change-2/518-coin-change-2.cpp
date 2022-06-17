class Solution {
public:
//     int solve(int x, int n,vector<int>& coins,vector<vector<int>>& dp){
//         if(x==0) return 1;
//         if(x<0 || n<0) return 0;
//         if(dp[x][n]!=-1) return dp[x][n];
        
//      return dp[x][n]=  solve(x,n-1,coins,dp)+solve(x-coins[n],n,coins,dp);
//     }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        
            // return solve(amount,coins.size()-1,coins,dp);
        for(int i=0;i<=coins.size();i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[coins.size()][amount];
    }
};