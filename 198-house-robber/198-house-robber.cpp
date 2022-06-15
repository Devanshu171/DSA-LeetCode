class Solution {
public:
    int  solve(vector<int> &arr,int n,vector<int>&dp){

            if(n==0) return arr[n];
                if(dp[n]!=-1) return dp[n];
            
            int fs=arr[n];
            if(n>1){
                fs+=solve(arr,n-2 ,dp);
            }
            int ss=solve(arr,n-1,dp);
            
            return dp[n]=max(fs,ss);
            
        }
    int rob(vector<int>& nums) {
            int n=nums.size();
    
             vector<int>dp(n,-1);   
        return solve(nums,n-1,dp);
    }
};