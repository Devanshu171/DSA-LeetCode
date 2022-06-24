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
int solveTabu(int nums[], int M, int V){
    vector<vector<int>>dp(M,vector<int>(V+1,1e8));
    for(int i=0;i<M;i++) dp[i][0]=0;
    for(int i=nums[0];i<=V;i++){
        if(i%nums[0]==0) dp[0][i]=i/nums[0];
    }
    
    for(int ind=1;ind<M;ind++){
        for(int tar=1;tar<=V;tar++){
             int notPick=dp[ind-1][tar];
                 int pick=1e8;
                if(tar>=nums[ind]) pick=1+dp[ind][tar-nums[ind]];
    
             dp[ind][tar]=min(notPick,pick);
        }
    }
    
    return dp[M-1][V];
}
int solveTabuSo(int nums[], int M, int V){
  vector<int>prev(V+1,1e8),cur(V+1,1e8);
    prev[0]=0,cur[0]=0;
    for(int i=nums[0];i<=V;i++){
        if(i%nums[0]==0) prev[i]=i/nums[0];
    }
    
    for(int ind=1;ind<M;ind++){
        for(int tar=1;tar<=V;tar++){
             int notPick=prev[tar];
                 int pick=1e8;
                if(tar>=nums[ind]) pick=1+cur[tar-nums[ind]];
    
             cur[tar]=min(notPick,pick);
        }
        prev=cur;
    }
    
    return prev[V];
}
	int minCoins(int nums[], int M, int V) 
	{ 
	    // Your code goes here4
	   // int ans= solveRec(M-1,V,nums);
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	   // int ans=solveMemo(M-1,V,nums,dp);
	   //int ans=solveTabu(nums,M,V);
	   int ans=solveTabuSo(nums,M,V);
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