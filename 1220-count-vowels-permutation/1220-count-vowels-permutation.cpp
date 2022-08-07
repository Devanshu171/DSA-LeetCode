class Solution {
public:
    #define mod  1000000007
    int solve(char ch,int n){
        if(n==0) return 1;
        
        if(ch=='a'){
            return solve('e',n-1);
        }else if(ch=='e'){
            return (solve('a',n-1)+solve('i',n-1))%mod;
        }else if(ch=='i'){
            int ans=0;
            
            return (((solve('a',n-1)%mod+solve('e',n-1))%mod+solve('o',n-1))%mod+solve('u',n-1))%mod;
            
            
        }else if(ch=='o'){
            return solve('i',n-1)+solve('u',n-1);
        }else{
            return solve('a',n-1);
            
        }
    }
       int solveMemo(char ch,int n,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(dp[n][ch-'a']!=-1) return dp[n][ch-'a'];
        if(ch=='a'){
            return dp[n][ch-'a']=solveMemo('e',n-1,dp);
        }else if(ch=='e'){
            return dp[n][ch-'a']=(solveMemo('a',n-1,dp)+solveMemo('i',n-1,dp))%mod;
        }else if(ch=='i'){
            int ans=0;
            
            return dp[n][ch-'a']=(((solveMemo('a',n-1,dp)%mod+solveMemo('e',n-1,dp))%mod+solveMemo('o',n-1,dp))%mod+solveMemo('u',n-1,dp))%mod;
            
            
        }else if(ch=='o'){
            return dp[n][ch-'a']=(solveMemo('i',n-1,dp)+solveMemo('u',n-1,dp))%mod;
        }else{
            return dp[n][ch-'a']=solveMemo('a',n-1,dp);
            
        }
    }
    int countVowelPermutation(int n) {
        
        int ans=0;
        vector<char>vec={'a', 'e', 'i', 'o', 'u'};
        // for(int i=0;i<5;i++){
        //     ans=(ans+solve(vec[i],n-1))%mod;
        // }
        vector<vector<int>>dp(n+1,vector<int>(26,-1));
          for(int i=0;i<5;i++){
            ans=(ans+solveMemo(vec[i],n-1,dp))%mod;
        }
        return ans;
    }
};