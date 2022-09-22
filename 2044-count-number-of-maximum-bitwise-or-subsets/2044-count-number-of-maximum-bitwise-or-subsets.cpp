class Solution {
public:
    int solve(int ind,vector<int>&nums,int target,int Or){
        if(ind==nums.size()){
            return Or==target;
        }
        int a=solve(ind+1,nums,target,Or|nums[ind]);
        int b=solve(ind+1,nums,target,Or);
        return a+b;
    }
       int solveMemo(int ind,vector<int>&nums,int target,int Or,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return Or==target;
        }
           if(dp[ind][Or]!=-1) return dp[ind][Or];
        int a=solveMemo(ind+1,nums,target,Or|nums[ind],dp);
        int b=solveMemo(ind+1,nums,target,Or,dp);
        return dp[ind][Or]= a+b;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mOR=0;
        for(auto it:nums) mOR|=it;
       // return solve(0,nums,mOR,0);
        vector<vector<int>>dp(nums.size(),vector<int>(mOR+1,-1));
        return solveMemo(0,nums,mOR,0,dp);
    }
};