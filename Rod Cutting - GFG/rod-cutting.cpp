// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[],int len,int n, vector<vector<int>>&dp){
      if(len==0) return 0;
      if(len<0 || n<=0) return INT_MIN;
      if(dp[n][len]!=-1) return dp[n][len];
      
      return dp[n][len]= max(solve(price,len,n-1,dp),solve(price,len-n,n,dp)+price[n-1]);
    
  }
  
//   return dp[n]=m/axi;
//   }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,n,dp);
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