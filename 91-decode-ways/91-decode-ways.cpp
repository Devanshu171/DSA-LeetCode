class Solution {
public:
    int solveRec(int n,string s){
        if(n==s.size()) return 1;
        if(n>=s.size()) return 0;
        
        int single=0,pair=0;
        if(s[n]!='0') single=solveRec(n+1,s);
        string str=s.substr(n,2);
        if(str[0]!='0' && stoi(str)>=1 && stoi(str)<=26) pair=solveRec(n+2,s);
        
        return single+pair;
    }
     int solveMemo(int n,string s,vector<int>&dp){
        if(n==s.size()) return 1;
        if(n>=s.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        int single=0,pair=0;
        if(s[n]!='0') single=solveMemo(n+1,s,dp);
        string str=s.substr(n,2);
        if(str[0]!='0' && stoi(str)>=1 && stoi(str)<=26) pair=solveMemo(n+2,s,dp);
        
        return dp[n]= single+pair;
    }
    int numDecodings(string s) {
        
        // return solveRec(0,s);
        vector<int>dp(s.size(),-1);
        return solveMemo(0,s,dp);
    }
}; 