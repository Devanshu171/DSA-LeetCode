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
    int maxProfit(vector<int>& prices) {
        // return solveRec(0,1,prices);
        int n=prices.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return solveMemo(0,1,prices,dp);
    }
};