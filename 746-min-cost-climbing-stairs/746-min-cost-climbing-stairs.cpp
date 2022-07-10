class Solution {
public:
    
    /*
    
           --------- solution 1 simple recursion-------
           ************* bottom to top********
    
            void solve(int i,int total,int n,vector<int>&cost,int &ans){
        if(i>=n){
         if(i==n)   ans=min(ans,total);
            return;
        }
        
        if(i>=0) total+=cost[i];
        solve(i+1,total,n,cost,ans);
        solve(i+2,total,n,cost,ans);
    }
   
    int minCostClimbingStairs(vector<int>& cost) {
        int ans=INT_MAX;
        solve(-1,0,cost.size(),cost,ans);
        solve(0,0,cost.size(),cost,ans);
        return ans;
        
    }
    
    
    ***********Recursion Top to Bottom aproach**********
     int solve(int n,vector<int>&cost){
       if(n==1 || n==0) return cost[n];
        int left=solve(n-1,cost);
        int right=solve(n-2,cost);
        return min(left,right)+cost[n];
        
    }
   
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=min(solve(n-1,cost),solve(n-2,cost));
        return ans;
        
    }
        
        
        *************DP MEMOIZATION*************
        top down 
    int solve(int n,vector<int>&cost,vector<int>&dp){
        
        if(dp[n]!=-1) return dp[n];
       if(n==1 || n==0) return cost[n];
        dp[n-1]=solve(n-1,cost,dp);
        dp[n-2]=solve(n-2,cost,dp);
        return dp[n]=min(dp[n-1],dp[n-2])+cost[n];
        
    }
   
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
dp[n]=min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        return dp[n];
        
    }
    
    ********** tablution DP*************
                bottom up
                1d array
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
                return min(dp[n-1],dp[n-2]);
        
    }
    
    
    */

//     ********* tablution with O(1) space
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        int prev1=cost[1];
        int prev2=cost[0];
        for(int i=2;i<n;i++){
            int cur=min(prev2,prev1)+cost[i];
            prev2=prev1;
            prev1=cur;
        }
            return min(prev2,prev1);
        
    }
};