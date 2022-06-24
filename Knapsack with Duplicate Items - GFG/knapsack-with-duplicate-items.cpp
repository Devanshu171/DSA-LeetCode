// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solveRec(int ind,int w,int val[],int wt[]){
        if(ind==0){
            if(w>=wt[0])  (w/wt[0])*val[0];
            else return 0;
        }
        
        int notPick=solveRec(ind-1,w,val,wt);
        int pick=0;
        if(w>=wt[ind]) pick=val[ind]+solveRec(ind,w-wt[ind],val,wt);
        
        return max(pick,notPick);
    }
    int solveMemo(int ind,int w,int val[],int wt[],vector<vector<int>>&dp){
        if(ind==0){
            if(w>=wt[0]) return (w/wt[0])*val[0];
            else return 0;
        }
        
        if(dp[ind][w]!=-1) return dp[ind][w];
        int notPick=solveMemo(ind-1,w,val,wt,dp);
        int pick=0;
        if(w>=wt[ind]) pick=val[ind]+solveMemo(ind,w-wt[ind],val,wt,dp);
        
        return dp[ind][w]=max(pick,notPick);
    }
    int solveTabu(int n,int W,int val[],int wt[]){
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++) 
        dp[0][i]=(i/wt[0])*val[0];
        
        for(int ind=1;ind<n;ind++){
            for(int w=1;w<=W;w++){
                  int notPick=dp[ind-1][w];
                    int pick=0;
                    if(w>=wt[ind]) pick=val[ind]+dp[ind][w-wt[ind]];
                    
                     dp[ind][w]=max(pick,notPick);
            }
        }
        
        return dp[n-1][W];
    }
    int solveTabuSo(int n,int W,int val[],int wt[]){
        vector<int>prev(W+1,0),cur(W+1,0);
        for(int i=wt[0];i<=W;i++) 
        prev[i]=(i/wt[0])*val[0];
        
        for(int ind=1;ind<n;ind++){
            for(int w=1;w<=W;w++){
                  int notPick=prev[w];
                    int pick=0;
                    if(w>=wt[ind]) pick=val[ind]+cur[w-wt[ind]];
                    
                     cur[w]=max(pick,notPick);
            }
            prev=cur;
        }
        
        return prev[W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // return solveRec(N-1,W,val,wt);
        // vector<vector<int>>dp(N,vector<int>(W+1,-1));
        // return solveMemo(N-1,W,val,wt,dp);
        // return solveTabu(N,W,val,wt);
        return solveTabuSo(N,W,val,wt);

        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends