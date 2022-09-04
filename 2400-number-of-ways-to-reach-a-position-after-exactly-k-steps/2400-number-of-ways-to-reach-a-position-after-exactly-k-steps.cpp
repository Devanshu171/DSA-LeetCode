class Solution {
public:
    #define mod 1000000007
   
    int solveMemo(int s,int end,int k,vector<vector<int>>&dp){
        if(k==0 ) { 
            if(end==s) return 1;
            else return 0;
            }
        // if(abs(end-s)>k){
        //     return 0;
        // }
        // if(s<0){
        //     if(abs(s-end)>k) return 0;
        // }
        if(dp[s][k]!=-1) return dp[s][k];
          return  dp[s][k]=(solveMemo(s+1,end,k-1,dp)%mod+solveMemo(s-1,end,k-1,dp)%mod)%mod;
    }
    
    int numberOfWays(int s, int e, int k) {
        if(abs(s-e)>k) return 0;
        s+=2000;
        e+=2000;
   
        vector<vector<int>>dp(5000,vector<int>(k+1,-1));
        
        int ans=solveMemo(s,e,k,dp);
        
        return ans;
    }
};