// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	  int solveRec(int n){
            if(n==0) return 0;
        if(n<0) return 1e8;
        
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            ans=min(ans,solveRec(n-i*i)+1);
        }
        
        return ans;
    }
    int solveMemo(int n,vector<int>&dp){
            if(n==0) return 0;
        if(n<0) return 1e8;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            ans=min(ans,solveMemo(n-i*i,dp)+1);
        }
        
        return dp[n]=ans;
    }

	int MinSquares(int n)
	{
	    // Code here
	    vector<int>dp(n+1,-1);
        // return solveRec(n);
        return solveMemo(n,dp);
        
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends