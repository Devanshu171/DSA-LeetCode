// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int x,int nums[],int m,vector<int>&dp){
    
      if(x==0)  return 0;
       if(x<0) return INT_MAX;
    
    if(dp[x]!=-1) return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<m;i++){
        mini=min(mini,solve(x-nums[i],nums,m,dp));
    }
    
    return dp[x]= mini==INT_MAX?mini: 1+ mini;

}
	int minCoins(int nums[], int M, int V) 
	{ 
	    // Your code goes here4
	    vector<int>dp(V+1,-1);
    int ans=solve(V,nums,M,dp);
    return   ans==INT_MAX?-1:ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends