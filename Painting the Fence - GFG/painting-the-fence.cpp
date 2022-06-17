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
   long long add(long long a,long long b){
    return ((a%Mod) +(b%Mod))%Mod; 
}
long long mul(long long a,long long b){
    return ((a%Mod)*1ll*(b%Mod))%Mod;
}
    long long solveTabu(int n,int k){
//     vector<int>dp(n+1,-1);
//     dp[1]=k;
//     dp[2]=add(k,mul(k,k-1));
    
//     for(int i=3;i<=n;i++){
//         dp[i]=add(mul(dp[i-1],k-1),mul(dp[i-2],k-1));
//     }
//     return dp[n];
if(n==1) return k;
    long long prev2=k;
    long long prev1=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        long long ans=add(mul(prev1,k-1),mul(prev2,k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
    long long countWays(int n, int k){
        // code here4
        vector<long long>dp(n+1,-1);
        // return solve(n,k);
        // return solveMemo(n,k,dp);
        return solveTabu(n,k);
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