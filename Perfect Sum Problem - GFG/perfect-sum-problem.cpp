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
int solveMemo(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp){
    if(tar==0) return 1;
    if(ind==0) return arr[ind]==tar;
    
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    
     int notTake=solveMemo(ind-1,tar,arr,dp);
    int take=0;
    if(arr[ind]<=tar) take=solveMemo(ind-1,tar-arr[ind],arr,dp);
    
    return dp[ind][tar]=(take+notTake)%mod;
}

	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int>ar;
         int zeros=0;
        for(int i=0;i<n;i++) {
            if(arr[i]!=0)
            ar.push_back(arr[i]);
            else
              zeros++;
            
        }

        //  int ans= solveRec(ar.size()-1,sum,ar);
        vector<vector<int>>dp(ar.size(),vector<int>(sum+1,-1));
        int ans=solveMemo(ar.size()-1,sum,ar,dp);
         ans*=pow(2,zeros);
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