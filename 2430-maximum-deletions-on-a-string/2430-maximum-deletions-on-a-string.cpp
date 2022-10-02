class Solution {
public:
     vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int solve(string s,vector<int>&dp){
        if(s.size()==0) return 0;
        if(dp[s.size()]!=-1) return dp[s.size()];
        vector<int>lps=prefix_function(s);
                
        for(int i=1;i<s.size();i++){
               if(i%2 and lps[i]==(i+1)/2){
                   dp[s.size()]=max(dp[s.size()],1+solve(s.substr(lps[i]),dp));
               }
        }
        dp[s.size()]=dp[s.size()]==-1?1:dp[s.size()];
        return dp[s.size()];
        
    }
    int deleteString(string s) {
      vector<int>dp(s.size()+1,-1);
           return solve(s,dp);
    }
};