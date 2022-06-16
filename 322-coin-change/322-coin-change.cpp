class Solution {
public:
int solveRec(int x,vector<int>& coins){
    
      if(x==0)  return 0;
       if(x<0) return INT_MAX;

    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        mini=min(mini,solveRec(x-coins[i],coins));
    }
    
    return mini==INT_MAX?mini: 1+ mini;

    }
int solveMemo(int x,vector<int>& coins,vector<int>&dp){
    
      if(x==0)  return 0;
       if(x<0) return INT_MAX;
    
    if(dp[x]!=-1) return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        mini=min(mini,solveMemo(x-coins[i],coins,dp));
    }
    
    return dp[x]= mini==INT_MAX?mini: 1+ mini;

}
    int solveTabu(vector<int>& nums, int V){
        vector<int>dp(V+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=V;i++){
            
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-nums[j]]+1);
                
            }
        }
    }
        
        return dp[V];
        
    }
    
    int coinChange(vector<int>& nums, int V) {
        	    // vector<int>dp(V+1,-1);
          // int ans=solveRec(V,nums);
    // int ans=solveMemo(V,nums,dp);
        int ans=solveTabu(nums,V);
      
    return   ans==INT_MAX?-1:ans;
    }
};