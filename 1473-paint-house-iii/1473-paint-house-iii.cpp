class Solution {
public:
    int solveRec(int ind,int prev,vector<int>& houses, vector<vector<int>>& cost,int target){
        if(target<0) return 1e8;
        if(ind==-1 && target==0) return 0;
        if(ind==-1 && target!=0) return 1e8;
        
        
        if(houses[ind]!=0 && prev==houses[ind]) return solveRec(ind-1,houses[ind],houses,cost,target);
        if(houses[ind]!=0 && prev!=houses[ind]) return solveRec(ind-1,houses[ind],houses,cost,target-1);
        int ans=1e8;
        for(int i=1;i<=cost[0].size();i++){
            if(i==prev) ans=min(ans,solveRec(ind-1,i,houses,cost,target)+cost[ind][i-1]);
            else ans=min(ans,solveRec(ind-1,i,houses,cost,target-1)+cost[ind][i-1]);
        }
        return ans;
        
    }
        int solveMemo(int ind,int prev,vector<int>& houses, vector<vector<int>>& cost,int target,vector<vector<vector<int>>>&dp){
        if(target<0) return 1e8;
        if(ind==-1 && target==0) return 0;
        if(ind==-1 && target!=0) return 1e8;
        if(dp[ind][prev][target]!=-1) return dp[ind][prev][target];
        
        if(houses[ind]!=0 && prev==houses[ind]) return dp[ind][prev][target]= solveMemo(ind-1,houses[ind],houses,cost,target,dp);
        if(houses[ind]!=0 && prev!=houses[ind]) return dp[ind][prev][target]=solveMemo(ind-1,houses[ind],houses,cost,target-1,dp);
        int ans=1e8;
        for(int i=1;i<=cost[0].size();i++){
            if(i==prev) ans=min(ans,solveMemo(ind-1,i,houses,cost,target,dp)+cost[ind][i-1]);
            else ans=min(ans,solveMemo(ind-1,i,houses,cost,target-1,dp)+cost[ind][i-1]);
        }
        return dp[ind][prev][target]=ans;
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // int ans= solveRec(m-1,n+1,houses,cost,target);
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n+2,vector<int>(target+1,-1)));
                int ans= solveMemo(m-1,n+1,houses,cost,target,dp);

        return ans==1e8?-1:ans;
    }
};