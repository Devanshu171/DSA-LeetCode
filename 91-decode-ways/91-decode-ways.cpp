class Solution {
public:
    int solveRec(int n,string s){
        if(n==s.size()) return 1;
        if(n>s.size()) return 0;
        
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
    int solveTabu(string s){
        
        int n=s.size();
        vector<int>dp(n+1,0);
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
             dp[i]=dp[i+1];
        if(i<n-1 &&( s[i]=='1' || s[i]=='2' && s[i+1]<'7')) dp[i]+=dp[i+2];  
            }
        }
        
        return dp[0];
        
      
    }
    int solveTabuSo(string s){
        
        int n=s.size();
        int prev1=1,prev2;
     
        for(int i=n-1;i>=0;i--){
            int cur=0;
            if(s[i]=='0') cur=0;
            else{
             cur=prev1;
        if(i<n-1 &&( s[i]=='1' || s[i]=='2' && s[i+1]<'7')) cur+=prev2;
            }
             prev2=prev1;
                prev1=cur;
        }
        
        return prev1;
        
      
    }
    int numDecodings(string s) {
        
        // return solveRec(0,s);
        // vector<int>dp(s.size(),-1);
        // return solveMemo(0,s,dp);
        // return solveTabu(s);
        return solveTabuSo(s);
    }
}; 