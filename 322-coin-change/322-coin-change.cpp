class Solution {
public:
    	int solve(int x,vector<int>& coins,vector<int>&dp){
    
      if(x==0)  return 0;
       if(x<0) return INT_MAX;
    
    if(dp[x]!=-1) return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        mini=min(mini,solve(x-coins[i],coins,dp));
    }
    
    return dp[x]= mini==INT_MAX?mini: 1+ mini;

}
    int coinChange(vector<int>& nums, int V) {
        	    vector<int>dp(V+1,-1);
    int ans=solve(V,nums,dp);
    return   ans==INT_MAX?-1:ans;
    }
};