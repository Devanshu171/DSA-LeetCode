// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int solveRec(int i,vector<int>& nums, int target){
        if(i==nums.size()){
            if(target==0)
            return 1;
            else 
            return 0;
        }
        
        int pos=solveRec(i+1,nums,target-nums[i]);
        int neg=solveRec(i+1,nums,target-(-nums[i]));
        
        return pos+neg;
    }
    int solveMemo(int i,vector<int>& nums, int target,map<pair<int,int>,int>&dp){
        if(i==nums.size()){
            if(target==0)
            return 1;
            else 
            return 0;
        }
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        int pos=solveMemo(i+1,nums,target-nums[i],dp);
        int neg=solveMemo(i+1,nums,target-(-nums[i]),dp);
        
        return dp[{i,target}]=pos+neg;
    }
        
    int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int,int>,int>dp;
        // return solve(0,nums,target);
        return solveMemo(0,nums,target,dp);
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends