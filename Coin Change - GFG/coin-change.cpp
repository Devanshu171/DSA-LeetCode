// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  #define ll long long int
  ll solve(int x, int n,int arr[],vector<vector<ll>>& dp){
        if(x==0) return 1;
        if(x<0 || n<0) return 0;
        if(dp[x][n]!=-1) return dp[x][n];
        
     return dp[x][n]=  solve(x,n-1,arr,dp)+solve(x-arr[n],n,arr,dp);
    }
    long long int count(int arr[], int m, int amount) {

        // code here.
          vector<vector<ll>>dp(amount+1,vector<ll>(m,-1));
            return solve(amount,m-1,arr,dp);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends