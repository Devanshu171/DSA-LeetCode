class Solution {
public:
    bool isPalin(string s){
        int n=s.size();
        if(n==0) return false;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        
        return true;
    }
    
    int countPalin(int ind,string &s,vector<int>&dp){
        if(ind==s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int cnt=0;
        
        for(int i=ind;i<s.size();i++){
            cnt+=isPalin(s.substr(ind,i-ind+1));
        }

        return dp[ind]= cnt+ countPalin(ind+1,s,dp);
    }
    int countSubstrings(string s) {
       
        // vector<int>dp(s.size(),-1);
        //  return countPalin(0,s,dp);
    int ans=0;
        for(int i=0;i<s.size();i++){
            int l=i,h=i;
            while(l>=0 && h<s.size() && s[l--]==s[h++]) ans++;
            l=i,h=i+1;
            while(l>=0 && h<s.size() && s[l--]==s[h++]) ans++;
        }
        return ans;
        
     }
};