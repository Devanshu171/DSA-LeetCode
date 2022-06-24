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
      // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Cost For Tickets.
       // Memory Usage: 9.6 MB, less than 70.83% of C++ online submissions for Minimum Cost For Tickets.
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
        vector<int>dp(366);
   int k=0;
        for(int i=1;i<=365;i++){
            
            dp[i] = dp[i-1];
            if(k<n && i==days[k] ){
                dp[i]=min({dp[i-1]+costs[0],
                          dp[max(0,i-7)]+costs[1],
                          dp[max(0,i-30)]+costs[2]});
                          k++;
            }
            
        }
        return dp[365];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveRec(0,0,days,costs);
        // vector<int>dp(365+31,-1);
        // return solveMemo(0,0,days,costs,dp);
        return solveTabu(days,costs);
    }
};