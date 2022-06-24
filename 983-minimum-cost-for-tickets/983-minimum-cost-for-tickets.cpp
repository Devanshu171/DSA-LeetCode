class Solution {
public:
    int solveRec(int ind,int pass,vector<int>&days,vector<int>&costs){
      
       if(ind>=days.size()) return 0;
        
        if(pass<days[ind]){

     int pass1=solveRec(ind+1,days[ind],days,costs)+costs[0];
     int pass2=solveRec(ind+1,days[ind]+6,days,costs)+costs[1];
     int pass3=solveRec(ind+1,days[ind]+29,days,costs)+costs[2];
            return min(pass1,min(pass2,pass3));
            
        }
        return solveRec(ind+1,pass,days,costs);
  
        
    }
     int solveMemo(int ind,int pass,vector<int>&days,vector<int>&costs,vector<int>&dp){
      
       if(ind>=days.size()) return 0;
        if(dp[pass]!=-1) return dp[pass];
        if(pass<days[ind]){
 
     int pass1=solveMemo(ind+1,days[ind],days,costs,dp)+costs[0];
     int pass2=solveMemo(ind+1,days[ind]+6,days,costs,dp)+costs[1];
     int pass3=solveMemo(ind+1,days[ind]+29,days,costs,dp)+costs[2];
            return  dp[pass]=min(pass1,min(pass2,pass3));
            
        }
        return dp[pass]=solveMemo(ind+1,pass,days,costs,dp);
  
        
    }
    int solveTabu(vector<int>& days, vector<int>& costs){
        int n=days.size();
        vector<vector<int>>dp(n+1,vector<int>(365+31,1e8));
        for(int i=0;i<=365+30;i++) dp[n+1][i]=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int pass=365;pass>=0;pass--){
                 if(pass<days[ind]){
                
                     int pass1=dp[ind+1][days[ind]]+costs[0];
                     int pass2=dp[ind+1][days[ind]+6]+costs[1];
                     int pass3=dp[ind+1][days[ind]+29]+costs[2];
                
              dp[ind][pass]=min(pass1,min(pass2,pass3));
            
        }
         // dp[ind][pass]=solveMemo(ind+1,pass,days,costs,dp);
            }
        }
        return dp[0][0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveRec(0,0,days,costs);
        vector<int>dp(365+31,-1);
        return solveMemo(0,0,days,costs,dp);
        // return solveTabu(days,costs);
    }
};