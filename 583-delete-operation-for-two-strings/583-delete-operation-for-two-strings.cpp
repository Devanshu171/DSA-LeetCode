class Solution {
public:
   
    // int solveMemo(string w1,string w2,int i,int j,vector<vector<int>>&dp){
    //     while( j>=0 && i>=0 && w1[i]==w2[j]){
    //         i--;j--;
    //     }
    //     if(i<0 || j<0){
    //         return max(i+1 ,j+1);
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=min(solveMemo(w1,w2,i-1,j,dp),solveMemo(w1,w2,i,j-1,dp));
    //     return dp[i][j]=ans+1;
    // }
    // int minDistance(string w1, string w2) {
    //     vector<vector<int>>dp(w1.size(),vector<int>(w2.size(),-1));
    //     // return solve(w1,w2,0,0);
    //     return solveMemo(w1,w2,w1.size()-1,w2.size()-1,dp);
    // }
    
    int solve(string w1,string w2,int i,int j){
        while( j<w2.size() && i<w1.size() && w1[i]==w2[j]){
            i++;j++;
        }
        if(i==w1.size() || j==w2.size()){
            return max(w1.size()-i ,w2.size()-j);
        }
        int ans=min(solve(w1,w2,i+1,j),solve(w1,w2,i,j+1));
        return ans+1;
    }
    int solveMemo(string w1,string w2,int i,int j,vector<vector<int>>&dp){
        while( j<w2.size() && i<w1.size() && w1[i]==w2[j]){
            i++;j++;
        }
        if(i==w1.size() || j==w2.size()){
            return max(w1.size()-i ,w2.size()-j);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=min(solveMemo(w1,w2,i+1,j,dp),solveMemo(w1,w2,i,j+1,dp));
        return dp[i][j]=ans+1;
    }
    int minDistance(string w1, string w2) {
        vector<vector<int>>dp(w1.size(),vector<int>(w2.size(),-1));
        return solveMemo(w1,w2,0,0,dp);
    }
};