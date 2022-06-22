// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool solveRec(int ind,int target,vector<int>&arr){
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    
    bool notTake=solveRec(ind-1,target,arr);
    bool take=false;
        
        if(arr[ind]<=target)
        take=solveRec(ind-1,target-arr[ind],arr);
        
        return (notTake || take);
}
bool solveMemo(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    
    bool notTake=solveMemo(ind-1,target,arr,dp);
    bool take=false;
        
        if(arr[ind]<=target)
        take=solveMemo(ind-1,target-arr[ind],arr,dp);
        
        return dp[ind][target]= (notTake || take);
}
    bool isSubsetSum(vector<int>arr, int sum){
     
     vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
    //   return solveRec(arr.size()-1,sum,arr);
    return solveMemo(arr.size()-1,sum,arr,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends