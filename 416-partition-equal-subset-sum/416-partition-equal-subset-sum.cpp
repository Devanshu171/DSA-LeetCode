class Solution {
public:
    bool solveRec(int ind,int target,vector<int>&arr){
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    
    bool notTake=solveRec(ind-1,target,arr);
    bool take=false;
    if(arr[ind]<=target) take=solveRec(ind-1,target-arr[ind],arr);
    
    return (take||notTake);
}
bool solveMemo(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake=solveMemo(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target) take=solveMemo(ind-1,target-arr[ind],arr,dp);
    
    return dp[ind][target]= (take||notTake);
}

    bool canPartition(vector<int>& arr) {
            int sum=0,n=arr.size();
    for(auto it:arr) sum+=it;
    if(sum%2!=0) return false;
        
//     return solveRec(n-1,sum/2,arr);
    vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
    return solveMemo(n-1,sum/2,arr,dp);
    }
};