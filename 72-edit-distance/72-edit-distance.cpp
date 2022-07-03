class Solution {
public:
    int solveRec(int ind1,int ind2,string s1,string s2){
        if(ind2==-1) return ind1+1;
        if(ind1==-1) return ind2+1;
        
        if(s1[ind1]==s2[ind2]){
            return solveRec(ind1-1,ind2-1,s1,s2);
        }else{
            int remove=solveRec(ind1-1,ind2,s1,s2)+1;
              int insert=solveRec(ind1,ind2-1,s1,s2)+1;
            int replace=solveRec(ind1-1,ind2-1,s1,s2)+1;
            
            return min(remove,min(replace,insert));
        }
    }
    int solveMemo(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind2==-1) return ind1+1;
        if(ind1==-1) return ind2+1;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]= solveMemo(ind1-1,ind2-1,s1,s2,dp);
        }else{
            int remove=solveMemo(ind1-1,ind2,s1,s2,dp)+1;
              int insert=solveMemo(ind1,ind2-1,s1,s2,dp)+1;
            int replace=solveMemo(ind1-1,ind2-1,s1,s2,dp)+1;
            
            return dp[ind1][ind2]= min(remove,min(replace,insert));
        }
    }
  int solveTabu(string &s1, string &s2){
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=m;i++)
            dp[0][i]=i;
 
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                
                if(s1[ind1-1]==s2[ind2-1]){
             dp[ind1][ind2]= dp[ind1-1][ind2-1];
                    
                }else{
                    int remove=dp[ind1-1][ind2]+1;
                    int insert=dp[ind1][ind2-1]+1;
                    int replace=dp[ind1-1][ind2-1]+1;
            
                dp[ind1][ind2]= min(remove,min(replace,insert));
                }
            }
        }
        
        return dp[n][m];
           
    }
     int solveTabuSo(string &s1, string &s2){
        int n=s1.size(),m=s2.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        
        for(int i=0;i<=m;i++)
            prev[i]=i;
           
        
        for(int ind1=1;ind1<=n;ind1++){
            cur[0]=ind1;
            for(int ind2=1;ind2<=m;ind2++){
                
                if(s1[ind1-1]==s2[ind2-1]){
             cur[ind2]= prev[ind2-1];
                    
                }else{
                    int remove=prev[ind2]+1;
                    int insert=cur[ind2-1]+1;
                    int replace=prev[ind2-1]+1;
            
                cur[ind2]= min(remove,min(replace,insert));
                }
            }
            prev=cur;
        }
        
        return prev[m];
           
    }
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        // return solveRec(s1.size()-1,s2.size()-1,s1,s2);
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solveMemo(n-1,m-1,s1,s2,dp);
        // return solveTabu(s1,s2);
        return solveTabuSo(s1,s2);
    }
};