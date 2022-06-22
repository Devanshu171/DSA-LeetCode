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
bool solveTabu(vector<int>arr, int sum){
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    
    // 1st base case
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    // 2nd base case (from recursion)
    if(arr[0]<=sum) dp[0][arr[0]]=true;
    
    // nested loops for state chaning variables,
    // opposite of recursion i.e top down ->bottom up
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=sum;target++){
               
         bool notTake=dp[i-1][target];
         bool take=false;
        
             if(arr[i]<=target)
         take=dp[i-1][target-arr[i]];
        
         dp[i][target]= (notTake || take);
            
        }
    }
    
    return dp[n-1][sum];
}
bool solveTabuSo(vector<int>arr, int sum){
    int n=arr.size();
    vector<bool>cur(sum+1,false),prev(sum+1,false);
    
    // 1st base case
   prev[0]=cur[0]=true;
    if(arr[0]<=sum) prev[arr[0]]=cur[arr[0]]=true;
   
    // nested loops for state chaning variables,
    // opposite of recursion i.e top down ->bottom up
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=sum;target++){
               
         bool notTake=prev[target];
         bool take=false;
        
             if(arr[i]<=target)
         take=prev[target-arr[i]];
        
         cur[target]= (notTake || take);
            
        }
        prev=cur;
    }
    
    return prev[sum];
}
    bool isSubsetSum(vector<int>arr, int sum){
     
     vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
    //   return solveRec(arr.size()-1,sum,arr);
    // return solveMemo(arr.size()-1,sum,arr,dp);
    // return solveTabu(arr,sum);
    return solveTabuSo(arr,sum);
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