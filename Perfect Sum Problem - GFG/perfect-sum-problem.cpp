// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007
	int solveRec(int ind,int tar,vector<int>&arr){
    if(tar==0) return 1;
    if(ind==0) return arr[ind]==tar;
    
     int notTake=solveRec(ind-1,tar,arr);
    int take=0;
    if(arr[ind]<=tar) take=solveRec(ind-1,tar-arr[ind],arr);
    
    return (take+notTake)%mod;
}
int solveMemo(int ind,int tar,int arr[],vector<vector<int>>&dp){
   
    if(ind==0){
    if(tar==0 && arr[0]==0) return 2;
    else if(tar==0 || arr[0]==tar) return 1;
    else return 0;
    }
    
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    
     int notTake=solveMemo(ind-1,tar,arr,dp);
    int take=0;
    if(arr[ind]<=tar) take=solveMemo(ind-1,tar-arr[ind],arr,dp);
    
    return dp[ind][tar]=(take+notTake)%mod;
}

	int perfectSum(int arr[], int n, int sum)
	{
     
        //  int ans= solveRec(ar.size()-1,sum,ar);
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=solveMemo(n-1,sum,arr,dp);
  
         return ans;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends