class Solution {
public:
//         int solveRec(int ind,int buy,int trans,vector<int>&prices){
//         if(ind==prices.size()) return 0;
//         if(trans==0) return 0;
        
//         int profit=0;
//         if(buy){
//              profit=max(-prices[ind]+solveRec(ind+1,0,trans,prices),solveRec(ind+1,1,trans,prices));
//         }else{
//              profit=max(prices[ind]+solveRec(ind+1,1,trans-1,prices),solveRec(ind+1,0,trans,prices));
//         }
//         return profit;
//     }
//      int solveMemo(int ind,int buy,int trans,vector<int>&prices,vector<vector<vector<int>>>&dp){
//         if(ind==prices.size()) return 0;
//         if(trans==0) return 0;
//         if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];
//         int profit=0;
//         if(buy){
//              profit=max(-prices[ind]+solveMemo(ind+1,0,trans,prices,dp),solveMemo(ind+1,1,trans,prices,dp));
//         }else{
//              profit=max(prices[ind]+solveMemo(ind+1,1,trans-1,prices,dp),solveMemo(ind+1,0,trans,prices,dp));
//         }
//         return dp[ind][buy][trans]= profit;
//     }
//     int solveTabu(int k ,vector<int>&prices){
//         int n=prices.size();
//                 vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<2;buy++){
//                 for(int trans=k;trans>=1;trans--){
//                       int profit=0;
//         if(buy){
//              profit=max(-prices[ind]+dp[ind+1][0][trans],dp[ind+1][1][trans]);
//         }else{
//              profit=max(prices[ind]+dp[ind+1][1][trans-1],dp[ind+1][0][trans]);
//         }
//          dp[ind][buy][trans]= profit;
//                 }
//             }
//         }
//         return dp[0][1][k];

//     }
//       int solveTabuSo(int k,vector<int>&prices){
//         int n=prices.size();
//                vector<vector<int>>next(2,vector<int>(k+1,0));
//         vector<vector<int>>cur(2,vector<int>(k+1,0));
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<2;buy++){
//                 for(int trans=k;trans>=1;trans--){
//                       int profit=0;
//         if(buy){
//              profit=max(-prices[ind]+next[0][trans],next[1][trans]);
//         }else{
//              profit=max(prices[ind]+next[1][trans-1],next[0][trans]);
//         }
//          cur[buy][trans]= profit;
//                 }
//             }
//             swap(cur,next);
//         }
//         return next[1][k];

//     }
    int solveMemo(int ind,vector<int>&prices,int k,bool buy,vector<vector<vector<int>>>&dp){
            if(k==0 || ind==prices.size()){
                return 0;
            }
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solveMemo(ind+1,prices,k,false,dp),solveMemo(ind+1,prices,k,true,dp));
        }else{
            profit=max(prices[ind]+solveMemo(ind+1,prices,k-1,true,dp),solveMemo(ind+1,prices,k,false,dp));
            
        }
        return dp[ind][buy][k]= profit;
        
    }

    int maxProfit(int k, vector<int>& prices) {
            int n=prices.size();
     // return solveRec(0,1,k,prices);
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solveMemo(0,1,k,prices,dp);
        // return solveTabu(k,prices);
        // return solveTabuSo(k,prices);
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveMemo(0,prices,k,true,dp);
    }
};