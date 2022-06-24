// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
int solveRec(int ind,int tar,int nums[]){
    if(tar==0) return 0;
    if(ind==0){
        if(nums[0]<=tar && tar%nums[0]==0) return tar/nums[0];
        else return 1e8;
    }
    
    int notPick=solveRec(ind-1,tar,nums);
    int pick=1e8;
    if(tar>=nums[ind]) pick=1+solveRec(ind,tar-nums[ind],nums);
    
    return min(notPick,pick);
}
int solveMemo(int ind,int tar,int nums[],vector<vector<int>>&dp){
    if(tar==0) return 0;
    if(ind==0){
        if(nums[0]<=tar && tar%nums[0]==0) return tar/nums[0];
        else return 1e8;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notPick=solveMemo(ind-1,tar,nums,dp);
    int pick=1e8;
    if(tar>=nums[ind]) pick=1+solveMemo(ind,tar-nums[ind],nums,dp);
    
    return dp[ind][tar]= min(notPick,pick);
}
	int minCoins(int nums[], int M, int V) 
	{ 
	    // Your code goes here4
	   // int ans= solveRec(M-1,V,nums);
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int ans=solveMemo(M-1,V,nums,dp);
	    return ans==1e8?-1:ans;
  
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