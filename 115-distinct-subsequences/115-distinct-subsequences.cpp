class Solution {
public:
    int solveRec(int ind1,int ind2,string s,string t){
        if(ind2==-1){
            return 1;
        }
        if(ind1==-1){
            return 0;
        }
        
        if(s[ind1]==t[ind2]){
            int notPick=solveRec(ind1-1,ind2,s,t);
            int pick=solveRec(ind1-1,ind2-1,s,t);
            return pick+notPick;
        }else{
            return solveRec(ind1-1,ind2,s,t);
        }
    }
     int solveMemo(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind2==-1){
            return 1;
        }
        if(ind1==-1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
         
          int notPick=solveMemo(ind1-1,ind2,s,t,dp),pick=0;
         
        if(s[ind1]==t[ind2]){
             pick=solveMemo(ind1-1,ind2-1,s,t,dp); 
        }
         
         return dp[ind1][ind2]=pick+notPick;
    }
    int solveTabu(string s,string t){
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                  int notPick=dp[ind1-1][ind2],pick=0;
         
        if(s[ind1-1]==t[ind2-1]){
             pick=dp[ind1-1][ind2-1]; 
        }
         
          dp[ind1][ind2]=(pick+notPick)%1000000007;
            }
        }
        
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        // return solveRec(s.size()-1,t.size()-1,s,t);
        // vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        // return solveMemo(s.size()-1,t.size()-1,s,t,dp);
        return solveTabu(s,t);
    }
};