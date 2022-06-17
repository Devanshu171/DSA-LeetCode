// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int arr[],vector<int>&dp){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    if(dp[n]!=-1) return dp[n];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        maxi=max(maxi, solve(n-arr[i],arr,dp)+1); 
        }
        return dp[n]= maxi;
    }

    int solveTabu(int n,int arr[]){
        vector<int>dp(n+1,INT_MIN);
        dp[0]=0;
        for(int len=1;len<=n;len++){
            
            for(int i=0;i<3;i++){
                if(len>=arr[i] && dp[len-arr[i]]>=0){
                    dp[len]=max(dp[len],dp[len-arr[i]]+1);
                }
            }
        }
        
        return dp[n]<0?0:dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int arr[3]={x,y,z};
        return solveTabu(n,arr);
    // vector<int>dp(n+1,-1);
    // int ans= solve(n,arr,dp);
    // return ans<0?0:ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends