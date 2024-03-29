class Solution {
public:
     int solveRec(int ind,bool buy,int cd,vector<int>&price){
        if(ind==price.size()) return 0;
        if(cd) return solveRec(ind+1,buy,0,price);
        if(buy){
            int buy=-price[ind]+solveRec(ind+1,0,0,price);
            int notBuy=solveRec(ind+1,1,0,price);
            return max(buy,notBuy);
        }else{
            int sell=solveRec(ind+1,1,1,price)+price[ind];
            int notSell=solveRec(ind+1,0,0,price);
            return max(sell,notSell);
        }
    }
    int solveMemo(int ind,int buy,int cd,vector<int>&price,vector<vector<vector<int>>>&dp){
      if(ind==price.size()) return 0;
        
        if(dp[ind][buy][cd]!=-1) return dp[ind][buy][cd];
        
        if(cd) return solveMemo(ind+1,buy,0,price,dp);

        
        int profit=0;
        
        if(buy){
            profit=max(-price[ind]+solveMemo(ind+1,0,0,price,dp),solveMemo(ind+1,1,0,price,dp));
        }else{
            profit=max(price[ind]+solveMemo(ind+1,1,1,price,dp),solveMemo(ind+1,0,0,price,dp));
        }
        
       return dp[ind][buy][cd]=profit;
    }
    int solveTabu(vector<int>&prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cd=1;cd>=0;cd--){
                 int profit=0;
                if(cd) profit= dp[ind+1][buy][0];

                   else if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][0],dp[ind+1][1][0]);
                    }else{
                        profit=max(prices[ind]+dp[ind+1][1][1],dp[ind+1][0][0]);
                    }
        
                     dp[ind][buy][cd]=profit;
                }
            }
                
        }
        
        return dp[0][1][0];
    }
     int solveTabuSo(vector<int>&prices){
        int n=prices.size();
       vector<vector<int>>cur(2,vector<int>(2,0));
                vector<vector<int>>next(2,vector<int>(2,0));

        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cd=1;cd>=0;cd--){
                 int profit=0;
                if(cd) profit= next[buy][0];

                   else if(buy){
                        profit=max(-prices[ind]+next[0][0],next[1][0]);
                    }else{
                        profit=max(prices[ind]+next[1][1],next[0][0]);
                    }
        
                     cur[buy][cd]=profit;
                }
            }
            swap(cur,next);
                
        }
        
        return next[1][0];
    }
   
    int maxProfit(vector<int>& prices) {
        // return solveRec(0,1,0,prices);
        // int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        // return solveMemo(0,1,0,prices,dp);
        // return solveTabu(prices);
                return solveTabuSo(prices);

    }
    
};