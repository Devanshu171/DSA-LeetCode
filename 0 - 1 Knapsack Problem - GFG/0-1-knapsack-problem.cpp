// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solveRec(int w,int wt[],int val[],int ind){
        if((ind==0 && w<wt[0])|| w==0) return 0;
        else if(ind==0 && w>=wt[0]) return val[0];
        
        int notPick=solveRec(w,wt,val,ind-1);
        int pick=0;
        if(wt[ind]<=w) pick=solveRec(w-wt[ind],wt,val,ind-1)+val[ind]; 
        
        return max(pick,notPick);
    }
    int solveMemo(int w,int wt[],int val[],int ind,vector<vector<int>>&dp){
        if((ind==0 && w<wt[0])|| w==0) return 0;
        else if(ind==0 && w>=wt[0]) return val[0];
        if(dp[ind][w]!=-1) return dp[ind][w];
        int notPick=solveMemo(w,wt,val,ind-1,dp);
        int pick=0;
        if(wt[ind]<=w) pick=solveMemo(w-wt[ind],wt,val,ind-1,dp)+val[ind]; 
        
        return dp[ind][w]= max(pick,notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return solveRec(W,wt,val,n-1);
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    return solveMemo(W,wt,val,n-1,dp);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends