class Solution {
public:
    int solveRec(int ind,bool buy,vector<int>&price){
        if(ind==price.size()) return 0;
        
        if(buy){
            int buy=-price[ind]+solveRec(ind+1,0,price);
            int notBuy=solveRec(ind+1,1,price);
            return max(buy,notBuy);
        }else{
            int sell=solveRec(ind+1,1,price)+price[ind];
            int notSell=solveRec(ind+1,0,price);
            return max(sell,notSell);
        }
    }
    int solveMemo(int ind,int buy,vector<int>&price,vector<vector<long long>>&dp){
      if(ind==price.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        int profit=0;
        
        if(buy){
            profit=max(-price[ind]+solveMemo(ind+1,0,price,dp),solveMemo(ind+1,1,price,dp));
        }else{
            profit=max(price[ind]+solveMemo(ind+1,1,price,dp),solveMemo(ind+1,0,price,dp));
        }
        
       return dp[ind][buy]=profit;
    }
    int solveTabu(vector<int>&prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                 int profit=0;
        
        if(buy){
            profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
        }else{
            profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
        }
        
             dp[ind][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // return solveRec(0,1,prices);
        int n=prices.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        // return solveMemo(0,1,prices,dp);
        return solveTabu(prices);
    }
};