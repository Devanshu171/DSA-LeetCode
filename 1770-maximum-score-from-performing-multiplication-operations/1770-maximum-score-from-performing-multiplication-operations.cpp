class Solution {
public:
    int solve(int s,int m,int e,vector<int>& nums, vector<int>& multi,vector<vector<int>>&dp){
      
        if(m==multi.size()) return 0;
        if(dp[s][m]!=INT_MIN) return dp[s][m];
        
        int f=nums[s]*multi[m]+solve(s+1,m+1,e,nums,multi,dp);
        int l=nums[e]*multi[m]+solve(s,m+1,e-1,nums,multi,dp);
        
        return dp[s][m]=max(f,l);
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        vector<vector<int>>dp(multi.size()+1,vector<int>(multi.size()+1,INT_MIN));
        return solve(0,0,nums.size()-1,nums,multi,dp);
    }
};