// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	const int m=1000000000+7;
	int solve(int n,vector<int>&dp){
	    if(dp[n]!=-1)return dp[n];
	    if(n==1 || n==0) return 1;
	    dp[n-1]=solve(n-1,dp);
	    dp[n-2]=solve(n-2,dp);
	    
	    return (dp[n-1]+dp[n-2])%m;
	}
		int nthPoint(int n){
		    vector<int>dp(n+1,-1);
		    return solve(n,dp);
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends