class Solution {
public:
    int solveRec(int ind,int prev,vector<int>&nums){
        if(ind==0) return nums[ind]<prev;
        
        if(nums[ind]>=prev) return solveRec(ind-1,prev,nums);
        int pick=solveRec(ind-1,nums[ind],nums)+1;
        int notPick=solveRec(ind-1,prev,nums);
        
        return max(pick,notPick);
    }
    int solveMemo(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0) return nums[ind]<nums[prev];
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        
        if(nums[ind]>=nums[prev]) return  dp[ind][prev]=solveMemo(ind-1,prev,nums,dp);
        int pick=solveMemo(ind-1,ind,nums,dp)+1;
        int notPick=solveMemo(ind-1,prev,nums,dp);
        
        return  dp[ind][prev]=max(pick,notPick);
    }
    int solveTabu(vector<int>&nums){
        nums.push_back(1e9);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=1;i<n;i++){
            if(nums[0]<nums[i]) dp[0][i]=1;
        }
            
        for(int ind=1;ind<n-1;ind++){
            for(int prev=1;prev<n;prev++){
              if(ind==prev) continue;    
        if(nums[ind]>=nums[prev])   dp[ind][prev]=dp[ind-1][prev];
                else{
                    int pick=dp[ind-1][ind]+1;
                    int notPick=dp[ind-1][prev];

                      dp[ind][prev]=max(pick,notPick);
                }
            }
        }
        return dp[n-2][n-1];
    }
     int solveTabuSo(vector<int>&nums){
        nums.push_back(1e9);
        int n=nums.size();
        vector<int>prevv(n,0),cur(n,0);
        
        for(int i=1;i<n;i++){
            if(nums[0]<nums[i]) prevv[i]=1;
        }
            
        for(int ind=1;ind<n-1;ind++){
            for(int prev=1;prev<n;prev++){
              if(ind==prev) continue;    
        if(nums[ind]>=nums[prev])   cur[prev]=prevv[prev];
                else{
                    int pick=prevv[ind]+1;
                    int notPick=prevv[prev];

                      cur[prev]=max(pick,notPick);
                }
            }
            swap(cur,prevv);
        }
        return prevv[n-1];
    }
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(1e9);
        int n=nums.size();
        // return solveRec(n-1,1e9,nums);
        
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solveMemo(n-2,n-1,nums,dp);
        // return solveTabu(nums);
        return solveTabuSo(nums);
    }
};