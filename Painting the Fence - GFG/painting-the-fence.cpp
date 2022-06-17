// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    #define Mod 1000000007
    long long solve(int n,int k){
        if(n==2) return k+k*(k-1);
        if(n==1) return k;
        
        long long ii=solve(n-2,k)*(k-1);
        long long ij=solve(n-1,k)*(k-1);
        long long ans=(ii+ij)%Mod;
        return ans;
    }
    long long solveMemo(int n,int k,vector<long long>&dp){
        if(n==2) return (k%Mod+ ((k%Mod)*1ll*(k-1)%Mod)%Mod)%Mod;
        if(n==1) return k%Mod;
        if(dp[n]!=-1) return dp[n];

        long long ii= ((solveMemo(n-2,k,dp)%Mod)*1ll*((k-1)%Mod))%Mod;
        long long ij=((solveMemo(n-1,k,dp)%Mod)*1ll*((k-1)%Mod))%Mod;
        long long ans=((ii%Mod)+(ij%Mod))%Mod;
        return dp[n]= ans;
    }
    long long countWays(int n, int k){
        // code here4
        vector<long long>dp(n+1,-1);
        // return solve(n,k);
        return solveMemo(n,k,dp);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends