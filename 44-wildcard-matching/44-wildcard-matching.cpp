class Solution {
public:
    bool solveRec(int ind1,int ind2,string s,string p){
        if(ind1==-1 && ind2==-1){
            return true;
        }

        if(ind1==-1 && ind2!=-1){
            while(ind2>=0 && p[ind2]=='*') ind2--;
            
            return ind2==-1;
        }
        if(ind1==-1 || ind2==-1) return false;
        
        else if(s[ind1]==p[ind2]) return solveRec(ind1-1,ind2-1,s,p);
       else if(p[ind2]=='?') return solveRec(ind1-1,ind2-1,s,p);
       else if(p[ind2]=='*'){
            for(int i=ind1+1;i>=0;i--){
                if(solveRec(i-1,ind2-1,s,p)) return true;
            }
        }
         return false;
    }
        int solveMemo(int ind1,int ind2,string s,string p,vector<vector<int>>&dp){
        if(ind1==-1 && ind2==-1){
            return true;
        }
        
           
        if(ind1==-1 && ind2!=-1){
            while(ind2>=0 && p[ind2]=='*') ind2--;
            
            return ind2==-1;
        }
        if(ind1==-1 || ind2==-1) return false;
         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        else if(s[ind1]==p[ind2] || p[ind2]=='?') return dp[ind1][ind2]= solveMemo(ind1-1,ind2-1,s,p,dp);
       
       else if(p[ind2]=='*'){
            return dp[ind1][ind2]= solveMemo(ind1-1,ind2,s,p,dp)| solveMemo(ind1,ind2-1,s,p,dp);
        }
         return dp[ind1][ind2] =false;
    }
    int solveTabu(string &s, string &p){
        int n=s.size(),m=p.size();
                vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i]=1;
                else break;
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
         if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?')  dp[ind1][ind2]= dp[ind1-1][ind2-1];
       
       else if(p[ind2-1]=='*'){
             dp[ind1][ind2]= dp[ind1-1][ind2] || dp[ind1][ind2-1];
        }
         else dp[ind1][ind2] =false;
            }
        }
        return dp[n][m];

    }
    
    bool isMatch(string s, string p) {
        // return solveRec(s.size()-1,p.size()-1,s,p);
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        // return solveMemo(s.size()-1,p.size()-1,s,p,dp);
        return solveTabu(s,p);
    }
};