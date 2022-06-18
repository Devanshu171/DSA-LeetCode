// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i,int j,vector<vector<int>>&grid){
    if(i<0 && j<0) return INT_MIN;
    if(i==0) return grid[i][j];
    
    int up=solve(i-1,j,grid);
    int topRight=solve(i-1,j+1,grid);
    int topLeft=solve(i-1,j-1,grid);
    
    return max(up,max(topRight,topLeft))+grid[i][j];
}
int solveMemo(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i<0 || j<0 || j==grid.size()) return INT_MIN;
    if(i==0) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solveMemo(i-1,j,grid,dp);
    int topRight=solveMemo(i-1,j+1,grid,dp);
    int topLeft=solveMemo(i-1,j-1,grid,dp);
    
    return dp[i][j]= max(up,max(topRight,topLeft))+grid[i][j];
}
    int maximumPath(int n, vector<vector<int>> grid)
    {
        // code here
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     ans=max(ans,solve(n-1,i,grid));
        // }
         for(int i=0;i<n;i++){
            ans=max(ans,solveMemo(n-1,i,grid,dp));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends