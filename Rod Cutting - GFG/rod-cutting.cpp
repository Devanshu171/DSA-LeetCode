// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solveRec(int ind,int len,int price[],int n){
      if(len==n) return 0;
      if(ind>n) return 0;
      
      
      int notPick=solveRec(ind+1,len,price,n);
      int pick=0;
      if(len+ind<=n) pick=solveRec(ind,len+ind,price,n)+price[ind-1];
      
      return max(pick,notPick);
  }
  int solveMemo(int ind,int len,int price[],int n,vector<vector<int>>&dp){
      if(len==n) return 0;
      if(ind>n) return 0;
      
      if(dp[ind][len]!=-1) return dp[ind][len];
      
      int notPick=solveMemo(ind+1,len,price,n,dp);
      int pick=0;
      if(len+ind<=n) pick=solveMemo(ind,len+ind,price,n,dp)+price[ind-1];
      
      return dp[ind][len]= max(pick,notPick);
  }
    int cutRod(int price[], int n) {
        //code here
        // return solveRec(1,0,price,n);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(1,0,price,n,dp);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends