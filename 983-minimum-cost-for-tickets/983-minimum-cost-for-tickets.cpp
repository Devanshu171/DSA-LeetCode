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
     int solveMemo(int ind,int pass,vector<int>&days,vector<int>&costs,vector<vector<int>>&dp){
      
       if(ind>=days.size()) return 0;
        if(dp[ind][pass]!=-1) return dp[ind][pass];
        if(pass<days[ind]){

     int pass1=solveMemo(ind+1,days[ind],days,costs,dp)+costs[0];
     int pass2=solveMemo(ind+1,days[ind]+6,days,costs,dp)+costs[1];
     int pass3=solveMemo(ind+1,days[ind]+29,days,costs,dp)+costs[2];
            return  dp[ind][pass]=min(pass1,min(pass2,pass3));
            
        }
        return dp[ind][pass]=solveMemo(ind+1,pass,days,costs,dp);
  
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveRec(0,0,days,costs);
        vector<vector<int>>dp(days.size(),vector<int>(365+31,-1));
        return solveMemo(0,0,days,costs,dp);
    }
};