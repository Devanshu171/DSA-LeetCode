class Solution {
public:
      int solveRec(int ind1,int ind2,string s1,string s2){
        
        if(ind1<0 || ind2<0) return 0;
        
        if(s1[ind1]==s2[ind2]){
            return 1+solveRec(ind1-1,ind2-1,s1,s2);
        }else{
            return max(solveRec(ind1-1,ind2,s1,s2),solveRec(ind1,ind2-1,s1,s2));
        }
    }
    int solveMemo(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]){
            return  dp[ind1][ind2]=1+solveMemo(ind1-1,ind2-1,s1,s2,dp);
        }else{
            return dp[ind1][ind2]=max(solveMemo(ind1-1,ind2,s1,s2,dp),solveMemo(ind1,ind2-1,s1,s2,dp));
        }
    }
    int solveTabu(string s1,string s2){
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                
                   if(s1[ind1-1]==s2[ind2-1]){
              dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
               }else{
                      dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                     }
              }
        }
        return dp[n][m];
    }
      int solveTabuSo(string s1,string s2){
        int n=s1.size(),m=s2.size();
        vector<int>prev(m+1,0),cur(m+1,0);
  
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                
                   if(s1[ind1-1]==s2[ind2-1]){
              cur[ind2]=1+prev[ind2-1];
               }else{
                      cur[ind2]=max(prev[ind2],cur[ind2-1]);
                     }
              }
            prev=cur;
        }
        return prev[m];
    }
    int longestCommonSubsequence(string s1, string s2) {
            int n=s1.size(),m=s2.size();
        // return solveRec(n-1,m-1,s1,s2);
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solveMemo(n-1,m-1,s1,s2,dp);
        // return solveTabu(s1,s2);
        return solveTabuSo(s1,s2);
    }
};